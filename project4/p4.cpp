//
// Grader comments 2014.05.23
// -35 points total
//
#include "Word.h"
#include "BSTree.h"

#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

/*
 * Displays an error if BSTree has not been instantiated
 * @param myTree a pointer to a BSTree
 * @return true if myTree is not NULL
 */
bool error(BSTree<Word>* myTree);

/*
 * Transforms a given string to all upper case
 * @param newWord the string to be transformed
 * @return newWord in all uppercase
 */
string toUpper(string newWord);

using namespace std;
int main (int argc, char* argv[])
{
    char command;
    string input;
    Word newWord;
    BSTree<Word>* myTree = NULL;
    ifstream myfile (argv[1]);
    if(argc != 2)
    {
        cout << "INCORRECT NUMBER OF COMMAND LINE ARGUMENTS\n";
    }
    else if (myfile.good())
    {
		//
		// Grader comments 2014.05.23
		// Using the extraction operator like this is problematic.
		// Imagine that the tree hasn't yet been created. That is,
		// myTree == NULL. If you get a command that says "I attercop",
		// Your error processing will see that there is no tree, which
		// is good. But the extraction operator only gets one character
		// at a time, and keeps getting characters from the same line
		// until there is no more data on the line. So command is 'I'
		// on the first time through, and then command is 'a', then 't',
		// 't', 'e', and so on.
		//
		// -20 points
		//
		// Rob did some rearranging throughout this loop to fix the
		// extraction operator stuff, to get the unit test to work.
		//
        while (getline(myfile, input) == true)
        {
			command = input[0];
			
			if(input.size() > 2)
			{
				input = input.substr(2);
			}
			
			//cout << "Rob: '" << command << "', '" << input << "'" << endl;

            switch(command)
            {
                case '#':
                    //getline(myfile, input);	// Rob
                break;
                case 'C':
                case 'c':
                    //create Tree
                    myTree = new BSTree<Word>();
                    cout << "TREE CREATED\n";
                break;
                case 'X':
                case 'x':
                    if(!error(myTree))
                    {
                        //clear tree
                        myTree->clear();
                        cout << "TREE CLEARED\n";
                    }
                break;
                case 'D':
                case 'd':
                    if(!error(myTree))
                    {
                        //delete myTree;
                        myTree->clear();
                        delete myTree;
                        myTree = NULL;
                        cout << "TREE DELETED\n";    
                    }
                break;
                case 'I':
                case 'i':
				//
				// Grader comments 2014.05.23
				// WORD x INCREMENTED should be reported only if you
				// actually increment the count. Also, if you're inserting
				// the value for the first time, then the program
				// should report WORD x INSERTED. Finally, don't convert
				// the word to upper case. The data should be inserted
				// into the tree as is.
				//
				// -5 points
				//
				// Rob rearranged the following to get the unit test to work.
				//
                    if(!error(myTree))
                    {
                        //myfile >> input;	// Rob
                        newWord.setWord(toUpper(input));
                        if(!myTree->insert(newWord))
                        {
                            myTree->get(newWord)->incrementCount();  
		                    cout << "WORD "<< input <<" INCREMENTED\n";
                        }
						else
						{
							cout << "WORD "<< input << " INSERTED\n";
						}
                    }
                    //insert word in alphabetical order
                break;
                case 'F':
                case 'f':
                    if(!error(myTree))
                    {
                        //myfile >> input;	// Rob
                        newWord.setWord(toUpper(input));
                        if(myTree->getSize() == 0)
                        {
                            cout << "TREE EMPTY\n";
                        }
                        else if(myTree->find(newWord))
                        {
                            cout << "FOUND "<< toUpper(input) <<"\n";
                        }
                        else
                            cout << toUpper(input) <<" NOT FOUND\n";
                    }
                break;
                case 'R':
                case 'r':
                    if(!error(myTree))
                    {
                        //myfile >> input;	// Rob
                        newWord.setWord(toUpper(input));
                        if(myTree->getSize() == 0)
                        {
                            cout << "TREE EMPTY\n";
                        }
						
						//
						// Grader comments 2014.05.23
						// Should do this stuff only if the tree is non-empty.
						// -5 points
						// Rob changed the following code to get the unit test to work.
						//
                        //remove word
						else
						{
	                        if(myTree->BSTremove(newWord))
	                            cout << "REMOVED "<< toUpper(input) <<"\n";
	                        else
	                            cout << toUpper(input) <<" NOT FOUND\n";
						}
                    }
                break;
                case 'G':
                case 'g':
                    if(!error(myTree))
                    {
                        //myfile >> input;	// Rob
                        newWord.setWord(toUpper(input));
                        if(myTree->getSize() == 0)
                        {
                            cout << "TREE EMPTY\n";
                        }
						
						//
						// Grader comments 2014.05.23
						// Should do this stuff only if the tree is non-empty.
						// -5 points
						// Rob changed the following code to get the unit test to work.
						//
						else
						{
							if(myTree->find(newWord))
								cout << "GOT "<< toUpper(input) << " " << myTree->get(newWord)->getCount() << "\n";
							else
								cout << toUpper(input) <<" NOT FOUND\n";
						}
                    }
                break;
                case 'N':
                case 'n':
                    if(!error(myTree))
                    {
                        cout << "TREE SIZE IS "<< myTree->getSize() << endl;
                    }
                break;
                case 'O':
                case 'o':
                    if(!error(myTree))
                    {
                        if(myTree->getSize() > 0)
                        {
                            myTree->inOrder();
                            cout << endl;
                        }
                        else
                            cout << "TREE EMPTY\n";
                    }
                break;
                case 'E':
                case 'e':
                    if(!error(myTree))
                    {
                        if(myTree->getSize() > 0)
                        {
                            myTree->reverseOrder();
                            cout << endl;
                        }
                        else
                            cout << "TREE EMPTY\n";
                    }
                break;
                default :
                    cout << "NOT A VALID COMMAND\n";
            }
        }
        myfile.close();
        
    }
    else
    {
        cout << "NOT A VALID FILENAME\n";
    }
    return 0;
}

bool error(BSTree<Word>* myTree)
{
    if(myTree == NULL)
    {
        cout << "MUST CREATE TREE INSTANCE\n";
        return true;
    }
    return false;
}

string toUpper(string newWord)
{
    for(unsigned int i = 0; i<newWord.length();i++)
    {
        newWord[i] = toupper(newWord[i]);
    }
    return newWord;
}