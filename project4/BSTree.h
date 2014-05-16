#include "BSTNode.h"

using namespace std;

template <class T>
class BSTree
{
    public:
        BSTree()
        :root(NULL), sizeOfTree(0){}
        ~BSTree ()
        {clear();}
        unsigned int getSize () const
        {return sizeOfTree;}
        void clear()
        {
            clear(root);
            root = NULL;
            sizeOfTree = 0;
        }
        bool insert (T newContents)
        {return insert(newContents, root);}
        bool find (T targetData)
        {return find(targetData, root);}
        bool BSTremove(T targetData)
        {return BSTremove(targetData, root);}
        T* get(T targetData)
        {return get(targetData, root);}
        void inOrder()
        {inOrder(root);}
        void reverseOrder()
        {reverseOrder(root);}
        
    private:
        BSTNode<T>* root;
        int sizeOfTree;
        void clear (BSTNode<T>*& tmpRoot)
        {
            if(tmpRoot != NULL)
            {
                clear(tmpRoot -> getLeftChild());
                clear(tmpRoot -> getRightChild());
                delete tmpRoot;
        
            }
        }
        bool insert(T newContents, BSTNode<T>*& tmpRoot)
        {
            if(tmpRoot == NULL)
            {
                tmpRoot = new BSTNode<T>(newContents);
                sizeOfTree++;
                return true;
            }
            else if(newContents < tmpRoot -> getData())
            {
                return insert(newContents, tmpRoot -> getLeftChild());
            }
            else if(newContents > tmpRoot -> getData())
            {
                return insert(newContents, tmpRoot -> getRightChild());
            }
            else
                return false;
        }
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
        T* get(T targetData, BSTNode<T>* tempRoot)
        {
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
        void inOrder(BSTNode<T>* tempRoot)
        {
            if(tempRoot != NULL)
            {
                inOrder(tempRoot -> getLeftChild());
                cout << tempRoot -> getData() << " ";
                inOrder(tempRoot -> getRightChild());
            }
        }
        void reverseOrder (BSTNode<T>* tempRoot)
        {
            if(tempRoot != NULL)
            {
                reverseOrder(tempRoot -> getRightChild());
                cout << tempRoot -> getData() << " ";
                reverseOrder(tempRoot -> getLeftChild());
            }
        }
};
/*
data members: size of tree (number of nodes), pointer to root
BSTree () : initialize count to zero, root to NULL
~BSTree () : call clear function
unsigned int getSize () const : return count
(public) void clear () : calls private clear
(private) void clear (BSTNode*& tempRoot) -- helper for public clear
(public) bool insert (T newContents) : calls private insert
(private) bool insert (T newContents, BSTNode*& tempRoot) -- creates node to contain newContents and inserts it in the tree, returns true; if newContents is already in the tree, does not insert, returns false
(public) bool find (T targetData) : calls private find
(private) bool find (T targetData, BSTNode* tempRoot) -- returns true if targetData can be found in tree, else returns false
(public) bool remove (T targetData) : calls private remove
(private) bool remove (T targetData, BSTNode*& tempRoot) -- returns true if targetData is removed from tree, else returns false
(private) void removeMax (T& removed, BSTNode*& tempRoot) -- for use with the recursive remove algorithm
(public) T* get (T targetData) : calls private get
(private) T* get (T targetData, BSTNode* tempRoot) -- returns a pointer to targetData on success, NULL on failure
(public) void inOrder () : calls private inOrder
(private) void inOrder (BSTNode* tempRoot) -- displays contents of nodes in tree in ascending order (requires use of operator<< on node data) to STDOUT
(public) void reverseOrder () : calls private reverseOrder
(private) void reverseOrder (BSTNode* tempRoot) -- displays contents of nodes in tree in descending order (requires use of operator<< on node data) to STDOUT
*/