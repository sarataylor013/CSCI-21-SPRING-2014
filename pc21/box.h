#pragma once

#include <iostream>
#include <sstream>
using namespace std;
template <class T>
class Box
{
    public:
        Box(T newContents)
        :contents(newContents){}
        T getContents() const
        {return contents;}
        void setContents(T newContents)
        {contents = newContents;}
        friend ostream& operator<<(ostream& os, const Box& myClass)
        {   os << myClass.getContents();
            return os;}
    
    private:
        T contents;
};