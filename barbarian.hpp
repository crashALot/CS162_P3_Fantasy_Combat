/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        08/05/18
** Description: This file contains the associated prototypes and 
*               interfaces needed to use Barbarian class objects.
*               Derived from Character base class.
*********************************************************************/
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP
#include "character.hpp"

class Barbarian : public Character
{
private:

public:

    Barbarian();
    int attacks();
    void defend(int);
    ~Barbarian();

};

#endif