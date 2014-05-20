#pragma once

using namespace std;

class SLNode
{
    public:
        /*
         * sets values nextNode(NULL) and contents(0)
         */
        SLNode();
        SLNode(int newContents);
        
        /*
         * sets nextNode to NULL
         */
        ~SLNode();
        void setContents (int newContents);
	    int getContents () const;
	    void setNextNode (SLNode* newNode);
	    SLNode* getNextNode () const;
    
    private:
        int contents;
        SLNode* nextNode;
};

