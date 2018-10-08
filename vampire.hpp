/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        08/05/18
** Description: This file contains the associated prototypes and 
*               interfaces needed to use Vampire class objects.
*               Derived from Character base class.
*********************************************************************/
#ifndef VAMPIRE_HPP
#define CHARAACTER_HPP
#include "character.hpp"

class Vampire : public Character
{
private:

    int smoothOperator;

public:

    Vampire();
    int attacks();
    void defend(int);
    ~Vampire();

};

#endif