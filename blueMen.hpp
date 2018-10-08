/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        08/05/18
** Description: This file contains the associated prototypes and 
*               interfaces needed to use BlueMen class objects.
*               Derived from Character base class.
*********************************************************************/
#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP
#include "character.hpp"

class BlueMen : public Character
{
private:

    int haveDied;

public:

    BlueMen();
    int attacks();
    void defend(int);
    ~BlueMen();

};

#endif