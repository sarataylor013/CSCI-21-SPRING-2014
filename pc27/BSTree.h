#pragma once

#include "BSTNode.h"
using namespace std;

class BSTree
{
    public:
        BSTree();
        ~BSTree();
        bool insert(int contents);
        bool remove (int contents);
        void clear();
        unsigned int getSize () const;
        void inOrder ();
    
    private:
        BSTNode* root;
        unsigned int size;
        bool insert(int contents, BSTNode*& tmpROOT);
        bool remove (int contents, BSTNode*& tmpROOT);
        void removeMax (int& contents, BSTNode*& tmpROOT);
        void clear(BSTNode*& tmpROOT);
        void inOrder(BSTNode* tmpROOT);
};