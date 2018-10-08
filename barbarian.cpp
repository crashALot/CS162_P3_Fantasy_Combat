/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        08/05/18
** Description: This file contains the methods and functions required
*               to create and manipulate Vampire class objects. 
*               Derived class of Character parent class.
*********************************************************************/
#include "barbarian.hpp"

/********************************************************************* 
** Description: Barbarian::Barbarian()
*               Barbarian class default constructor
*********************************************************************/
Barbarian::Barbarian()
{
    setArmor(0);
    setAttack(2, 6);
    setDefense(2, 6);
    setStrength(12);
    setTitle("Barbarian");
}

/********************************************************************* 
** Description: int Barbarian::attacks()
*               Barbarian class attack function. References parent class
*               attack function as default action.    
*********************************************************************/
int Barbarian::attacks()
{
    return Character::attacks();
}

/********************************************************************* 
** Description: void Barbarian::defend(int attackIn)
*               Barabarian class defend function. References parent class
*               defend function as default action.
*********************************************************************/
void Barbarian::defend(int attackIn)
{
    Character::defend(attackIn);
}

/********************************************************************* 
** Description: Barbarian::~Barbarian()
*               Barbarian class destructor
*********************************************************************/
Barbarian::~Barbarian()
{
    
}