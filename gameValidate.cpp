/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        08/05/18
** Description: This file contains the functions necessary to validate
*               user input.
*********************************************************************/
#include "gameValidate.hpp"
#include <string>
#include <iostream>

/********************************************************************* 
** Description: int mainMenuValidate()
*               Limits user input to integers 1 or 2
*********************************************************************/
int mainMenuValidate()
{
    int go=1, length=0;
    std::string userIn;
    do
    {
        // http://www.cplusplus.com/forum/beginner/2624/
        // How to identify the Enter key when pressed alone 
        std::getline(std::cin, userIn);
        length=userIn.length();
        if (userIn[0]==' ' || length>1 || (userIn[0]!='1' && userIn[0]!='2'))
        {
            std::cout << "Please re-enter your choice as an integer 1 (Play a game) or 2 (Quit the game): " << std::endl;
        }
        else
        {
            // Work cited: https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c
            go=0; // Signal variable exits while loop
            return((int)userIn[0]-'0'); // Converts char to int via ASCII code math
        }
    }
    while (go);
    return 0;
}

/********************************************************************* 
** Description: int selectionMenuValidate()
*               Limits user input to between 1 and 5
*********************************************************************/
int selectionMenuValidate()
{
    int go=1, length=0;
    std::string userIn;
    do
    {
        // http://www.cplusplus.com/forum/beginner/2624/
        // How to identify the Enter key when pressed alone 
        std::getline(std::cin, userIn);
        length=userIn.length();
        if (userIn[0]==' ' || length>1 || (userIn[0]-'0')>5 || (userIn[0]-'0')<1)
        {
            std::cout << "Please re-enter your choice as an integer less than 6 but greater than 0:" << std::endl;
        }
        else
        {
            // Work cited: https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c
            go=0; // Signal variable exits while loop
            return((int)userIn[0]-'0'); // Converts char to int via ASCII code math
        }
    }
    while (go);
    return 0;
}