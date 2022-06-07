//
//  HelperFunctions.hpp
//  Dungeon_Escape
//
//  Created by Devin Daniels on 6/6/22.
//

#ifndef HelperFunctions_hpp
#define HelperFunctions_hpp

#include <iostream>
using std::cout, std::endl, std::cin;
#include <string>
using std::string;


// player moves
const char MOVE_RIGHT = 'd';
const char MOVE_LEFT = 'a';
const char MOVE_DOWN= 's';
const char MOVE_UP = 'w';






// display game instructions
void displayInsructions();
// get character name
string getName();
// gets and validates a symbol choice for the character
string getCharacterChoice();
// gets, validates, returns a char to move the player
char getUserMove();
// method used in fillLevels
// ask and validate player choice to replay
bool playAgain();









#endif /* HelperFunctions_hpp */
