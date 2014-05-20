#include "DLNode.h"
#include <string>
using namespace std;

template <class T>
class DList
{
    public:
        /*
         *  Default Constructor. Sets contents to 0 and next and previous to NULL
         */
        DList()
        :head(NULL), tail(NULL), size(0){}
        
        /*
         * Call the clear function
         */
        ~DList()
        {
            clear();
        }
        
        /*
         * Get the number of nodes in the list
         * @return an unsigned int containing the number of nodes in the list
         */
        unsigned int getCount() const
        {return size;}
        
        /*
         * create new DLNode with newContents and attach at head; *should not be called in conjunction with insert
         * @param newContents int containing the new contents
         */
        void insertHead(T newContents)
        {
            DLNode<T>* newNode = new DLNode<T>(newContents);
            newNode -> setNextNode(head);
            if(head == NULL)
            {
                tail = newNode;
            }
	        head = newNode;
	        size++;
        }
        
        /*
		 * create new DLNode with newContents and attach at tail; *should not be called in conjunction with insert
		 * @param newContents int containing the new contents
		 */
        void insertTail (T newContents)
        {
            DLNode<T>* newNode = new DLNode<T>(newContents);
            DLNode<T>* temp = head;
            if(head == NULL)
            {
                head = newNode;
            }
            else
            {
                while(temp->getNextNode() != NULL)
                {
                    temp = temp -> getNextNode();
                }
                temp -> setNextNode(newNode);
                newNode -> setPreviousNode (temp);
            }
            tail = newNode;
            size++;
        }
        
        /*
		 * create new DLNode with newContents and insert in ascending (based on newContents) order;
		 *    should not be called in conjunction with pushFront or pushBack
		 * @param newContents int containing the new contents
		 */
        void insert (T newContents)
        {
            DLNode<T>* newNode = new DLNode<T>(newContents);
            DLNode<T>* temp = head;
            
            if(head == NULL  || head->getContents() >= newContents)
            {
                delete newNode;
                insertHead(newContents);
            }
            else
            {
                while(temp->getContents() < newContents && temp->getNextNode() != NULL)
                {
                    temp = temp->getNextNode();
                }
                if(temp->getContents() < newContents)
                {
                    delete newNode;
                    insertTail(newContents);
                }
                else
                {
                    newNode->setNextNode(temp);
                    newNode->setPreviousNode(temp->getPreviousNode());
                    if(temp->getPreviousNode() != NULL)
                    {
                        temp->getPreviousNode()->setNextNode(newNode);
                    }
                    temp->setPreviousNode(newNode);
                    size++;
                }
            }
        }
        
        /*
		 * return the value of the contents of the head node; throw an exception (throw "LIST EMPTY") if the list is empty
		 * @return an int containing the contents of the first node
		 */
		T getFront() const
		{return head->getContents();}
		
		/*
		 * return the value of the contents of the tail node; throw an exception (throw "LIST EMPTY") if the list is empty
		 * @return an int containing the contents of the last node
		 */
		T getBack () const
		{return tail->getContents();}
		
		/*
		 * @param an int to be compaired with the contenets of each node in the list
		 * @return bool true if the target is in the list, else return false
		 */
		bool get (int target) const
		{
		    bool wasFound = false;
		    DLNode<T>* temp = head;
		    if(head == NULL)
            {
                wasFound = false;
            }
            else
            {
                while(temp->getNextNode() != NULL && temp->getContents() != target)
                {
                    temp = temp->getNextNode();
                }
                if(temp->getContents() == target)
                {
                    wasFound = true;
                }
            }
            return wasFound;
		}
		/*
		 * remove current head node; do nothing if list is empty
		 */
        void removeHead()
        {
            if(head != NULL)
            {
                DLNode<T>* temp = head;
                if(tail == head)
                {
                    tail = NULL;
                    head = NULL;
                    delete temp;
                    size--;
                }
                else
                {
                    head = head -> getNextNode();
                    head->setPreviousNode(NULL);
                    delete temp;
                    size--;
                }
            }
        }
        
        /*
		 * remove current tail node; do nothing if list is empty
		 */
        void removeTail ()
        {
            if(head != NULL)
            {
                DLNode<T>* temp = tail;
                if(head == tail)
                {
                    tail = NULL;
                    head = NULL;
                    delete temp;
                    size--;
                }
                else
                {
                    tail = tail->getPreviousNode();
                    tail->setNextNode(NULL);
                    delete temp;
                    size--;
                }
            }
        }
        
        /*
		 * remove the first instance of a DLNode containing target; do nothing if target is not found
		 * @param target an int to be compared to the contents of the nodes in each list
		 * @return bool true if the target was found and removed, false if target was not found
		 */
        bool removeFirst (T newContents)
        {
            bool wasFound = false;
            DLNode<T>* temp = head;
            DLNode<T>* before = head;
            
            if(head == NULL)
            {
                wasFound = false;
            }
            else
            {
                if(temp->getContents() == newContents)
                {
                    removeHead();
                }
                else
                {
                    while(temp->getNextNode() != NULL && temp->getContents() != newContents)
                    {
                        before = temp;
                        temp = temp->getNextNode();
                    }
                    if(temp->getContents() == newContents)
                    {
                        before->setNextNode(temp->getNextNode());
                        if( temp->getNextNode() != NULL)
                        {
                            temp->getNextNode()->setPreviousNode(before);
                        }
                        else
                        {
                            tail = before;
                        }
                        delete temp;
                        wasFound = true;
                        size--;
                    }
                }
            }
            return wasFound;
        }
        /*
		 * remove all instances of DLNode containing target; do nothing if target is not found
		 * @param target an int to be compared to the contents of the nodes in each list
		 * @return bool true if the target was found and removed, false if target was not found
		 */
        bool removeAll (T newContents)
        {
            bool wasFound = false;
            while(removeFirst(newContents))
            {
                wasFound = true;
            }
            return wasFound;
        }
        /*
		 * clear all nodes from list, reset count to zero, set head and tail to NULL
		 */
        void clear()
        {
            while(head != NULL)
            {
                DLNode<T>* temp = head;
                head = head -> getNextNode();
                delete temp;
                size--;
            }
        }
        /*
		 * display the contents of each node in the list, formatted per the program specification ("NUM1,NUM2,NUM3,...,NUMX"), to the output stream out
		 * @param out an ostream& designating the output stream
		 * @param src a DLList to be output
		 */
        friend ostream& operator<< (ostream& out, const DList<T>& src)
        {
            DLNode<T>* temp = src.head;
            while(temp->getNextNode() != NULL)
            {
                out << temp->getContents() << ",";
                temp = temp->getNextNode();
            }
            out << temp->getContents() <<endl;
            
            return out;
        }
    
    
    private:
        DLNode<T>* head;
        DLNode<T>* tail;
        unsigned int size;
};