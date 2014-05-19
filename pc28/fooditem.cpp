#include "fooditem.h"

FoodItem::FoodItem(string newName, unsigned int newValue, unsigned int newCalories, string newUnitOfMeasure, float newUnits)
:Item(newName, newValue), calories(newCalories), unitOfMeasure(newUnitOfMeasure), units(newUnits)
{}
	                 
FoodItem::~FoodItem()
{}
	
void FoodItem::setCalories(unsigned int newCalories)
{
    calories = newCalories;
}
void FoodItem::setUnitOfMeasure(string newUnitOfMeasure)
{
    unitOfMeasure = newUnitOfMeasure;
}
void FoodItem::setUnits(float newUnits)
{
    units = newUnits;
}

unsigned int FoodItem::getCalories()
{
    return calories;
}
string FoodItem::getUnitOfMeasure()
{
    return unitOfMeasure;
}
float FoodItem::getUnits()
{
    return units;
}
	
string FoodItem::toString()
{
    stringstream ss;
    ss <<Item::toString() << ", " << setprecision(2) << fixed << units << " " << unitOfMeasure << ", " << calories << " calories";
    return ss.str();
}