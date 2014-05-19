#include "Box.h"
#include "Prize.h"

#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/* for unit testing -- do not alter */
template <typename X, typename A>
void btassert(A assertion);
void unittest ();

void prizeTest();
void boxTest();

//
// Grader comments 2014.04.11
// Passes 11 of 30 tests before crashing.
// Deducted 190 points
//
int main()
{
    bool isDone = false;
    int input = 5;
    while(!isDone)
    {
        cout<<"[1] TEST PRIZE CLASS\n";
        cout<<"[2] TEST BOX CLASS\n";
        cout<<"[3] Run Official Unit Test\n";
        cout<<"[0] QUIT\n";
        cin >> input;
        
        switch(input){
            case 1:
                prizeTest();
            break;
            case 2:
                boxTest();
            break;
            case 3:
                unittest();
                isDone = true;
            break;
            case 0:
                isDone = true;
            break;
            default:
                cout << "NOT Valid Input\n";
        }
    }
    return 0;
}

void prizeTest()
{
    Prize prizeOne, prizeTwo;
    char answer;
    bool isDone = false;
    string newName;
    int input;
    int newValue = 0;
    while(!isDone)
    {
        cout<<"[1] Prize Name\n";
        cout<<"[3] Set Value\n";
        cout<<"[4] Compare\n";
        cout<<"[0] QUIT\n";
        cin >> input;
        
        switch(input){
            case 1:
                cout << "Prize name: " << prizeOne.getPrizeName();
                cout << "Update (y/n)? ";
                cin >> answer;
                if(answer == 'y')
                {
                    cout << "Enter new prize name: ";
                    cin.ignore(256, '\n');
                    getline(cin, newName);
                    prizeOne.setPrizeName(newName);
                    cout << "Prize name updated.";
                }

            break;
            case 3:
                cout << "Input Value: ";
                cin >> newValue;
                prizeOne.setPrizeValue(newValue);
            break;
            case 4:
                if(prizeOne == prizeTwo)
                    cout << "The Prizes are the same";
                else
                    cout << "They are different";
            break;
            case 0:
                isDone = true;
            break;
            default:
                cout << "NOT Valid Input\n";
        }
        cout << "\nPrize One: " << prizeOne.getPrizeName() << " Value: " << prizeOne.getPrizeValue() << endl;
        cout << "Prize Two: " << prizeTwo.getPrizeName() << " Value: " << prizeTwo.getPrizeValue() << endl;
    }
}

//
// Grader comments 2014.04.11
// No unit test for box class
// Deducted 90 points
//
void boxTest()
{
    Box box1;
    Prize newPrize;
    string name = "NO NAME";
    int value = 0;
    bool isDone = false;
    unsigned int input;
    char userChoice = 'n';
    string newColor = "NO COLOR";
    
    while(!isDone)
    {
        cout<<"\n\nBox Test\n\n";
        cout<<"Box info -> "<<box1.getBoxNumber()<<", "<<box1.getBoxColor()<<endl;
        cout<<"[1] Add prize\n";
        cout<<"[2] View prizes (using getPrize)\n";
        cout<<"[3] Remove prize\n";
        cout<<"[4] Box number\n";
        cout<<"[5] Box color\n";
        cout<<"[6] View prize capacity\n";
        cout<<"[7] View prize count\n";
        cout<<"[0] Back to main menu\n";
        cout<<"your choice:";
        cin >> input;
        
        switch(input){
            case 1:
                cout<<"Prize name (current = \"NO NAME\"): ";
                cin>>name;
                cout<<"Prize value (current = 0): ";
                cin>>value;
                newPrize.setPrizeName(name);
                newPrize.setPrizeValue(value);
                if(box1.addPrize(newPrize))
                    cout<<"New prize added.\n\n";
                else
                    cout<<"Unable to add new prize.\n\n";
            break;
            case 2:
                for(unsigned int i = 0; i < box1.getPrizeCount(); ++i)
                {
                    cout << (i+1) << ": " << box1.getPrize(i).getPrizeName() << endl;
                }
            break;
            case 3:
                for(unsigned int i = 0; i < box1.getPrizeCount(); ++i)
                {
                    cout << (i+1) << ": " << box1.getPrize(i).getPrizeName() << endl;
                }
                cout << "\n Remove which prize (0 to cancel)?";
                cin >> input;
                if(input != 0)
                {
                    input -= 1;
                    box1.removePrize(input);
                }
            break;
            case 4:
                cout << "Box number: " << box1.getBoxNumber() << endl;
                cout << "Update (y/n)?";
                cin >> userChoice;
                if(userChoice == 'y')
                {
                    cout << "Enter new box number: ";
                    cin >> input;
                    box1.setBoxNumber(input);
                    cout << "Box number: " << box1.getBoxNumber() << endl;
                }
            break;
            case 5:
                cout << "Box color: " << box1.getBoxColor() << endl;
                cout << "Update (y/n)?";
                cin >> userChoice;
                if(userChoice == 'y')
                {
                    cout << "Enter new box color: ";
                    cin >> newColor;
                    box1.setBoxColor(newColor);
                    cout << "Box color: " << box1.getBoxColor() << endl;
                }
            break;
            case 6:
                cout << "Box prize capacity: " << box1.getPrizeCapacity();
            break;
            case 7:
                cout << "Box prize count: " << box1.getPrizeCount();
            break;
            case 0:
                isDone = true;
            break;
            default:
                cout<< "Not Valid Input\n";
        }
    }
}

