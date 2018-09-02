//============================================================================
// Name        : a2.cpp
// Author      : mina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <sstream>
#include <stdlib.h>
#include <typeinfo>
#include "inord_list.h"
using namespace std;

int iCharCount;
int iLineNum;
int iWordCount;
inord_list list;



string getParam(string str)
{
	int i= 0;
	string s1;

	while(str[i])
	{
		s1 = s1 + char(tolower(str[i]));
		i++;
	}

	return s1;

}

void getChars(char *pFile)
{
	ifstream inFile;

	inFile.open (pFile);

	while(inFile.good())
	{
		inFile.get();
		iCharCount++;
	}

	inFile.close();

}

int ReadFile(char *pFile)
{

	string word;
    string line;
    ifstream inFile;


    word.clear();
    line.clear();


    //fstream outFile;    outFile.open ("test.txt");


    inFile.open (pFile);

    if (!inFile.is_open()) return 0;


    while (getline(inFile,line))
    {

    	iLineNum++;
    	istringstream stm(line);

    	while(stm >> word)
    	{
    		list.insertNode(list.initNode(getParam(word),iLineNum));

    	}

		list.displayList();

    }

    inFile.close();

    return 0;

}


int ProcessCmd(char *pFile)
{
	string word,word2;
	string cmdLine;
	ifstream cmdFile;

	cmdFile.open (pFile);

    if (!cmdFile.is_open()) return 0;

    while (getline(cmdFile,cmdLine))
    {
    	istringstream stm(cmdLine);

		stm >> word;
		stm >> word2;


		if ( (word2.length() == 0 ) and (word.compare("countWord") == 0 or word.compare("containing") == 0 or word.compare("starting") == 0 or word.compare("search") == 0 ) )
		{
			cout << "Incorrect number of arguments" << endl;
			continue; //break; //return -2;
		}

		if ( word.compare("charCount") == 0)
			cout  << iCharCount-1  << " characters" << endl;
		else if( word.compare("distWords") == 0)
			cout  << list.countDistWord() << " distinct words" << endl;
		else if( word.compare("wordCount") == 0)
			cout  << list.countWords() << " words" << endl;
		else if( word.compare("frequentWord") == 0)
			cout  << "Most frequent word is: "  << list.displayGreatestWord() << endl;
		else if( word.compare("countWord") == 0 )
			cout  << word2 <<  " is repeated " << list.countAWord(getParam(word2)) << " times" << endl;
		else if( word.compare("containing") == 0 )
			cout  << list.displayContain(getParam(word2)) << endl;
		else if( word.compare("starting") == 0 )
			cout  << list.displayStart(getParam(word2)) << "\n";
		else if( word.compare("search") == 0 )
			cout  << list.listSearch(getParam(word2));// << endl;
		else
		{
			cout << "Undefined command" << "\n";
			continue; //break; //return -1;
		}

		word  = "";
		word2 = "" ;

    }

	return 0;
}


int main(int argc,char *argv[])
{

	iCharCount = 0;
	iWordCount = 0;
	iLineNum = 0;

	getChars(argv[1]);

	ReadFile(argv[1]);

	ProcessCmd(argv[2]);

	return 0;
}
