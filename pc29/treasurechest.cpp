#include "treasurechest.h"

void TreasureChest::addItem (const Item& newItem)
{
    chest.push_back(newItem);
}
		
/*
 * Insert an item at the specified zero-indexed position in the chest.
 * If position is not valid for the chest, add the item to 
 * the end of the chest.
 * @param newItem the item to be inserted into the chest
 * @param position the zero-indexed position where the insertion
 *        is to take place
 */
void TreasureChest::insertItem (const Item& newItem, unsigned int position)
{
    chest.insert((chest.begin() + position), newItem);
}
		
const Item* TreasureChest::getItem (unsigned int position)
{
       if(position < chest.size())
       {
            return &chest[position];
       }
       else
        return NULL;
}
		
/*
 * Remove an item from the chest at a specified zero-indexed position.
 * @param position the zero-indexed position of the item
 * @return a copy of the Item removed from the chest
 * @throw string("ERROR: attempting remove at invalid position") if
 *        position is not valid
 */
Item TreasureChest::removeItem (unsigned int position) throw (string)
{
    if(position >= chest.size() )
    {
        throw string("ERROR: attempting remove at invalid position");
    }
    else
    {
        Item temp = chest[position];
        chest.erase(chest.begin() + position);
        return temp;
    }
}
		
/*
 * Clear the chest of all items.
 */
void TreasureChest::clear ()
{
    chest.clear();
}
		
/*
 * Check to see if the chest is empty.
 * @return true if the chest is empty, else false
 */
bool TreasureChest::empty () const
{
    return chest.empty();
}
		
/*
 * Get the size/number of items currently in the chest.
 * @return an unsigned integer containing the current size of the chest
 */
unsigned int TreasureChest::getSize () const
{
    return chest.size();
}
		
/*
 * Sort the items in the chest by name, using the sort function 
 * from the C++ standard algorithm library.
 */
void TreasureChest::sortByName ()
{
    sort(chest.begin(), chest.end(), compareItemsByName);
}
		
/*
 * Sort the items in the chest by value, using the sort function 
 * from the C++ standard algorithm library.
 */
void TreasureChest::sortByValue ()
{
    sort(chest.begin(), chest.end(), compareItemsByValue);
}
		
/*
 * Sort the items in the chest by quantity, using the sort function 
 * from the C++ standard algorithm library.
 */
void TreasureChest::sortByQuantity ()
{
    sort(chest.begin(), chest.end(), compareItemsByQuantity);
}
		
/*
 * Place the names of the items in the chest on the specified stream,
 * formatted as ITEM_NAME,ITEM_NAME,...ITEM_NAME
 */
ostream& operator<< (ostream& outs, const TreasureChest& src)
{
    if(src.getSize() > 0)
    {
        for(vector<Item>::const_iterator i = src.chest.begin(); i!=(src.chest.end() - 1); i++)
        {
            outs<< (*i).name << ",";
        }
        outs << (src.chest.end()-1)->name;
    }
        return outs;
}

/*
 * Compare two items by name.
 * @return true if lsrc.name < rsrc.name, else false
 */
bool compareItemsByName (const Item& lsrc, const Item& rsrc)
{
    return (lsrc.name<rsrc.name);
}

/*
 * Compare two items by value.
 * @return true if lsrc.value < rsrc.value, else false
 */
bool compareItemsByValue (const Item& lsrc, const Item& rsrc)
{
    return (lsrc.value<rsrc.value);
}

/*
 * Compare two items by quantity.
 * @return true if lsrc.quantity < rsrc.quantity, else false
 */
bool compareItemsByQuantity (const Item& lsrc, const Item& rsrc)
{
    return (lsrc.quantity<rsrc.quantity);
}