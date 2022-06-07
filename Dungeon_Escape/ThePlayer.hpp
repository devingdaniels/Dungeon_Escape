//
//  ThePlayer.hpp
//  Dungeon_Escape
//
//  Created by Devin Daniels on 6/6/22.
//
#ifndef ThePlayer_hpp
#define ThePlayer_hpp

#include <string>
using std::string;


// player coordinates
const int ROW_Y_COOR = 0;
const int COL_X_COOR = 1;


class Player{
private:
    // constants
    
    // size of player coordinate arrays
    static const int PLAYER_YX_SIZE = 2;
    
    // player name
    string name;
    
    // player character
    string character;
    
    // counter of collected gold
    int gold;
    
    // current level (node) player is on
    int currentLevel;
    
public:
    
    // current and next player locations within the current level
    int currentPlayerYX[PLAYER_YX_SIZE]; // current player location in a given level
    int oldPlayerXY[PLAYER_YX_SIZE];
    
    // constructor
    Player(){
        // init player attibutes
        this->name = "";
        this->character = "";
        this->gold = 1;
        this->currentLevel =  1;
        
        // init player coordinates
        for (int i = 0; i < PLAYER_YX_SIZE; i++){
            this->currentPlayerYX[i] = 0;
            this->oldPlayerXY[i] = 0;
        }
    }
    
    //destructor
    virtual ~ Player() = default;
    
    // getters
    string getName() const {return this->name;} // returns current player name
    string getCharacter() const {return this->character;} // returns current player character
    int getGold() const {return this->gold;} // current collected gold
    int getCurrentLvl() const {return this->currentLevel;} // level that current player is on (starts on 1)
   
    //setters
    void setName(string name) {this->name = name;}
    void setCharacter(string character) {this->character = character;}
    void updateGold() {this->gold++;}
    void setCurrentLvl(int n) {this->currentLevel = n;}
};

#endif /* ThePlayer_hpp */
