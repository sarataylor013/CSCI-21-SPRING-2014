
#include <iostream>
#include <sstream>
using namespace std;
template <class T>
class DLNode
{
  public:
    /*
     * Default constructor; sets previous and next to NULL and contents to 0
     */
    DLNode()
    :contents(0), next(NULL), previous(NULL){}
    /*
     * Overloaded constructor
     * @param newContents templated Datatype stored in contents
     */
    DLNode(T newContents)
    {
        next = NULL;
        previous = NULL;
        contents = newContents;
    }
    /*
     * Does Nothing
     */
    virtual ~DLNode()
    {}
    /*
     * sets contents to newContents
     * @param newContents
     */
    void setContents (T newContents)
    {
        contents = newContents;
    }
    /*
     * returns contents
     * @return Type T data stored in contents
     */
    T getContents () const
    {
        return contents;
    }
    /*
     * sets next pointer to the node after it
     * @param newNode a pointer to a DLNode stored in next
     */
    void setNextNode (DLNode<T>* newNode)
    {
        next = newNode;
    }
	/*
     * returns pointer to next Node
     * @return pointer to DLNode of type T
     */
    DLNode<T>* getNextNode () const
    {
        return next;
    }
    /*
     * sets previous pointer to the node before it
     * @param newNode a pointer to a DLNode stored in previous
     */
    void setPreviousNode (DLNode<T>* newNode)
    {
        previous = newNode;
    }
	/*
     * returns pointer to previous Node
     * @return pointer to DLNode of type T
     */
    DLNode<T>* getPreviousNode () const
    {
        return previous;
    }
  
  private:
    T contents;
    DLNode<T>* next;
    DLNode<T>* previous;
  
  
    
};


/*
 implement a complete doubly-linked list node class with the following functions and data members [150 pts]:

    data members: contents (int), pointer to previous node, pointer to next node
    DLNode () : initialize contents to zero, next and previous to NULL
    DLNode (int newContents) : initialize contents to newContents, next and previous to NULL
    virtual ~DLNode () : nothing to be done
    void setContents (int newContents)
    void setNext (DLNode* newNext)
    void setPrevious (DLNode* newPrevious)
    int getContents () const
    DLNode* getNext () const
    DLNode* getPrevious () const
*/