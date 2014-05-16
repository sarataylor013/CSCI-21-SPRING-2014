#include <iostream>
using namespace std;

template <class T>
class BSTNode
{
    public:
    
        /*
         * Constructor; sets left and right child to NULL
         * @param newData sets data to newData
         */
        BSTNode (T newData)
        :data(newData), leftChild(NULL), rightChild(NULL){}
        
        /*
         * Destructor; Does Nothing.
         */
        virtual ~BSTNode ()
        {}
        
        /*
         * Sets Data in this Node
         * @param newData templated data type, replaces current data
         */
        void setData (T newData)
        { data = newData;}
        
        /*
         * Sets the leftChild pointer in this Node
         * @param newLeftChild a pointer to a templated BSTNode, replaces current leftChild
         */
        void setLeftChild (BSTNode<T>* newLeftChild)
        {leftChild = newLeftChild;}
        
        /*
         * Sets the rightChild pointer in this Node
         * @param newRightChild a pointer to a templated BSTNode, replaces current rightChild
         */
        void setRightChild (BSTNode<T>* newRightChild)
        {rightChild = newRightChild;}
        
        /*
         * Returns the data stored in this node
         * @return teplated data stored in this node
         */
        T getData () const
        {return data;}
        
        /*
         * Returns the leftChild of this node
         * @return pointer to BSTNode stored in the leftChild member variable; 
         *      returns NULL if there is no leftChild
         */
        BSTNode<T>* getLeftChild () const
        {return leftChild;}
        
        /*
         * Returns the rightChild of this node
         * @return pointer to BSTNode stored in the rightChild member variable; 
         *      returns NULL if there is no rightChild
         */
        BSTNode<T>* getRightChild () const
        {return rightChild;}
        
        /*
         * Returns a refrence to the data stored in this node
         * @return teplated refrence to data stored in this node
         */
        T& getData ()
        {return data;}
        
        /*
         * Returns a refrence to the leftChild of this node
         * @return refrence to pointer to BSTNode stored in the leftChild member variable; 
         *      returns NULL if there is no leftChild
         */
        BSTNode<T>*& getLeftChild ()
        {return leftChild;}
        
        /*
         * Returns a refrence the rightChild of this node
         * @return a refrence to pointer to BSTNode stored in the rightChild member variable; 
         *      returns NULL if there is no rightChild
         */
        BSTNode<T>*& getRightChild ()
        {return rightChild;}
        
    
    private:
        T data;
        BSTNode<T>* leftChild;
        BSTNode<T>* rightChild;
};