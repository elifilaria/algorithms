#include<iostream>

#include<fstream>

#include<vector>

#include<map>

using namespace std;

#include"elapsed_time.h"



struct Dictionary {

  map<string, vector<string>> hashmap;

  vector<string> wordArray;

  Dictionary(const char *filename);  // constructor



  bool inWordArray(string &s);       // single query

  void check(const char *filename);  // multiple queries

};



void getWords( const char *filename, map<string, vector<string>> &mymap )

{

  ifstream f(filename);

  if ( ! f.good() ) {

    cerr << "Error:  unable to open " << filename << endl;

    exit(-1);

  }

  string s, head;//head is 2char prefix

  while ( f >> s )

    {

      head=s.substr(0,2);

      //head[0]=tolower(head[0]);

      mymap[head].push_back(s);

      //cout << head << endl;

    }

  

}



Dictionary::Dictionary( const char *filename )

{
  getWords(filename, hashmap);


}



bool Dictionary::inWordArray(string &s)

{

  int n = wordArray.size();

  for ( int i = 0; i < n; ++i )

    if ( s == wordArray[i] ) return true;

  return false;

}



void Dictionary::check( const char *filename )

{

  map<string, vector<string>> query;

  getWords(filename, query);



  start_timer();  // from elapsed_time.h



  int counter=0;

  string head;

  vector<string> wordArray, dictArray;

  for (std::map<string,vector<string>>::iterator it=query.begin(); it!=query.end(); ++it)

    {

      head = it->first;

      wordArray=it->second;

      //std::cout << it->first  << '\n';

      dictArray=hashmap[head];

      for (std::vector<string>::iterator word = wordArray.begin(); word!=wordArray.end(); ++word)

{

  bool found = false;

  for (std::vector<string>::iterator dictword = dictArray.begin(); dictword!=dictArray.end(); ++dictword)

    if ((*word).compare(*dictword)==0)

      {

found = true;

break;

      }

  if (!found) counter++;

}

    }

  cout << "Misspelled " << counter << " words." << endl;



  double cycles = elapsed_time();

  cout << " Total cycles: " << cycles << endl;
  int emptyEntries = 0;
  int oneWordEntries = 0;
  int twoWordEntries = 0;
  int fiveWordEntries = 0;
  int overTenEntries = 0;
  int overTwentyEntries = 0;
  for (unsigned int i = 0; i < dictArray.size(); i++) {
    if (dictArray[i].size() == 0) {++emptyEntries;}
    if (dictArray[i].size() == 1) {++oneWordEntries;}
    if (dictArray[i].size() == 2) {++twoWordEntries;}
    if (dictArray[i].size() == 5) {++fiveWordEntries;}
    if (dictArray[i].size() > 10) {++overTenEntries;}
    if (dictArray[i].size() > 20) {++overTwentyEntries;}
}
  cout << "Empty entries in the hash table \t" << emptyEntries << endl;
  cout << "One word entries in the hash table \t" << oneWordEntries << endl;
  cout << "Two word entries in the has table \t" << twoWordEntries << endl;
  cout << "Five word entries in the hash table \t" << fiveWordEntries << endl;
  cout << "Over ten word entries in the hash table \t" << overTenEntries << endl;
  cout << "Over twenty word entries in the hash table \t" << overTwentyEntries << endl;
  
}



int main(int argc, char **argv)

{

  if ( argc != 3 ) {

    cerr << "Usage: spellCheck dictionaryFile inputFile" << endl;

    exit(0);

  }

  Dictionary d(argv[1]);

  d.check(argv[2]);

}
