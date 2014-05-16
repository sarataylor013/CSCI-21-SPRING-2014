#pragma once

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Word
{
    public:
        /*
         * Default constructor; sets count to 1
         */
        Word();
        
        /*
         * Overloaded constructor; word = newWord and count = 1
         * @param newWord sets word member variable
         */
        Word(string newWord);
        
        /*
         * Default destructor. Does Nothing
         */
        virtual ~Word();
        
        /*
         * Returns word member variable
         * @return a string containing the word
         */
        string getWord() const;
        
        /*
         * Sets the word member variable
         * @param newWord a string containing the new value for word
         */
        void setWord(string newWord);
        
        /*
         * returns the value of count
         * @return an unsigned int containing count
         */
        unsigned int getCount() const;
        
        /*
         * Increases count by one
         */
        void incrementCount();
        
        /*
         * Overloads the == operator to compare the string word of two Word objects
         * @param leftSide a Word to be compared
         * @param rightSide a Word to be compared
         * @return a bool; returns true if the word member variable of both objects match
         */
        friend bool operator==(const Word leftSide, const Word rightSide);
        
        /*
         * Overloads the < operator to compare the string word of two Word objects
         * @param leftSide a Word to be compared
         * @param rightSide a Word to be compared
         * @return a bool; returns true if the leftSide is < the rightSide
         */
        friend bool operator< (const Word leftSide, const Word rightSide);
        
        /*
         * Overloads the > operator to compare the string word of two Word objects
         * @param leftSide a Word to be compared
         * @param rightSide a Word to be compared
         * @return a bool; returns true if the leftSide is > the rightSide
         */
        friend bool operator> (const Word leftSide, const Word rightSide);
        
        /*
         * Overloads the << operator to display the contents of Word objects
         * Displays as "WORD COUNT" where WORD is member vaiable word and 
         * COUNT is member vaiable count
         * @param os stream << outputs to
         * @param myClass a Word to be displayed
         * @return a ostream&; to be sent to output stream such as std::cout
         */
        friend ostream& operator<<(ostream& os, const Word& myClass);

    private:
        string word;
        unsigned int count;
};
/*
data members: word (string), count (unsigned int)
Word () : count to 1
Word (string newWord) : initialize word to newWord, count to 1
virtual ~Word () : nothing to be done
string getWord () const
void setWord (string newWord)
unsigned int getCount () const
void incrementCount () : add 1 to count
operator== (make sure this is case-insensitive)
operator< (make sure this is case-insensitive)
operator> (make sure this is case-insensitive)
operator<< : place contents of Word formatted as "WORD COUNT" on the stream
*/