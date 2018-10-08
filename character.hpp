/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        08/05/18
** Description: This file contains the associated prototypes and 
*               interfaces needed to use Character class objects.
*               Base class for multiple other classes.
*********************************************************************/
#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <string>

enum roll {Dice, Sides};

class Character
{
private:

    int attack[2], defense[2], armor, strength, inflicted;
    std::string title;

public:

    Character();
    double randomGenerator();
    virtual int attacks();
    virtual void defend(int);
    void setAttack(int, int);
    void setDefense(int, int);
    void setArmor(int);
    void setStrength(int);
    void setTitle(std::string);
    void setInflicted(int);
    std::string getTitle();
    int getAttackDice();
    int getAttackSides();
    int getDefenseDice();
    int getDefenseSides();
    int getArmor();
    int getStrength();
    int getInflicted();
    virtual ~Character();

};

#endif