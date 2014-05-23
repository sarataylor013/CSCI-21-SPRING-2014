//
// Grader comments 2014.05.23
// -15 points total
//
#pragma once
#include "BSTNode.h"

using namespace std;

template <class T>
class BSTree
{
    public:
        /*
         * Default constructor; initialize count to zero, root to NULL
         */
        BSTree()
        :root(NULL), sizeOfTree(0){}
        
        /*
         * Default Destructor; Calls clear();
         */
        ~BSTree ()
        {clear();}
        
        /*
         * returns the size of the tree
         * @return unsigned int containing size of the tree
         */
        unsigned int getSize () const
        {return sizeOfTree;}
        
        /*
         * Calls a private clear function then nulls out the root
         */
        void clear()
        {
            clear(root);
            root = NULL;
            sizeOfTree = 0;
        }
        
        /*
         * Calls private insert to insert new Nodes in the tree
         * @param newContents contents to be stored in the new Node
         * @return bool; returns true if insert was successful
         */
        bool insert (T newContents)
        {return insert(newContents, root);}
        
        /*
         * Calls private find to find data in the tree
         * @param targetData templated Data to be found
         * @return bool returns true if Data was found
         */
        bool find (T targetData)
        {return find(targetData, root);}
        
        /*
         * Calls private remove function to remove targetData
         * @param targetData templated Data to be removed
         * @return bool retruns true if data was found and removed
         */
		//
		// Grader comments 2014.05.23
		// Function should be called remove()
		// -5 points
		//
        bool BSTremove(T targetData)
        {return BSTremove(targetData, root);}
        
        /*
         * Calls private get function returns a pointer to targetData on success, NULL on failure
         * @param targetData templated data to be found
         * @return templated pointer; returns a pointer to targetData on success, NULL on failure
         */
        T* get(T targetData)
        {return get(targetData, root);}
        
        /*
         * Calls private inOrder to display the contents of the tree in ascending order
         */
        void inOrder()
        {inOrder(root);}
        
        /*
         * Calls private reverseOrder to display the contents of the tree in descending order
         */
        void reverseOrder()
        {reverseOrder(root);}
        
    private:
        BSTNode<T>* root;
        int sizeOfTree;
        
        /*
         * recursively deletes all the nodes in the tree
         * @param tmpRoot pointer to the root of the current subtree
         */
        void clear (BSTNode<T>*& tempRoot)
        {
            if(tempRoot != NULL)
            {
                clear(tempRoot -> getLeftChild());
                clear(tempRoot -> getRightChild());
                delete tempRoot;
        
            }
        }
        
        /*
         * recursively sorts and inserts new Nodes in the tree
         * @param newContents contents to be stored in the new Node
         * @param tempRoot pointer to the root of the current subtree
         * @return bool; returns true if insert was successful
         */
        bool insert(T newContents, BSTNode<T>*& tempRoot)
        {
            if(tempRoot == NULL)
            {
                tempRoot = new BSTNode<T>(newContents);
                sizeOfTree++;
                return true;
            }
            else if(newContents < tempRoot -> getData())
            {
                return insert(newContents, tempRoot -> getLeftChild());
            }
            else if(newContents > tempRoot -> getData())
            {
                return insert(newContents, tempRoot -> getRightChild());
            }
            else
                return false;
        }
        
        /*
         * Finds data in the tree
         * @param targetData templated Data to be found
         * @param tempRoot pointer to the root of the current subtree
         * @return bool returns true if Data was found; else returns false
         */
        bool find(T targetData, BSTNode<T>* tempRoot)
        {
            if(tempRoot == NULL)
            {
                return false;
            }
            else if(targetData == tempRoot -> getData())
            {
                return true;
            }
            else if(targetData > tempRoot -> getData())
            {
                return find(targetData, tempRoot -> getRightChild());
            }
            else
            {
                return find(targetData, tempRoot -> getLeftChild());
            }
        }
        
        /*
         * Removes node containing targetData
         * @param targetData templated Data to be removed
         * @param tempRoot pointer to the root of the current subtree
         * @return bool retruns true if data was found and removed
         */
        bool BSTremove(T targetData, BSTNode<T>*& tempRoot)
        {
            if(tempRoot == NULL)
            {
                return false;
            }
            else if(targetData < tempRoot -> getData())
            {
                return BSTremove(targetData, tempRoot->getLeftChild());
            }
            else if(targetData > tempRoot -> getData())
            {
                return BSTremove(targetData, tempRoot->getRightChild());
            }
            else
            {
                if(tempRoot-> getLeftChild() == NULL)
                {
                    BSTNode<T>* oldPtr = tempRoot;
                    tempRoot = tempRoot->getRightChild();
                    delete oldPtr;
                }
                else
                {
                    removeMax(tempRoot -> getData(), tempRoot -> getLeftChild());

                }
                sizeOfTree--;
                return true;
            }
        }
        
        /*
         * Helps the remove function reorder the tree if the target node has a leftChild
         * @param removed templated Data to be removed
         * @param tempRoot pointer to the root of the current subtree
         */
        void removeMax (T& removed, BSTNode<T>*& tempRoot)
        {
            if(tempRoot -> getRightChild() == NULL)
            {
                BSTNode<T>* maxNode = tempRoot;
                removed = tempRoot->getData();
                tempRoot = tempRoot -> getLeftChild();
                delete maxNode;
            }
            else
            {
                removeMax(removed, tempRoot->getRightChild());
            }
        }
        
        /*
         * Searches the tree and returns a pointer to targetData on success, NULL on failure
         * @param targetData templated data to be found
         * @param tempRoot pointer to the root of the current subtree
         * @return templated pointer; returns a pointer to targetData on success, NULL on failure
         */
        T* get(T targetData, BSTNode<T>* tempRoot)
        {
			//
			// Grader comments 2014.05.23
			// tempRoot could be null on entry to this function.
			// Can't use it without checking it first.
			// -10 points
			//
			if(tempRoot == NULL) {	// Rob added to get unit test to work
				return NULL;
			}
			
            if(targetData == tempRoot->getData())
            {
                return &(tempRoot->getData());
            }
            else if(targetData < tempRoot->getData())
            {
                if(tempRoot->getLeftChild() == NULL)
                {
                    return NULL;
                }
                else
                {
                    return get(targetData ,tempRoot->getLeftChild());
                }
            }
            else
            {
                if(tempRoot->getRightChild() == NULL)
                {
                    return NULL;
                }
                else
                {
                    return get(targetData ,tempRoot->getRightChild());
                }
            }
        }
        
        /*
         * Recursively displays the contents of the tree in ascending order
         * @param tempRoot pointer to the root of the current subtree
         */
        void inOrder(BSTNode<T>* tempRoot)
        {
            if(tempRoot != NULL)
            {
                inOrder(tempRoot -> getLeftChild());
                cout << tempRoot -> getData() << "\n";	// Rob added newline for unit test
                inOrder(tempRoot -> getRightChild());
            }
        }
        
        /*
         * Recursively displays the contents of the tree in descending order
         * @param tempRoot pointer to the root of the current subtree
         */
        void reverseOrder (BSTNode<T>* tempRoot)
        {
            if(tempRoot != NULL)
            {
                reverseOrder(tempRoot -> getRightChild());
                cout << tempRoot -> getData() << "\n";	// Rob added newline for unit test
                reverseOrder(tempRoot -> getLeftChild());
            }
        }
};