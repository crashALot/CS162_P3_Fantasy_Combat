/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        08/05/18
** Description: This file contains the methods and functions required
*               to create and manipulate Medusa class objects. 
*               Derived class of Character parent class.
*********************************************************************/
#include "medusa.hpp"
#include <iostream>
#include <iomanip>

/********************************************************************* 
** Description: Medusa::Medusa()
*               Medusa class default constructor
*********************************************************************/
Medusa::Medusa()
{
    setArmor(3);
    setAttack(2, 6);
    setDefense(1, 6);
    setStrength(8);
    setTitle("Medusa");
}

/********************************************************************* 
** Description: int Medusa::attacks() 
*               Medusa class attack function. If 2 dice are rolled 
*               totalling a total attack of 12, this function passes
*               a large integer to guarantee ending the opponent.
*********************************************************************/
int Medusa::attacks() 
{
    int attack[2], totalAttack=0;
    for (int i=0; i<this->getAttackDice(); i++)
    {
        attack[i]=(this->getAttackSides()*randomGenerator())+1;
        totalAttack+=attack[i];
    }
    // Medusa's special ability, glare, is just an overpowered attack
    if (totalAttack==12)
    {
        std::cout << "STONE               |            XXX" << std::endl;
        std::cout << std::endl;
        std::cout << "** Medusa has attacked with all her strength, she glares at her opponent turning them to stone! They never had a chance!" ;
        std::cout << std::endl;
        std::cout << "Dice Roll:            ";
        totalAttack=1000;
    }
    for (int i=0; i<2; i++)
    {
        std::cout << std::setw(2) << attack[i] << "  ";
        if (i+1==this->getAttackDice())
        {
            std::cout << std::right << std::setw(11+i*2) << "|";
        }
    }
    return totalAttack;
}

/********************************************************************* 
** Description: void Medusa::defend(int attackIn)
*               Medusa class defend function. References parent class
*               defend function as default action.
*********************************************************************/
void Medusa::defend(int attackIn)
{
    Character::defend(attackIn);
}

/********************************************************************* 
** Description: Medusa::~Medusa()
*               Medusa class destructor
*********************************************************************/
Medusa::~Medusa()
{
    
}