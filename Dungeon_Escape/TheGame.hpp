//
//  TheGame.hpp
//  Dungeon_Escape
//
//  Created by Devin Daniels on 6/6/22.
//

#ifndef TheGame_hpp
#define TheGame_hpp


#include "TheGameLevels.hpp" // The levels of the game used in TheGame class

#include "ThePlayer.hpp" // The player object

#include "HelperFunctions.hpp" // getting a name, displaying game instructions, etc.


struct GameElements{
public:
    
    // constants for number of game board elements
    static const int NUM_ENEMIES = 4;
    static const int NUM_GOLD = 6;
    static const int NUM_FIRE = 4;
    static const int NUM_KEY = 1;
    
    // game board elements
    const string MONSTER = "👾";  // monster in the array
    const string SPIDER = "🕷";
    const string OGRE = "👹";
    const string GOLD = "💰"; // gold in the array
    const string FIRE = "🔥"; // fire in the array
    const string DOOR = "🚪"; // door in the array
    const string KEY = "🗝️"; // key that is only in the last node, unlocks door on first level (node 1)
    const string GOOD_EXIT = "✅"; // door appears once key is found
    const string BAD_EXIT = "⛔"; // represents exit until key is found
    const string BOARD_ELEMENT = "●";
    const string TELEPORTER = "🌀";
};


class Game{
private:
    
    // linked-list of game levels
    LinkedList gameLevels;
    
    // variable for current level of where player is
    Node *currentLevel;
    
    // object containing player info and coordinates used in the game
    Player player;
    
    // struct containing array elements for the dungeon
    GameElements gameElements;
    
public:
    static const int GAME_SIZE = 3;
    const int STARTING_LEVEL = 1;
    const int FINAL_LEVEL = GAME_SIZE;
    
    // constructor
    Game(){} // static game implementation, dynamic would set gamesize
    // destructor
    virtual ~Game() = default;
    
    // getters
    Player getPlayer()  {return this->player;}
    
    // methods
    void createGame(); // creates nodes in linked-list, fills the nodes, and creates a player
    void fillLevels(); // fill each array with different elements
    void spawnElement(Node *curLvl, string element, int count); // method to fill with proper element
    string displayCurrentLevel(); // display current level that player is on
    void getMove(); // gets and updates player location
    bool checkEnemy(); // checks for loss
    bool checkWin(); // checks for win
    void movePlayer(); // if no win or loss, will move the player character in the array
    void displayAllLevels(); // display the linked-list, for debugging
};
#endif /* TheGame_hpp */
