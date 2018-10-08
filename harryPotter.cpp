/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        08/05/18
** Description: This file contains the methods and functions required
*               to create and manipulate HarryPotter class objects. 
*               Derived class of Character parent class.
*********************************************************************/
#include "harryPotter.hpp"
#include <iostream>

/********************************************************************* 
** Description: HarryPotter::HarryPotter()
*               HarryPotter class default constructor
*********************************************************************/
HarryPotter::HarryPotter()
{
    setArmor(0);
    setAttack(2, 6);
    setDefense(2, 6);
    setStrength(10);
    setTitle("Harry Potter");
    hasDied=false;
}

/********************************************************************* 
** Description: int HarryPotter::attacks()
*               HarryPotter class attack function. References parent class
*               attack function as default action. 
*********************************************************************/
int HarryPotter::attacks()
{
    return Character::attacks();
}

/********************************************************************* 
** Description: void HarryPotter::defend(int attackIn)
*               HarryPotter class defend function. Takes input from 
*               opposing players attack function and calculates
*               damage inflicted. HarryPotter class includes special 
*               move wherein HarryPotter instance is revived once 
*               after losing all health
*********************************************************************/
void HarryPotter::defend(int attackIn)
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
        // The below if-statement is Harry's special ability, he can die once and be revived with greater strength
        if (this->getStrength()<=0 && hasDied==false)
        {
            this->setStrength(20);
            std::cout << std::endl;
            std::cout << "**  " << this->getTitle() << " can not be killed so easily! He rises from the ashes stronger than before!" << std::endl;
            std::cout <<  "** " << " His strength has grown to 20!" << std::endl;
            std::cout << std::endl;
            hasDied=true;
        }
        this->setInflicted(attackIn-totalDefense);
    }
}

/********************************************************************* 
** Description: HarryPotter::~HarryPotter()
*               HarryPotter class destructor
*********************************************************************/
HarryPotter::~HarryPotter()
{
    
}