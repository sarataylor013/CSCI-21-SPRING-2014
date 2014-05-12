#include "BSTree.h"
#include <cstdlib>
#include <iostream>

BSTree::BSTree()
{
   root = NULL;
   size = 0;
}

BSTree::~BSTree()
{
    clear();
}

bool BSTree::insert(int contents)
{
    return insert(contents, root);
}

bool BSTree::remove (int contents)
{
    return remove(contents, root);
}

void BSTree::clear()
{
    clear(root);
    root = NULL;
    size = 0;
}

unsigned int BSTree::getSize () const
{
    return size;
}

void BSTree::inOrder ()
{
    inOrder(root);
}

bool BSTree::insert(int contents, BSTNode*& tmpROOT)
{
    if(tmpROOT == NULL)
    {
        tmpROOT = new BSTNode(contents);
        size++;
        return true;
    }
    else if(contents < tmpROOT -> getContents())
    {
        return insert(contents, tmpROOT -> getLeftChild());
    }
    else if(contents > tmpROOT -> getContents())
    {
        return insert(contents, tmpROOT -> getRightChild());
    }
    else
        return false;
}

bool BSTree::remove (int contents, BSTNode*& tmpROOT)
{
    if(tmpROOT == NULL)
    {
        return false;
    }
    else if(contents < tmpROOT -> getContents())
    {
        return remove(contents, tmpROOT->getLeftChild());
    }
    else if(contents > tmpROOT -> getContents())
    {
        return remove(contents, tmpROOT->getRightChild());
    }
    else
    {
        if(tmpROOT-> getLeftChild() == NULL)
        {
            BSTNode* oldPtr = tmpROOT;
            tmpROOT = tmpROOT->getRightChild();
            delete oldPtr;
        }
        else
        {
            removeMax(tmpROOT -> getContents(), tmpROOT -> getLeftChild());

        }
        size--;
        return true;
    }
}

void BSTree::removeMax (int& contents, BSTNode*& tmpROOT)
{
    if(tmpROOT -> getRightChild() == NULL)
    {
        BSTNode* maxNode = tmpROOT;
        contents = tmpROOT->getContents();
        tmpROOT = tmpROOT -> getLeftChild();
        delete maxNode;
    }
    else
    {
        removeMax(contents, tmpROOT->getRightChild());
    }
}

void BSTree::clear(BSTNode*& tmpROOT)
{
    if(tmpROOT != NULL)
    {
        clear(tmpROOT -> getLeftChild());
        clear(tmpROOT -> getRightChild());
        delete tmpROOT;
        
    }
    
}
void BSTree::inOrder(BSTNode* tmpROOT)
{
    if(tmpROOT != NULL)
    {
        inOrder(tmpROOT -> getLeftChild());
        cout << tmpROOT -> getContents() << " ";
        inOrder(tmpROOT -> getRightChild());
    }
}