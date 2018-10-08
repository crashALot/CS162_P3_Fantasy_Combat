/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        08/05/18
** Description: This file contains the associated prototypes and 
*               interfaces needed to use Game class objects.
*********************************************************************/
#ifndef GAMEMENU_HPP
#define GAMEMENU_HPP
#include "gameValidate.hpp"
#include "character.hpp"
#include "vampire.hpp"
#include "barbarian.hpp"
#include "blueMen.hpp"
#include "medusa.hpp"
#include "harryPotter.hpp"

class Game
{
private:
    
    Character* combatants[2];
    
public:
    
    Game();
    void mainMenu();
    void selectionMenu();
    double randomGenerator();
    void fightClub();
    void endMenu();
    void exitMenu();
    ~Game();

};
#endif