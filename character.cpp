/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        08/05/18
** Description: This file contains the methods and functions required
*               to create and manipulate Character class objects. 
*               Base class of several sub-characters. Includes several
*               virtual functions utilizing polymorphism to include
*               virtual destructor.
*********************************************************************/
#include "character.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

/********************************************************************* 
** Description: Character::Character()
*               Character class default constructor
*********************************************************************/
Character::Character()
{
    attack[Dice]=-1;
    attack[Sides]=-1;
    defense[Dice]=-1;
    defense[Sides]=-1;
    armor=-1;
    strength=-1;
    title="NA";
    inflicted=0;
}

/********************************************************************* 
** Description: double Character::randomGenerator()
*               Return value between 0 and 1 for use with other 
*               functions
*********************************************************************/
double Character::randomGenerator()
{
    return (static_cast<double>(rand())/static_cast<double>(RAND_MAX));
}

/********************************************************************* 
** Description: int Character::attacks()
*               Default attack function used by characters in game.
*********************************************************************/
int Character::attacks()
{
    int singleAttack, totalAttack=0;
    for (int i=0; i<this->getAttackDice(); i++)
    {
        singleAttack=(this->getAttackSides()*randomGenerator())+1;
        std::cout << std::setw(2) << singleAttack << "  ";
        totalAttack+=singleAttack;
        if (i+1==this->getAttackDice())
        {
            int space=17-(i*4);
            std::cout << std::right << std::setw(space) << "|";
        }
    }
    return totalAttack;
}

/********************************************************************* 
** Description: void Character::defend(int attackIn)
*               Default defend function used by characters in game.
*********************************************************************/
void Character::defend(int attackIn)
{
    int singleDefense, totalDefense=0;
    std::cout << "            ";
    // Calculate defense dice rolls
    for (int i=0; i<this->getDefenseDice(); i++)
    {
        singleDefense=(this->getDefenseSides()*randomGenerator())+1;
        std::cout << singleDefense << "   ";
        totalDefense+=singleDefense;
    }    
    std::cout << std::endl;
    // Compute total defense, to include armor   
    totalDefense=totalDefense+this->getArmor();
    // Update character stats
    if ((attackIn-totalDefense)<0)
    {
        this->setInflicted(0);
    }
    else
    {
        this->setStrength(this->getStrength()+totalDefense-attackIn);
        this->setInflicted(attackIn-totalDefense);
    }
}

/********************************************************************* 
** Description: Set and Get functions.
*               Character class mutators and accessors. Allow the user
*               to manipulate instances of Character class.
*********************************************************************/
void Character::setAttack(int diceIn, int sidesIn)
{
    attack[Dice]=diceIn;
    attack[Sides]=sidesIn;
}

void Character::setDefense(int diceIn, int sidesIn)
{
    defense[Dice]=diceIn;
    defense[Sides]=sidesIn;
}

void Character::setArmor(int armorIn)
{
    armor=armorIn;
}

void Character::setStrength(int strengthIn)
{
    strength=strengthIn;
}

void Character::setTitle(std::string nameIn)
{
    title=nameIn;
}

void Character::setInflicted(int inflictedIn)
{
    inflicted=inflictedIn;
}

std::string Character::getTitle()
{
    return title;
}

int Character::getAttackDice()
{
    return attack[Dice];
}

int Character::getAttackSides()
{
    return attack[Sides];
}

int Character::getDefenseDice()
{
    return defense[Dice];
}

int Character::getDefenseSides()
{
    return defense[Sides];
}

int Character::getArmor()
{
    return armor;
}

int Character::getStrength()
{
    return strength;
}

int Character::getInflicted()
{
    return inflicted;
}

/********************************************************************* 
** Description: Character::~Character()
*               Character class destructor
*********************************************************************/
Character::~Character()
{
    
}