/* Driver for programming project 3
 *
 * CSCI 21, Spring 2014
 *
 * Programmer: Sara Taylor
 */

#include "DList.h"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		cout << "INVALID NUMBER OF ARGUMENTS\n";
		return 0;
	}
	ifstream myfile(argv[1]);
	if(myfile.good())
	{
		char command;
		int number;
		string comment;
		DList<int>* myList = NULL;
		while(myfile >> command)
		{
			switch(command){
				case '#':
					getline(myfile, comment);
				break;
				case 'c':
				case 'C':
					if(myList != NULL)
					{
						myList->clear();
						myList = NULL;
					}
					myList = new DList<int>();
					cout << "LIST CREATED" << endl;
				break;
				case 'x':
				case 'X':
					if(myList != NULL)
					{
						myList->clear();
					}
					cout << "LIST CLEARED\n";
				break;
				case 'd':
				case 'D':
					if(myList != NULL)
					{
						myList->clear();
						myList = NULL;
					}
					cout << "LIST DELETED\n";
				break;
				case 'i':
				case 'I':
					myfile >> number;
					myList->insert(number);
					cout << "VALUE "<< number <<" INSERTED\n";
				break;
				case 'f':
				case 'F':
    				myfile >> number;
    				myList->insertHead(number);
					cout <<  "VALUE "<< number <<" ADDED TO HEAD\n";
				break;
				case 'b':
				case 'B':
				    myfile >> number;
    				myList->insertTail(number);
					cout <<  "VALUE "<< number <<" ADDED TO TAIL\n";
				break;
				case 'a':
				case 'A':
    				if(myList->getCount() == 0)
    				{
    				    cout << "LIST EMPTY\n";
    				}
    				else
					    cout <<"VALUE "<<myList->getFront()<<" AT HEAD\n";
				break;
				case 'z':
				case 'Z':
    				if(myList->getCount() == 0)
    				{
    				    cout << "LIST EMPTY\n";
    				}
    				else
					    cout <<"VALUE "<<myList->getBack()<<" AT TAIL\n";
				break;
				case 't':
				case 'T':
    				if(myList->getCount() == 0)
    				{
    				    cout << "LIST EMPTY\n";
    				}
    				else
    				{
    				    myList->removeHead();
    				    cout << "REMOVED HEAD\n";
    				}
				break;
				case 'k':
				case 'K':
				    if(myList->getCount() == 0)
    			    {
    			         cout << "LIST EMPTY\n";
    			    }
				    else
				    {
				        myList->removeTail();
				        cout << "REMOVED TAIL\n";
				    }
				break;
				case 'e':
				case 'E':
				    myfile >> number;
				    if(myList->removeAll(number))
				    {
				        cout << "VALUE "<<number<<" ELIMINATED\n";
				    }
				    else
				        cout << "VALUE "<<number<<" NOT FOUND\n";
				break;
				case 'r':
				case 'R':
				    myfile >> number;
				    if(myList->removeFirst(number))
				    {
				        cout << "VALUE "<<number<<" REMOVED\n";
				    }
				    else
				        cout << "VALUE "<<number<<" NOT FOUND\n";
				break;
				case 'g':
				case 'G':
    				myfile >> number;
    				if(myList->get(number))
    				{
    				    cout << "VALUE "<<number<<" FOUND\n";
    				}
    				else
				        cout << "VALUE "<<number<<" NOT FOUND\n";
				break;
				case 'n':
				case 'N':
				    cout <<"LIST SIZE IS "<< myList->getCount()<<endl;
				break;
				case 'p':
				case 'P':
    				if(myList->getCount() == 0)
    				{
    				    cout << "LIST EMPTY\n";
    				}
    				else
    				    cout << *myList;
				break;
			}	
		}
		myfile.close();
		return 0;
	}
	else
	{
		cout << "INVALID FILENAME\n";
		return 0;
	}
}
/*
implement a driver that provides the following functionality [150 pts]:

    accepts a single command-line argument (name of input file), opens and processes the input file
    if there is no command-line argument, display an appropriate error message
    if the filename provided in argv is invalid, display an appropriate error message
    produces the output EXACTLY as described above for the commands contained in the input file (the input file may contain any combination from the OPERATION list)


Required output format (your outputs must be EXACTLY as specified to pass the UNIT TEST):

    * any operation that tries to access a null list pointer, except create: "MUST CREATE LIST INSTANCE" *
    any line of the file that starts with '#' is a comment -- ignore
    create list: "LIST CREATED" (* if a list instance already exists, delete it first *)
    clear list: "LIST CLEARED"
    delete list: "LIST DELETED" (* be sure to NULL the list pointer *)
    insert: "VALUE x INSERTED"
    add to front: "VALUE x ADDED TO HEAD"
    add to back: "VALUE x ADDED TO TAIL"
    get head contents: "VALUE x AT HEAD"; catch and print exception ("LIST EMPTY") if list is empty
    get tail contents: "VALUE x AT TAIL"; catch and print exception ("LIST EMPTY") if list is empty
    remove from front: "REMOVED HEAD" or "LIST EMPTY" if empty
    remove from back: "REMOVED TAIL" or "LIST EMPTY" if empty
    eliminate element: "VALUE x ELIMINATED" on success or "VALUE x NOT FOUND" on failure
    remove element: "VALUE x REMOVED" on success or "VALUE x NOT FOUND" on failure
    get element: "VALUE x FOUND" on success or "VALUE x NOT FOUND" on failure
    show number of items: "LIST SIZE IS x"
    print all: "NUM1,NUM2,NUM3,...,xx" or "LIST EMPTY" if empty*/
