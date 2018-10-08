/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        08/05/18
** Description: This file contains the associated prototypes and 
*               interfaces needed to use Medusa class objects.
*               Derived from Character base class.
*********************************************************************/
#ifndef MEDUSA_HPP
#define MEDUSA_HPP
#include "character.hpp"

class Medusa : public Character
{
private:

public:

    Medusa();
    int attacks();
    void defend(int);
    ~Medusa();

};

#endif