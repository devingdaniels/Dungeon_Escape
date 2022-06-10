//
//  TheGame.hpp
//  Dungeon_Escape
//
//  Created by Devin Daniels on 6/6/22.
//

#include <iostream>
using std::cout, std::endl;

#include "TheGame.hpp" // Game class

int main() {
   
    // random number generator for spawing game elements
    srand(unsigned(time(nullptr)));
    // create instance of the game
    Game *game;
    // display initial instructions
    displayInsructions();
    do{ // outter do/while loop
        // flag for running a valid game
        bool playing = true;
        // create a new game
        game = new Game;
        // create a new game with player info and new level
        game->createGame();
        // store the player name
        string playerName = game->getPlayer().getName() + " " +  game->getPlayer().getCharacter();
        do {
            // display the level where player is currently located
            cout <<  game->displayCurrentLevel() << endl;
            // get a user move
            game->getMove();
            // check if move results in game over
            if (game->checkEnemy()){
                cout <<  game->displayCurrentLevel() << endl;
                playing = false;
                cout << "You encountered an enemy... " << playerName << " is a LOSER" << endl;
            }else if (game->checkWin()){
                cout <<  game->displayCurrentLevel() << endl;
                cout << playerName << " WINS!!!" << endl;
                // display the total gold player found
                cout << "Total gold found: " << game->getPlayer().getGold() << endl;
                playing = false;
            }else{
                // not a win or loss, update player location, keep playing
                game->movePlayer();
            }
            
        }while(playing); // returns false if player lands on enemey
        // delete old game
        delete game;
        // ask user if they want to play again
    }while(playAgain());
    cout << "Thanks for playing!" << endl;
    return 0;
}


