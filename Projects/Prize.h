#pragma once

#include <string>
using namespace std;

class Prize
{
    public:
        /*
         *  Default Constructor. Sets prizeName to "NO NAME" and prizeValue to 0
         */
        Prize();
        
        /*
         * Overloaded Constructor.
         * @param itemName string containing the name of the prize
         * @param itemValue an unsigned int containing the value of the prize
         */
        Prize(string itemName, unsigned int itemValue);
        
        /*
         * Destructor: empty
         */
        ~Prize();
        
        /*
         * Overloads the == operator to compare the name and value of two prize objects
         * @param prizeOne a Prize to be compared
         * @param prizeTwo a Prize to be compared
         * @return a bool; returns true if name and value of both objects match
         */
        friend bool operator==(const Prize &prizeOne, const Prize &prizeTwo);
        
        /*
         * Get a Prize's value
         * @return an unsigned int containing this Prize's value
         */
        unsigned int getPrizeValue();
        
        /*
         * Set a Prize's value
         * @param newValue unsigned int containing the new value for the Prize
         */
        void setPrizeValue(unsigned int newValue);
        
        /*
         * Get a Prize's name
         * @return a string containing this Prize's name
         */
        string getPrizeName() const;
        
        /*
         * Set a Prize's name
         * @param newName string containing the new name for the Prize
         */
        void setPrizeName(string newName);

    
    private:
        string prizeName;
        unsigned int prizeValue;
};

