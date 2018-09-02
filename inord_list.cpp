/*
 * inord_list.cpp
 *
 *  Created on: Mar 19, 2017
 *      Author: mina
 */

#include "inord_list.h"

inord_list::inord_list()
{
	head = NULL;
	tail = NULL;

	outFile.open ("test.txt");
}

inord_list::~inord_list()
{
	deleteLinkedList();

}

inord_list::lsNode* inord_list::initNode(string val, int line)
{

	lsNode *ptr = new lsNode;

	// error? then just return
	if( ptr == NULL )
		return NULL;
	else
	{
		ptr->word = val;
		ptr->line = line;
		ptr->count = 1;
		ptr->next = NULL;
		return ptr;
	}

}

void inord_list::insertNode(lsNode *newnode)
{
	   lsNode *temp, *prev;

	   if( head == NULL )
	   {                     // if an empty list,
	       head = newnode;                      // set 'head' to it
	       tail = newnode;
	       head->next = NULL;                   // set end of list to NULL
	       return;
	   }

	   temp = head;                             // start at beginning of list
						    // while currentname < newname
	   while( newnode->word.compare(temp->word) >= 0 )
	   {
		   if( newnode->word.compare(temp->word) == 0 )
			   temp->count++;
						    // to be inserted then
	          temp = temp->next;                // goto the next node in list
	          if( temp == NULL )                // don't go past end of list
	              break;
	   }
						    // set previous node before we insert
						    // first check to see if it's inserting
	   if( temp == head )
	   {		    	    // before the first node
	      newnode->next = head;                 // link next field to original list
	      head = newnode;                       // head adjusted to new node
	   }
	   else
	   {				    // it's not the first node
	      prev = head;			    // start of the list,
	      while( prev->next != temp )
	      {	    // will cycle to node before temp
	          prev = prev->next;
	      }
	      prev->next = newnode;		    // insert node between prev and next
	      newnode->next = temp;
	      if( tail == prev )		    // if the new node is inserted at the
	         tail = newnode;		    // end of the list the adjust 'end'
	   }
}


void inord_list::deleteLinkedList()
{
	lsNode *tmpNode;
	while(head)
	{
		tmpNode = head;
		head = tmpNode->next;
		delete tmpNode;
	}
}


// Functions

int inord_list::countWords( )
{
	int i = 0;
	lsNode *ptr = head;

	while( ptr != NULL and ptr->next != NULL)
	{
		i++;
		ptr = ptr->next;
	}

	i++;

	return i;
}

int inord_list::countDistWord( )
{
	int i = 0;
	lsNode *ptr = head;

	while( ptr != NULL and ptr->next != NULL)
	{
		if( ptr->word.compare(ptr->next->word) != 0 ) i++;
		ptr = ptr->next;
	}

	i++;

	return i;
}


int inord_list::countAWord(string str)
{
	int i = 0;
	lsNode *ptr = head;

	while( ptr != NULL)
	{
		if( ptr->word.compare(str) == 0 )
		{
			return ptr->count;
		}

		ptr = ptr->next;

	}

	return i;
}

int inord_list::greatestNumber( )
{
	int i = 0;
	lsNode *ptr = head;

	while( ptr != NULL and ptr->next != NULL)
	{
		if (ptr->word != "a" and ptr->word != "an" and ptr->word != "the"
				and ptr->word != "in" and ptr->word != "on" and ptr->word != "of"
						and ptr->word != "and" and ptr->word != "is" and ptr->word != "are")
		{
			if( ptr->count > ptr->next->count and ptr->count > i)
				i = ptr->count;

		}

		ptr = ptr->next;
	}

	return i;
}

string  inord_list::displayGreatestWord( )
{
	lsNode *ptr = head;

	string line;
	int ii = greatestNumber( );

	while( ptr != NULL )
	{

		if (	ptr->count ==  ii
				and ptr->word != "a" and ptr->word != "an" and ptr->word != "the"
				and ptr->word != "in" and ptr->word != "on" and ptr->word != "of"
				and ptr->word != "and" and ptr->word != "is" and ptr->word != "are")
		{
			line = line + ptr->word;
			line = line + " ";
		}

		ptr = ptr->next;
	}

	return line;
}

