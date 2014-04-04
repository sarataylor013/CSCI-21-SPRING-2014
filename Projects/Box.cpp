#include "Box.h"

Box::Box()
{
    boxNumber = 0;
    prizeCapacity = 5;
    prizeCount = 0;
    boxColor = "NO COLOR";
    Prize scratch;
    prizes = new Prize[prizeCapacity];
}
Box::Box(unsigned int newBoxNumber, string newBoxColor, unsigned int newPrizeCapacity)
{
    boxNumber = newBoxNumber;
    prizeCapacity = newPrizeCapacity;
    prizeCount = 0;
    boxColor = newBoxColor;
    Prize scratch;
    prizes = new Prize[prizeCapacity];
}
Box::~Box()
{
    delete [] prizes;
    prizes = NULL;
}
void Box::setBoxColor(string newBoxColor)
{
    boxColor = newBoxColor;
}
string Box::getBoxColor()
{
    return boxColor;
}
void Box::setBoxNumber(unsigned int newBoxNumber)
{
    boxNumber = newBoxNumber;
}
unsigned int Box::getBoxNumber()
{
    return boxNumber;
}
unsigned int Box::getPrizeCapacity()
{
    return prizeCapacity;
}
unsigned int Box::getPrizeCount()
{
    return prizeCount;
}
bool Box::addPrize(Prize newPrize)
{
    if(prizeCount < prizeCapacity)
    {
        prizes[prizeCount++] = newPrize;
        return true;
    }
    else
        return false;
}
Prize& Box::getPrize(unsigned int index)
{
    return prizes[index];
}
Prize Box::removePrize(unsigned int index)
{
    if(index > prizeCount)
        return scratch;
    Prize returnItem = prizes[index];
    prizes[index] = scratch;
    --prizeCount;
    for(unsigned int i = index; i < prizeCount; ++i)
    {
        prizes[i] = prizes[i+1];
    }

    return returnItem;
}