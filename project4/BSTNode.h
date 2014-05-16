#include <iostream>
using namespace std;

template <class T>
class BSTNode
{
    public:
        BSTNode (T newData)
        :data(newData), leftChild(NULL), rightChild(NULL){}
        virtual ~BSTNode ()
        {}
        void setData (T newData)
        { data = newData;}
        void setLeftChild (BSTNode<T>* newLeftChild)
        {leftChild = newLeftChild;}
        void setRightChild (BSTNode<T>* newRightChild)
        {rightChild = newRightChild;}
        T getData () const
        {return data;}
        BSTNode<T>* getLeftChild () const
        {return leftChild;}
        BSTNode<T>* getRightChild () const
        {return rightChild;}
        T& getData ()
        {return data;}
        BSTNode<T>*& getLeftChild ()
        {return leftChild;}
        BSTNode<T>*& getRightChild ()
        {return rightChild;}
        
    
    private:
        T data;
        BSTNode<T>* leftChild;
        BSTNode<T>* rightChild;
};
/*
data members: leftChild (BSTNode*), rightChild (BSTNode*), data (templated)
BSTNode (T newData) : initialize leftChild and rightChild to NULL, data to newData
virtual ~BSTNode () : nothing to be done
void setData (T newData)
void setLeftChild (BSTNode* newLeftChild)
void setRightChild (BSTNode* newRightChild)
T getData () const
BSTNode* getLeftChild () const
BSTNode* getRightChild () const
T& getData ()
BSTNode*& getLeftChild ()
BSTNode*& getRightChild ()
*/