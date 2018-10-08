/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        08/05/18
** Description: This file contains the associated prototypes and 
*               interfaces needed to use HarryPotter class objects.
*               Derived from Character base class.
*********************************************************************/
#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP
#include "character.hpp"

class HarryPotter : public Character
{
private:

    bool hasDied;

public:

    HarryPotter();
    int attacks();
    void defend(int);
    ~HarryPotter();

};

#endif