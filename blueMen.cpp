/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        08/05/18
** Description: This file contains the methods and functions required
*               to create and manipulate BlueMen class objects. 
*               Derived class of Character parent class.
*********************************************************************/
#include "blueMen.hpp"
#include <iostream>

/********************************************************************* 
** Description: BlueMen::BlueMen()
*               
*********************************************************************/
BlueMen::BlueMen()
{
    setArmor(3);
    setAttack(2, 10);
    setDefense(3, 6);
    setStrength(12);
    setTitle("Blue Men");
    haveDied=0;
}

/********************************************************************* 
** Description: int BlueMen::attacks()
*               BlueMen class attack function. References parent class
*               attack function as default action.   
*********************************************************************/
int BlueMen::attacks()
{
    return Character::attacks();
}

/********************************************************************* 
** Description: void BlueMen::defend(int attackIn)
*               BlueMen class defend function. Takes input from 
*               opposing players attack function and calculates
*               damage inflicted. BlueMen class includes special 
*               move reduces defense die count by 1 for every 4 points
*               of damage.
*********************************************************************/
void BlueMen::defend(int attackIn)
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
        this->setStrength(this->getStrength()+(totalDefense-attackIn));
        // The following if-statements determine if the character has taken greater than 4 damage, and whether or not it means losing a defense die
        if (this->getStrength()<=8)
        {
            if (haveDied==0)
            {
                this->setDefense(2,6);
                std::cout << " " << std::endl;
                std::cout << "** "<< "Blue men have fallen! The loss of 1 soul means blue men can only defend 2 times from now on!" << std::endl;
                std::cout << " " << std::endl;
                haveDied=1; 
            }
        }
        if (this->getStrength()<=4)
        {

            if (haveDied==1)
            {
                this->setDefense(1,6);
                std::cout << " " << std::endl;
                std::cout << "** " << "Blue men have fallen! The loss of another soul means blue men can only defend 1 time from now on!" << std::endl;
                std::cout << " " << std::endl;
                haveDied=2;
            }
        }
        this->setInflicted(attackIn-totalDefense);
    }
}

/********************************************************************* 
** Description: BlueMen::~BlueMen()
*               BlueMen class destructor
*********************************************************************/
BlueMen::~BlueMen()
{
    
}