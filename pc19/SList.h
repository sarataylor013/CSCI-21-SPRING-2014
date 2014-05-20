#pragma once

#include "SLNode.h"
#include <string>
using namespace std;

class SList
{
    public:
        SList();
        ~SList();
        void insertHead(int newContents);
        void insertTail (int newContents);
        void removeHead();
        void removeTail ();
        void clear();
        unsigned int getSize() const;
        string toString();
    
    
    private:
        SLNode* head;
        unsigned int size;
};
