#pragma once

using namespace std;

class BSTNode
{
    public:
        /*
         * sets values leftChild(NULL), rightChild(NULL), and contents(0)
         */
        BSTNode();
        BSTNode(int newContents);
        
        /*
         * sets values leftChild(NULL), rightChild(NULL)
         */
        ~BSTNode();
        void setContents (int newContents);
	    int getContents () const;
	    int& getContents ();
	    void setLeftChild (BSTNode* newLeft);
	    void setRightChild (BSTNode* newRight);
	
    	BSTNode* getLeftChild () const;
    	BSTNode*& getLeftChild ();
	
    	BSTNode* getRightChild () const;
    	BSTNode*& getRightChild ();
    
    private:
        int contents;
        BSTNode* leftChild; 
	    BSTNode* rightChild; 
};

