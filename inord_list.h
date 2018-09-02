/*
 * inord_list.h
 *
 *  Created on: Mar 19, 2017
 *      Author: mina
 */

#include <iostream>
#include <fstream>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <sstream>
#include <stdlib.h>
#include <typeinfo>

using namespace std;

#ifndef INORD_LIST_H_
#define INORD_LIST_H_




class inord_list
{


public:


    struct lsNode
    {
    	int line;
    	int count;
    	string word;
    	lsNode *next;
    };

    lsNode *head;
    lsNode *tail;

	inord_list();
	virtual ~inord_list();

	lsNode*  initNode(string val, int line);
	void addNode(lsNode *newnode );
	void insertNode(lsNode *ptr);
	void displayNode(lsNode *ptr);
	void displayList(  );
	inord_list::lsNode* searchName(lsNode *ptr, string  name );
	int countDistWord( );
	int countWord(char *str);
	int countWords();
	string displayDistWords( );
	string  displayGreatestWord( );
	string displayStart(string  str );
	string displayContain(string  str );
	string listSearch(string  str );
	void deleteLinkedList();
	int greatestNumber( );
	int countAWord(string  str);


	std::fstream outFile;
};

#endif /* INORD_LIST_H_ */
