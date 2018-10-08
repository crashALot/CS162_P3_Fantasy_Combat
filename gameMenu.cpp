/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        08/05/18
** Description: This file contains the methods and functions required
*               to create and manipulate Game class objects. 
*               Creates menu driven output required to play fantasy
*               fighting game. Coordinates player actions
*********************************************************************/
#include "gameMenu.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

/********************************************************************* 
** Description: Game::Game()
*               Game class default cnostructor
*********************************************************************/
Game::Game()
{
    combatants[0]=NULL;
    combatants[1]=NULL;
    mainMenu();
}

/********************************************************************* 
** Description: void Game::mainMenu()
*               Prompts user to play game or exit program
*********************************************************************/
void Game::mainMenu()
{
    int userSelection; 
    std::cout << "*********** Welcome to Fantasy Fighting for Families and Friends! ***********" << std::endl << std::endl;
    
    std::cout << "      Please select from one of the options below:" << std::endl;
    std::cout << "          1. Play a game" << std::endl;
    std::cout << "           2. Exit the program" << std::endl;
    userSelection=mainMenuValidate();
    switch (userSelection)
    {
        case 1:
        selectionMenu();
        break;
        
        case 2:
        exitMenu();
        break;
    }
}

/********************************************************************* 
** Description: void Game::selectionMenu()
*               Prompts the user to enter which combatants will be
*               used during game
*********************************************************************/
void Game::selectionMenu()
{
    for (int i=0; i<2; i++)
    {
        int userSelection;
        
        std::cout << std::endl << "*************** Select your ";
        if (!i)
            std::cout << "first";
            else
            std::cout << "second";    
        std::cout << " combatant! ***************" << std::endl << std::endl;
        
        std::cout << "  Please choose from a fighter below:" << std::endl << std::endl;
        std::cout << "          1. Vampire" << std::endl;
        std::cout << "           2. Barbarian" << std::endl;
        std::cout << "            3. Blue Men" << std::endl;
        std::cout << "             4. Medusa" << std::endl;
        std::cout << "              5. Harry Potter" << std::endl << std::endl;    
        userSelection=selectionMenuValidate()-1;
        switch (userSelection)
        {
            case 0:
            combatants[i]= new Vampire();
            break;

            case 1:
            combatants[i]= new Barbarian();
            break;
            
            case 2:
            combatants[i]= new BlueMen();
            break;
            
            case 3:
            combatants[i]= new Medusa();
            break;
            
            case 4:
            combatants[i]= new HarryPotter();
            break;
        }
    }
    fightClub();
    endMenu();
}

/********************************************************************* 
** Description: double Game::randomGenerator()
*               Return value between 0 and 1 for use with other 
*               functions
*********************************************************************/
double Game::randomGenerator()
{
    return (static_cast<double>(rand())/static_cast<double>(RAND_MAX));
}

