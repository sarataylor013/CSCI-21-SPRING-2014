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