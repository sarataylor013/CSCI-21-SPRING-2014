#include "Word.h"

Word::Word()
{
    count = 1;
}
Word::Word(string newWord)
{
    word = newWord;
    count = 1;
}
Word::~Word()
{}
string Word::getWord() const
{
    return word;
}
void Word::setWord(string newWord)
{
    word = newWord;
}
unsigned int Word::getCount() const
{
    return count;
}
void Word::incrementCount()
{
    count++;
}
bool operator==(const Word leftSide,const Word rightSide)
{
    return (leftSide.word == rightSide.word);
}
bool operator< (const Word leftSide, const Word rightSide)
{
    return (leftSide.word < rightSide.word);
}
bool operator> (const Word leftSide, const Word rightSide)
{
    return (leftSide.word > rightSide.word);    
}
ostream& operator<<(ostream& os, const Word& myClass)
{
    os << myClass.word << " " << myClass.count;
    return os;
}