/********************************************************************* 
** Description: void Game::fightClub()
*               Coordinates the attack and defend actions between user
*               selected players. Outputs narrative and results to 
*               consol
*********************************************************************/
void Game::fightClub()
{
    int firstAttacker, secondAttacker, totalAttack, counts=1;
    firstAttacker=randomGenerator()*2; // Randomly select first attacker
    secondAttacker=(1-firstAttacker); // Determine second attacker from first
    // Select two characters with the same name? Now one is evil and one is good!
    if (combatants[0]->getTitle()==combatants[1]->getTitle())
    {
        combatants[0]->setTitle("Evil "+combatants[0]->getTitle());
        combatants[1]->setTitle("Good "+combatants[1]->getTitle());
    }
    std::cout << "You have selected " << combatants[0]->getTitle() << " as your first combatant" << std::endl << std::endl;
    std::cout << "You have selected " << combatants[1]->getTitle() << " as your second combatant" << std::endl << std::endl;
    std::cout << "The first to attack is " << combatants[firstAttacker]->getTitle() << "!" << std::endl << std::endl;
    // While-loop guarantees loop will run until one combatant dies
    while (1)
    {
        std::cout << "__________________________________________________________________________" << std::endl;
        std::cout << "                                    Round " << counts << " Begins!" << std::endl;
        std::cout << "           ********** Attacker ********** | ********** Defender **********" << std::endl;
        std::cout << "Type:                 " << std::left << std::setw(17) << combatants[firstAttacker]->getTitle() << std::right << std::setw(4) << "|"<< std::left  << "            " << combatants[secondAttacker]->getTitle() << std::endl;
        std::cout << "Start Strength:       -->                 |" << "            " << combatants[secondAttacker]->getStrength() << std::endl;
        std::cout << "Armor:                -->                 |" << "            " << combatants[secondAttacker]->getArmor() << std::endl;
        std::cout << "Dice Roll:            " ;
        
        totalAttack=combatants[firstAttacker]->attacks(); 
        combatants[secondAttacker]->defend(totalAttack);

        std::cout << "Damage:               " << std::left << std::setw(15) << totalAttack << std::right << std::setw(6) << "|" << " Inflicted: " << combatants[secondAttacker]->getInflicted() << std::endl;
        std::cout << "Post Strength:        -->                 |" << "            " << combatants[secondAttacker]->getStrength() << std::endl << std::endl;
       
        combatants[secondAttacker]->setInflicted(0);
        if (combatants[secondAttacker]->getStrength()<=0)
        {
            std::cout << "            _-_-_-_-_  After a valiant fight " << combatants[secondAttacker]->getTitle() << " has died!  _-_-_-_-_" << std::endl; 
            break;
        }
        std::cout << std::endl;
        std::cout << "           ********** Attacker ********** | ********** Defender **********" << std::endl;
        std::cout << "Type:                 " << std::left << std::setw(17) << combatants[secondAttacker]->getTitle() << std::right << std::setw(4) << "|"<< std::left  << "            " << combatants[firstAttacker]->getTitle() << std::endl;
        std::cout << "Start Strength:       -->                 |" << "            " << combatants[firstAttacker]->getStrength() << std::endl;
        std::cout << "Armor:                -->                 |" << "            " << combatants[firstAttacker]->getArmor() << std::endl;
        std::cout << "Dice Roll:            " ;
        
        totalAttack=combatants[secondAttacker]->attacks();
        combatants[firstAttacker]->defend(totalAttack);
        
        std::cout << "Damage:               " << std::left << std::setw(15) << totalAttack << std::right << std::setw(6) << "|" << " Inflicted: " << combatants[firstAttacker]->getInflicted() << std::endl;
        std::cout << "Post Strength:        -->                 |" << "            " << combatants[firstAttacker]->getStrength() << std::endl << std::endl;
        
        combatants[firstAttacker]->setInflicted(0);
        if (combatants[firstAttacker]->getStrength()<=0)
        {
            std::cout << "            _-_-_-_-_  After a valiant fight " << combatants[firstAttacker]->getTitle() << " has died!  _-_-_-_-_" << std::endl;
            break;
        }

        counts++;
    }
    
    // Determine who won the match
    int victor=0;
    if (combatants[firstAttacker]->getStrength()>combatants[secondAttacker]->getStrength())
        victor=1;
    std::cout << "An end to the bloodshed is reached. To the victor go the spoils of war! ";
    if (victor)
        std::cout << combatants[firstAttacker]->getTitle();
    else
        std::cout << combatants[secondAttacker]->getTitle();
    std::cout << " won the battle!" << std::endl << std::endl;
    
    // Deallocated character objects previously created with "new"
    delete combatants[firstAttacker];
    delete combatants[secondAttacker];
} 

/********************************************************************* 
** Description: void Game::endMenu()
*               Enables user to choose whether to continue playing 
*               game or exit game
*********************************************************************/
void Game::endMenu()
{
    int userInput;
    std::cout << "With the battle over what would you like to do next? " << std::endl;
    std::cout << "      1. Play another round" << std::endl;
    std::cout << "       2. Exit the game" << std::endl;
    userInput=mainMenuValidate();
    if (userInput==1)
        selectionMenu();
    else
        exitMenu();
        
}

/********************************************************************* 
** Description: void Game::exitMenu()
*               Exit message left to user upon quitting the 
*               program
*********************************************************************/
void Game::exitMenu()
{
    std::cout << std::endl << "************ Thank you for playing! See you again soon! ************" << std::endl;
}

/********************************************************************* 
** Description: Game::~Game()
*               Game class destructor
*********************************************************************/
Game::~Game()
{
}