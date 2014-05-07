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
}

unsigned int BSTree::getSize () const
{
    return size;
}

void BSTree::inOrder ()
{
    inOrder(root);
}

bool BSTree::insert(int contents, BSTNode*& ROOT)
{
    if(ROOT == NULL)
    {
        ROOT = new BSTNode(contents);
        size++;
        return true;
    }
    else if(contents < ROOT -> getContents())
    {
        return insert(contents, ROOT -> getLeftChild());
    }
    else if(contents > ROOT -> getContents())
    {
        return insert(contents, ROOT -> getRightChild());
    }
    else
        return false;
}
void BSTree::clear(BSTNode*& ROOT)
{
    if(ROOT != NULL)
    {
        inOrder(ROOT -> getLeftChild());
        inOrder(ROOT -> getRightChild());
        delete ROOT;
    }
}
void BSTree::inOrder(BSTNode* ROOT)
{
    if(ROOT != NULL)
    {
        inOrder(ROOT -> getLeftChild());
        cout << ROOT -> getContents() << " ";
        inOrder(ROOT -> getRightChild());
    }
}