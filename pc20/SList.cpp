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
    SLNode* newNode = new SLNode(newContents);
	newNode -> setNextNode(head);
	head = newNode;
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
void SList::insert (int newContents)
{
    SLNode* newNode = new SLNode(newContents);
    SLNode* temp = head;
    SLNode* before = head;
            
    if(head == NULL || head->getContents() >= newContents)
    {
        delete newNode;
        insertHead(newContents);
    }
    else
    {
        while(temp->getContents() < newContents && temp->getNextNode() != NULL)
        {
            before = temp;
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
             if(temp != head)
            {
                before->setNextNode(newNode);
            }
            size++;
        }
    }
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
bool SList::removeFirst (int newContents)
{
    bool wasFound = false;
    SLNode* temp = head;
    SLNode* before = head;
        
    if(head == NULL)
    {
        wasFound = false;
    }
    else
    {
        if(head->getContents() == newContents)
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
                delete temp;
                wasFound = true;
                size--;
            }
        }
    }
    return wasFound;
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