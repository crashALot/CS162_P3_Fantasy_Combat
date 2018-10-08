/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        08/05/18
** Description: This file contains the methods and functions required
*               to create and manipulate Vampire class objects. 
*               Derived class of Character parent class.
*********************************************************************/
#include "vampire.hpp"
#include <iostream>

/********************************************************************* 
** Description: Vampire::Vampire()
*               Vampire class default constructor
*********************************************************************/
Vampire::Vampire()
{
    setArmor(1);
    setAttack(1, 12);
    setDefense(1, 6);
    setStrength(18);
    setTitle("Vampire");
    smoothOperator=0;
}

/********************************************************************* 
** Description: int Vampire::attacks()
*               Vampire class attack function. References parent class
*               attack function as default action.
*********************************************************************/
int Vampire::attacks()
{
    return Character::attacks();
}

/********************************************************************* 
** Description: void Vampire::defend(int attackIn)
*               Vampire class defend function. Takes input from 
*               opposing players attack function and calculates
*               damage inflicted. Vampire class includes special 
*               move that avoids damage from attack
*********************************************************************/
void Vampire::defend(int attackIn)
{
    int singleDefense, smoothOperator, totalDefense=0;
    smoothOperator=2*randomGenerator();
    // 50% chance opponent's attack does no damage
    if (smoothOperator)
    {
        std::cout << std::endl << " " ;
        std::cout << std::endl << "** "<< this->getTitle() << " has charmed their opponent senseless! They take no damage this turn." << std::endl;
        std::cout << " " << std::endl;
        return;
    }
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
        this->setStrength(this->getStrength()-(attackIn-totalDefense));
        this->setInflicted(attackIn-totalDefense);
    }
}

/********************************************************************* 
** Description: Vampire::~Vampire()
*               Vampire class destructor
*********************************************************************/
Vampire::~Vampire()
{
    
}