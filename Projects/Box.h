#pragma once

#include <string>
#include "Prize.h"
using namespace std;

class Box
{
   public:
    /*
     *  Default Constructor. Sets boxNumber = 0, boxColor = "NO COLOR", prizeCapacity = 5
     * prizeCount = 0, prizes array initialized to match prizeCapacity 
     */
    Box();
    
    /*
     *  Overloaded Constructor. Sets boxNumber = newBoxNumber, boxColor = newBoxColor, 
     * prizeCapacity = newPrizeCapacity
     * prizeCount = 0, prizes array initialized to match prizeCapacity 
     */
    Box(unsigned int newBoxNumber, string newBoxColor, unsigned int newPrizeCapacity);
    
    /*
     * Destructor: free memory associated with prizes
     */
    ~Box();
    
    /*
     * Sets the boxColor private member variable
     * @param newBoxColor a string to replace the current boxColor
     */
    void setBoxColor(string newBoxColor);
    
    /*
     * Gets the box's color
     * @return a string containing the box's color
     */
    string getBoxColor();
    
    /*
     * Sets the boxNumber private member variable
     * @param newBoxNumber an unsigned int to replace the current boxNumber
     */
    void setBoxNumber(unsigned int newBoxNumber);
    
    /*
     * Gets the box's number
     * @return an unsigned int containing the box's number
     */
    unsigned int getBoxNumber();
    
    /*
     * Gets the Prize Capacity
     * @return an Unsigned int containing the max capacity
     */
    unsigned int getPrizeCapacity();
    
    /*
     * Gets the current number of prizes in the box
     * @return unsigned int containing the number of prizes in the box
     */
    unsigned int getPrizeCount();
    
    /*
     * Adds a new prize the the Prize array
     * @returns true if the addition was successful
     */
    bool addPrize(Prize newPrize);
    
    /*
     * returns a prize at a specific index
     * @param the index of the prize you want to get
     * @return a Prize contained at the index, returns scratch if the index is invalid
     */
    Prize& getPrize(unsigned int index);
    
    /*
     * removes a prize at a specific index
     * @param the index of the prize you want to remove
     * @return a Prize contained at the index, returns scratch if the index is invalid
     */
    Prize removePrize(unsigned int index);
   
   private:
    unsigned int boxNumber;
    unsigned int prizeCapacity;
    unsigned int prizeCount;
    string boxColor;
    Prize scratch;
    Prize* prizes;
};
