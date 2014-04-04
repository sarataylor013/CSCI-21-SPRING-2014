#include "Prize.h"

Prize::Prize()
{
   prizeName = "NO NAME";
   prizeValue = 0;
}

Prize::Prize(string itemName, unsigned int itemValue)
{
    prizeName = itemName;
   prizeValue = itemValue;
    
}

Prize::~Prize()
{}

bool operator==(const Prize &prizeOne, const Prize &prizeTwo)
{
    if(prizeOne.prizeValue == prizeTwo.prizeValue && prizeOne.prizeName == prizeTwo.prizeName)
    {
      return true;  
    }
    return false;
  
}
  
unsigned int Prize::getPrizeValue()
{
    return prizeValue;
}

void Prize::setPrizeValue(unsigned int newValue)
{
    prizeValue = newValue;
}

string Prize::getPrizeName() const
{
    return prizeName;
}

void Prize::setPrizeName(string newName)
{
    prizeName = newName;
}