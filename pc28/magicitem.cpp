#include "magicitem.h"

MagicItem::MagicItem(string newName, unsigned int newValue, string newDescription, unsigned int newMana)
:Item(newName, newValue), description(newDescription), manaRequired(newMana)
{}
MagicItem::~MagicItem()
{}
	
void MagicItem::setDescription(string newDescription)
{
    description = newDescription;
}
void MagicItem::setManaRequired(unsigned int newMana)
{
    manaRequired = newMana;
}

string MagicItem::getDescription()
{
    return description;
}
unsigned int MagicItem::getManaRequired()
{
    return manaRequired;
}
	
string MagicItem::toString()
{
    stringstream ss;
    ss <<Item::toString() << ", " << description << ", requires " << manaRequired << " mana";
    return ss.str();
}
