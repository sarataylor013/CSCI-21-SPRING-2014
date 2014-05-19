#pragma once

#include "item.h"
#include <sstream>
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;
class MagicItem  : public Item
{
  public:
    MagicItem(string newName = "magicitem", unsigned int newValue = 0, string newDescription = "no description", unsigned int newMana = 0);
	virtual ~MagicItem();
	
	void setDescription(string newDescription);
	void setManaRequired(unsigned int newMana);

	string getDescription();
	unsigned int getManaRequired();
	
	string toString();
  
  private:
    string description;
	unsigned int manaRequired;
};