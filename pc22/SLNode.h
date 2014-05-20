
#include <iostream>
#include <sstream>
using namespace std;
template <class T>
class SLNode
{
  public:
    SLNode()
    :contents(0), nextNode(NULL){}
    SLNode(T newContents)
    {
        nextNode = NULL;
        contents = newContents;
    }
        
    ~SLNode()
    {
        nextNode = NULL;
    }

    void setContents (T newContents)
    {
        contents = newContents;
    }

    T getContents () const
    {
        return contents;
    }

    void setNextNode (SLNode<T>* newNode)
    {
        nextNode = newNode;
    }
	
    SLNode<T>* getNextNode () const
    {
        return nextNode;
    }
  
  private:
    T contents;
    SLNode<T>* nextNode;
  
  
    
};