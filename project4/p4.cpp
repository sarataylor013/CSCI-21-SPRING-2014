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
        while (myfile >> command )
        {
            switch(command)
            {
                case '#':
                    getline(myfile, input);
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
                    if(!error(myTree))
                    {
                        myfile >> input;
                        newWord.setWord(toUpper(input));
                        if(!myTree->insert(newWord))
                        {
                            myTree->get(newWord)->incrementCount();  
                        }
                    }
                    //insert word in alphabetical order
                    cout << "WORD "<< toUpper(input) <<" INCREMENTED\n";
                break;
                case 'F':
                case 'f':
                    if(!error(myTree))
                    {
                        myfile >> input;
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
                        myfile >> input;
                        newWord.setWord(toUpper(input));
                        if(myTree->getSize() == 0)
                        {
                            cout << "TREE EMPTY\n";
                        }
                        //remove word
                        if(myTree->BSTremove(newWord))
                            cout << "REMOVED "<< toUpper(input) <<"\n";
                        else
                            cout << toUpper(input) <<" NOT FOUND\n";
                    }
                break;
                case 'G':
                case 'g':
                    if(!error(myTree))
                    {
                        myfile >> input;
                        newWord.setWord(toUpper(input));
                        if(myTree->getSize() == 0)
                        {
                            cout << "TREE EMPTY\n";
                        }
                        if(myTree->find(newWord))
                            cout << "GOT "<< toUpper(input) << " " << myTree->get(newWord)->getCount() << "\n";
                        else
                            cout << toUpper(input) <<" NOT FOUND\n";
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