string inord_list::displayContain(string  str )
{
	stringstream ss;
	string line;
	lsNode *ptr = head;

	while( ptr != NULL and ptr->next != NULL)
	{

		if( ptr->word.find(str) != string::npos )
		{

			line = line + ptr->word;
			line = line + ": ";
			ss << ptr->count;
			line = line + ss.str();
			line = line + "\t";
			ss.str("");

			while( ptr->next != NULL and ptr->word.compare(ptr->next->word) == 0)
				ptr = ptr->next;

		}

		ptr = ptr->next;
	}

	return line;
}

string inord_list::displayStart(string  str )
{
	stringstream ss;
	string line;
	lsNode *ptr = head;

	while( ptr != NULL and ptr->next != NULL)
	{

		if( ptr->word.find(str) != string::npos and ptr->word.find_first_of(str,0) == 0)
		{

			line = line + ptr->word;
			line = line + ": ";
			ss << ptr->count;
			line = line + ss.str();
			line = line + "\t";
			ss.str("");

			while( ptr->next != NULL and ptr->word.compare(ptr->next->word) == 0)
				ptr = ptr->next;

		}

		ptr = ptr->next;
	}

	return line;
}

string inord_list::listSearch(string  str )
{
	stringstream ss;
	string line = "";
	lsNode *ptr = head;

	while( ptr != NULL and ptr->next != NULL)
	{

		if( ptr->word.find(str) != string::npos )
		{

			line = line + ptr->word;
			line = line + ":";
			line = line + "\t";
			line = line + "lines ";
			ss << ptr->line;
			ss << " ";
			//line = line + ss.str();
			//line = line + " \n";


			while( ptr->next != NULL and ptr->word.compare(ptr->next->word) == 0)
			{
				ptr = ptr->next;
				ss << ptr->line;
				ss << " ";
				//line = line + " ";

			}

			line = line + ss.str();
			line = line + "\n";
			ss.str("");

		}

		ptr = ptr->next;
	}


	return line;

}

// Display Functions

void inord_list::displayList( )
{
	lsNode *ptr = head;

	while( ptr != NULL )
	{
		displayNode( ptr );
		ptr = ptr->next;
	}

}


void inord_list::displayNode(lsNode *ptr )
{
    outFile << ptr->line  << ": " << ptr->word << " " << ptr->count << endl;
}


// Test Functions

string inord_list::displayDistWords( )
{
	int i = 0;
	string str = "";
	lsNode *ptr = head;

	while( ptr != NULL and ptr->next != NULL)
	{
		if( ptr->word.compare(ptr->next->word) == 0 )
		{
			while( ptr->next != NULL and ptr->word.compare(ptr->next->word) == 0)
			{
				ptr = ptr->next;
			}

			str = str + ptr->word;

			//outFile << ptr->word << ptr->line << "....."<< endl;

		}

		ptr = ptr->next;
	}

}




void inord_list::addNode(lsNode *newnode )
{
	// if there is no node, put it to head
	if( head == NULL )
	{
       head = newnode;
       tail = newnode;
	}

	tail->next = newnode;
	newnode->next = NULL;
	tail = newnode;
}


inord_list::lsNode* inord_list::searchName(lsNode *ptr, string  name )
{
    //while(  strcmp( name, ptr->word) != 0 )
	while( ptr->word.compare(name) != 0 )
    {
       ptr = ptr->next;
       if( ptr == NULL )
          break;
    }
    return ptr;
}

int inord_list::countWord(char *str)
{
	int i = 0;
	lsNode *ptr = head;

	while( ptr != NULL)
	{
		if( ptr->word.compare(str) == 0 ) i++;
		ptr = ptr->next;
	}

	//outFile << i << "....."<< endl;

	return i;
}
