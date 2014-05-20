#include "SLNode.h"
#include "SList.h"
#include <cstdlib>
#include <iostream>
#include <sstream>
SList::SList()
{
    head = NULL;
    size = 0;
}

SList::~SList()
{
    clear();
}
void SList::insertHead(int newContents)
{
    SLNode* tmp = new SLNode(newContents);
	tmp -> setNextNode(head);
	head = tmp;
	size++;
}
void SList::insertTail (int newContents)
{
    SLNode* newNode = new SLNode(newContents);
    SLNode* temp = head;
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
void SList::removeHead()
{
    if(head != NULL)
    {
       SLNode* temp = head;
       head = head -> getNextNode();
       delete temp;
       size--;
    }
}
void SList::removeTail()
{
    if(head != NULL)
    {
        SLNode* lastNode = head;
        SLNode* nodeToDelete = head;
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
void SList::clear()
{
    while(head != NULL)
    {
        SLNode* temp = head;
        head = head -> getNextNode();
        delete temp;
        size--;
    }
}
unsigned int SList::getSize() const
{
    return size;
}
string SList::toString()
{
    stringstream list;
    SLNode* temp = head;
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