/*
 * Unit testing functionb1. Do not alter.
 */

void unittest ()
{
    cout << "\nSTARTING UNIT TEST\n\n";
	
    Box b1;
    Box b2(42, "blue", 3);
	
    cout << "** TESTING DEFAULT BOX **\n\n";
	
    try {
        btassert<bool>(b1.getBoxNumber() == 0);
        cout << "Passed TEST 1: Box getBoxNumber()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 1 Box getBoxNumber() #\n";
    }
	
    try {
        btassert<bool>(b1.getBoxColor() == "NO COLOR");
        cout << "Passed TEST 2: Box getBoxColor()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 2 Box getBoxColor() #\n";
    }
    
    try {
        btassert<bool>(b1.getPrizeCapacity() == 5);
        cout << "Passed TEST 3: Box getPrizeCapacity()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 3 Box getPrizeCapacity() #\n";
    }
	
    try {
        btassert<bool>(b1.getPrizeCount() == 0);
        cout << "Passed TEST 4: Box getPrizeCount()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 4 Box getPrizeCount() #\n";
    }
	
    b1.setBoxNumber(99);
    try {
        btassert<bool>(b1.getBoxNumber() == 99);
        cout << "Passed TEST 5: Box setBoxNumber()/getBoxNumber()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 5 Box setBoxNumber()/getBoxNumber() #\n";
    }
	
    b1.setBoxColor("red");
    try {
        btassert<bool>(b1.getBoxColor() == "red");
        cout << "Passed TEST 6: Box setBoxColor()/getBoxColor()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 6 Box setBoxColor()/getBoxColor() #\n";
    }
    
    cout << "\n** TESTING CUSTOM BOX **\n\n";
	
    try {
        btassert<bool>(b2.getBoxNumber() == 42);
        cout << "Passed TEST 7: Box getBoxNumber()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 7 Box getBoxNumber() #\n";
    }
	
    try {
        btassert<bool>(b2.getBoxColor() == "blue");
        cout << "Passed TEST 8: Box getBoxColor()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 8 Box getBoxColor() #\n";
    }
    
    try {
        btassert<bool>(b2.getPrizeCapacity() == 3);
        cout << "Passed TEST 9: Box getPrizeCapacity()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 9 Box getPrizeCapacity() #\n";
    }
	
    try {
        btassert<bool>(b2.getPrizeCount() == 0);
        cout << "Passed TEST 10: Box getPrizeCount()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 10 Box getPrizeCount() #\n";
    }
	
    try {
        btassert<bool>(b2.getPrize(0) == Prize());
        cout << "Passed TEST 11: Box getPrize(0)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 11 Box getPrize(0) #\n";
    }
	
    try {
        btassert<bool>(b2.removePrize(0) == Prize());
        cout << "Passed TEST 12: Box removePrize(0)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 12 Box removePrize(0) #\n";
    }
    
    b2.addPrize(Prize("BRONZE PRIZE", 1));
    try {
        btassert<bool>(b2.getPrizeCount() == 1);
        cout << "Passed TEST 13: Box addPrize()/getPrizeCount()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 13 Box addPrize()/getPrizeCount() #\n";
    }
    
    b2.addPrize(Prize("SILVER PRIZE", 100));
    try {
        btassert<bool>(b2.getPrizeCount() == 2);
        cout << "Passed TEST 14: Box addPrize()/getPrizeCount()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 14 Box addPrize()/getPrizeCount() #\n";
    }
        
    b2.addPrize(Prize("GOLD PRIZE", 1000));
    try {
        btassert<bool>(b2.getPrizeCount() == 3);
        cout << "Passed TEST 15: Box addPrize()/getPrizeCount()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 15 Box addPrize()/getPrizeCount() #\n";
    }
    
    try {
        btassert<bool>(b2.addPrize(Prize("DIAMOND PRIZE", 999)) == false);
        cout << "Passed TEST 16: Box addPrize(ARRAY FULL)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 16 Box addPrize(ARRAY FULL) #\n";
    }
	
    try {
        btassert<bool>(b2.getPrize(1) == Prize("SILVER PRIZE", 100));
        cout << "Passed TEST 17: Box getPrize(1)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 17 Box getPrize(1) #\n";
    }
	
    try {
        btassert<bool>(b2.removePrize(2) == Prize("GOLD PRIZE", 1000));
        cout << "Passed TEST 18: Box removePrize(2)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 18 Box removePrize(2) #\n";
    }
    
    try {
        btassert<bool>(b2.getPrizeCount() == 2);
        cout << "Passed TEST 19: Box getPrizeCount()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 19 Box getPrizeCount() #\n";
    }
	
    try {
        btassert<bool>(b2.removePrize(2) == Prize());
        cout << "Passed TEST 20: Box removeCargo(2)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 20 Box removeCargo(2) #\n";
    }
	
    try {
        btassert<bool>(b2.getPrize(2) == Prize());
        cout << "Passed TEST 21: Box getPrize(2)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 21 Box getPrize(2) #\n";
    }
	
    try {
        btassert<bool>(b2.addPrize(Prize("RUBY PRIZE", 9999)) == true);
        cout << "Passed TEST 22: Box addPrize(\"RUBY PRIZE\", 9999)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 22 Box addPrize(\"RUBY PRIZE\", 9999) #\n";
    }
    
    try {
        btassert<bool>(b2.getPrizeCount() == 3);
        cout << "Passed TEST 23: Box getPrizeCount()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 23 Box getPrizeCount() #\n";
    }
	
    try {
        btassert<bool>(b2.getPrizeCapacity() == 3);
        cout << "Passed TEST 24: Box getPrizeCapacity()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 24 Box getPrizeCapacity() #\n";
    }
	
    cout << "\n** TESTING PRIZE **\n\n";
	
    Prize p1;
	
    try {
        btassert<bool>(p1.getPrizeName() == "NO NAME");
        cout << "Passed TEST 25: Prize getPrizeName()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 25 Prize getPrizeName() #\n";
    }
	
    try {
        btassert<bool>(p1.getPrizeValue() == 0);
        cout << "Passed TEST 26: Prize getPrizeValue()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 26 Prize getPrizeValue() #\n";
    }
	
    p1.setPrizeName("FOOD PRIZE");
    try {
        btassert<bool>(p1.getPrizeName() == "FOOD PRIZE");
        cout << "Passed TEST 27: Prize setPrizeName(\"FOOD PRIZE\")/getPrizeName()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 27 Prize setPrizeName(\"FOOD PRIZE\")/getPrizeName() #\n";
    }
	
    p1.setPrizeValue(17);
    try {
        btassert<bool>(p1.getPrizeValue() == 17);
        cout << "Passed TEST 28: Prize setPrizeValue(17)/getPrizeValue()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 28 Prize setPrizeValue(17)/getPrizeValue() #\n";
    }
	
    Prize p2("HAT PRIZE", 50);
	
    try {
        btassert<bool>(p2.getPrizeName() == "HAT PRIZE");
        cout << "Passed TEST 29: Prize getPrizeName()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 29 Prize getPrizeName() #\n";
    }
	
    try {
        btassert<bool>(p2.getPrizeValue() == 50);
        cout << "Passed TEST 30: Prize getPrizeValue()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 30 Prize getPrizeValue() #\n";
    }
    
    try {
        btassert<bool>(!(p1 == p2));
        cout << "Passed TEST 31: !(Prize == Prize)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 31 !(Prize == Prize) #\n";
    }
    
    p2.setPrizeName("FOOD PRIZE");
    try {
        btassert<bool>(p2.getPrizeName() == "FOOD PRIZE");
        cout << "Passed TEST 32: Prize setPrizeName(\"FOOD PRIZE\")/getPrizeName()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 32 Prize setPrizeName(\"FOOD PRIZE\")/getPrizeName() #\n";
    }
	
    p2.setPrizeValue(17);
    try {
        btassert<bool>(p2.getPrizeValue() == 17);
        cout << "Passed TEST 33: Prize setPrizeValue(17)/getPrizeValue()\n";
    } catch (bool b) {
        cout << "# FAILED TEST 33 Prize setPrizeValue(17)/getPrizeValue() #\n";
    }
    
    try {
        btassert<bool>(p1 == p2);
        cout << "Passed TEST 34: (Prize == Prize)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 34 (Prize == Prize) #\n";
    }
    
    p2.setPrizeValue(1);
    try {
        btassert<bool>(!(p1 == p2));
        cout << "Passed TEST 35: !(Prize == Prize)\n";
    } catch (bool b) {
        cout << "# FAILED TEST 35 !(Prize == Prize) #\n";
    }
	
    cout << "\nUNIT TEST COMPLETE\n\n";
}

template <typename X, typename A>
void btassert (A assertion)
{
    if (!assertion)
        throw X();
}