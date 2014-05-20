
#include "SLNode.h"
#include <string>
using namespace std;

template <class T>
class SList
{
    public:
        SList()
        :head(NULL), size(0){}
        ~SList()
        {
            clear();
        }
        void insertHead(T newContents)
        {
            SLNode<T>* newNode = new SLNode<T>(newContents);
	        newNode -> setNextNode(head);
	        head = newNode;
	        size++;
        }
        void insertTail (T newContents)
        {
            SLNode<T>* newNode = new SLNode<T>(newContents);
            SLNode<T>* temp = head;
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
            }
            size++;
        }
        void insert (T newContents)
        {
            SLNode<T>* newNode = new SLNode<T>(newContents);
            SLNode<T>* temp = head;
            //empty list
            if(head == NULL)
            {
                insertHead(newContents);
            }
            //list has 1 item
            else if ( head->getNextNode() == NULL )
            {
                if(head->getContents() > newContents)
                {
                    insertHead(newContents);
                }
                else
                {
                    insertTail(newContents);
                }
            }
            //list has > 1 item
            else
            {
                if(temp->getContents() > newContents)
                {
                    insertHead(newContents);
                }
                else
                {
                    while(temp->getNextNode()->getContents() < newContents && temp->getNextNode()->getNextNode() != NULL)
                    {
                        temp = temp -> getNextNode();
                    }
                    if(temp->getNextNode()->getContents() < newContents)
                    {
                        insertTail(newContents);
                    }
                    else
                    {
                        newNode -> setNextNode(temp->getNextNode());
                        temp->setNextNode(newNode);
                        size++;
                    }
                }
            }
        }
        void removeHead()
        {
            if(head != NULL)
            {
                SLNode<T>* temp = head;
                head = head -> getNextNode();
                delete temp;
                size--;
            }
        }
        void removeTail ()
        {
            if(head != NULL)
            {
                SLNode<T>* lastNode = head;
                SLNode<T>* nodeToDelete = head;
                if(lastNode->getNextNode() == NULL)
                {
                    removeHead();
                }
                else
                {
                    while(lastNode->getNextNode()->getNextNode() != NULL)
                    {
                        lastNode = lastNode -> getNextNode();
                    }
                    nodeToDelete = lastNode->getNextNode();
                    lastNode-> setNextNode(NULL);
                    delete nodeToDelete;
                    size--;
                }
            }
        }
        bool removeFirst (T newContents)
        {
            bool wasFound = false;
            SLNode<T>* temp = head;
            SLNode<T>* before = head;
            
            if(head == NULL)
            {
                wasFound = false;
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
                    delete temp;
                    wasFound = true;
                    size--;
                }
            }
            return wasFound;
        }
        bool removeAll (T newContents)
        {
            bool wasFound = false;
            while(removeFirst(newContents))
            {
                wasFound = true;
            }
            return wasFound;
        }
        void clear()
        {
            while(head != NULL)
            {
                SLNode<T>* temp = head;
                head = head -> getNextNode();
                delete temp;
                size--;
            }
        }
        unsigned int getSize() const
        {
            return size;
        }
        
        string toString()
        {
            stringstream list;
            SLNode<T>* temp = head;
            if(head == NULL)
            {
                return list.str();
            }
            else
            {
                while(temp->getNextNode() != NULL)
                {
                    list << temp->getContents() << ",";
                    temp = temp->getNextNode();
                }
                list << temp->getContents();
            }
            return list.str();
        }
    
    
    private:
        SLNode<T>* head;
        unsigned int size;
};