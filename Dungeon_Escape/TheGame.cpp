//
//  TheGame.cpp
//  Dungeon_Escape
//
//  Created by Devin Daniels on 6/6/22.
//

#include "TheGame.hpp"


void Game::createGame(){
    
    // First, create a linked-list with number of nodes = to GAME_SIZE
    for (int i = 0; i < GAME_SIZE; i++){
        gameLevels.addLevel();
    }
    
    // Next, get user info to create the player
    player.setName(getName()); // get and set the user name
    player.setCharacter(getCharacterChoice()); // get and set user charachter choice
    
    // Lastly, fill each level with game elements
    fillLevels();
   
}

void Game::fillLevels(){
    
    // start at the head of the linked list
    Node *currentLevel = gameLevels.getHead();
    
    // every level in each node gets initialized with board elements
    while (currentLevel != nullptr){
        // fill each level with base elements
        for (int i = 0; i < ROW_Y_SIZE; i++){
            for (int j = 0; j < COL_X_SIZE; j++){
                currentLevel->arr[i][j] = gameElements.BOARD_ELEMENT;
            }
        }
        // fill data for the starting level (level 1)
        if (currentLevel->getLevelNumber() == STARTING_LEVEL){
            // Fill gold on the current level
            addGold(currentLevel);
            // add Ogre's to the level
            addMonster(gameElements.OGRE,  currentLevel);
            // spawn in the fire
            addFire(currentLevel);
            // fill special cases
            // special case the player character
            currentLevel->arr[0][0] = player.getCharacter();
            // special case the bad exit symbol
            currentLevel->arr[6][0] = gameElements.BAD_EXIT;
            // special case the door to the next level
            currentLevel->arr[ROW_Y_SIZE - 1 ][COL_X_SIZE - 1 ] = gameElements.DOOR;
        }
        // fill data for the ending level (level 3)
        else if (currentLevel->getLevelNumber() == FINAL_LEVEL){
            // spawn in the monster type
            addMonster(gameElements.SPIDER,currentLevel);
            // spawn in the fire
            addFire(currentLevel);
            // spaw in the gold
            addGold(currentLevel);
            // randomely spawn the key
            spawnKey(currentLevel);
        }
        // fill data for general levels
        else {
            // spawn monster type
            addMonster(gameElements.MONSTER, currentLevel);
            // spawn in the fire
            addFire(currentLevel);
            // spaw in the gold
            addGold(currentLevel);
            currentLevel->arr[ROW_Y_SIZE - 1][COL_X_SIZE - 1] = gameElements.DOOR; // ADD A DOOR HERE

        }
        // get and save the address of the starting level to private class variable
        if (currentLevel->getLevelNumber() == STARTING_LEVEL){
            this-> currentLevel = currentLevel;
        }
        // get the next node
        currentLevel =  currentLevel->getNext();
    }
    
    
    
}
void Game::spawnKey(Node *currentLVL){
    
    int randomY = 0;
    int randomX = 0;
    
    bool good = false;
    do {
        randomY = rand() % ROW_Y_SIZE - 1;
        randomX = rand() % COL_X_SIZE - 1;
        if ( currentLVL->arr[ randomY][randomX] != gameElements.BOARD_ELEMENT){
            good = false;
        }
       else  if (currentLVL->arr[ randomY][randomX] == gameElements.BOARD_ELEMENT){
            good = true;
           currentLVL->arr[ randomY][randomX] = gameElements.KEY;
        }
    } while(!good);
    
    
}
void Game::addGold(Node *currentLVL){
    

    int randomY = 0;
    int randomX = 0;


    for (int i =0 ; i < gameElements.NUM_GOLD; i++){

        bool good = false;

        do {
            randomY = rand() % ROW_Y_SIZE - 1;
            randomX = rand() % COL_X_SIZE - 1;
          
            if ( currentLVL->arr[ randomY][randomX] != gameElements.BOARD_ELEMENT){
                good = false;
            }
            
            else  {
                good = true;
                currentLVL->arr[ randomY][randomX] = gameElements.GOLD;
            }
            
        } while(!good);
    }
}

void Game::addMonster(string monster, Node *currentLVL){

    int randomY = 0;
    int randomX = 0;

    for (int i =0 ; i < gameElements.NUM_ENEMIES; i++){
        bool good = false;
        do {
            randomY = rand() % ROW_Y_SIZE - 1;
            randomX = rand() % COL_X_SIZE - 1;
            if ( currentLVL->arr[ randomY][randomX] != gameElements.BOARD_ELEMENT){
                good = false;
            }
           else  if (currentLVL->arr[ randomY][randomX] == gameElements.BOARD_ELEMENT){
                good = true;
               currentLVL->arr[ randomY][randomX] = monster;
            }
        } while(!good);

    }
}

void Game::addFire(Node *currentLVL){
    
    int randomY = 0;
    int randomX = 0;

    for (int i =0 ; i < gameElements.NUM_ENEMIES; i++){
        bool good = false;
        do {
            randomY = rand() % ROW_Y_SIZE - 1;
            randomX = rand() % COL_X_SIZE - 1;
            if ( currentLVL->arr[ randomY][randomX] != gameElements.BOARD_ELEMENT){
                good = false;
            }
           else  if (currentLVL->arr[ randomY][randomX] == gameElements.BOARD_ELEMENT){
                good = true;
               currentLVL->arr[ randomY][randomX] = gameElements.FIRE;
            }
        } while(!good);

    }
}

string Game::displayCurrentLevel(){
    string buffer = "";
    
    cout <<"CURRENT LEVEL: " <<   currentLevel->getLevelNumber() << endl;
    for (int i = 0; i < ROW_Y_SIZE; i++){
        for (int j = 0; j < COL_X_SIZE; j++){
            buffer += currentLevel->arr[i][j] + "   ";
        }
        buffer += '\n';
    }
    return buffer;
}


void Game::getMove(){
    
    // get and save old player location
    int oldY = player.currentPlayerYX[0];
    int oldX = player.currentPlayerYX[1];
 
    bool validMove = false;
    do {
        char move = getUserMove();
        
        switch (move) {
            case MOVE_UP:
                if ( (player.currentPlayerYX[0] - 1) < (0 )){
                    cout << "You can't move through walls...Try a different move " << endl;
                }
                // valid move, update next
                else {
                    // save old y-coordinate
                    player.oldPlayerXY[0] = oldY;
                    // save old y-coordinate
                    player.oldPlayerXY[1] = oldX;
                    // update current player location with new move
                    player.currentPlayerYX[0] -= 1;
                    validMove = true;
                }
                break;
            case MOVE_DOWN:
                if ( ( player.currentPlayerYX[0] + 1 ) > (ROW_Y_SIZE - 1) ){
                    cout << "You can't move through walls...Try a different move " << endl;
                }
                // valid move, update next
                else {
                    // save old y-coordinate
                    player.oldPlayerXY[0] = oldY;
                    // save old y-coordinate
                    player.oldPlayerXY[1] = oldX;
                    // update current player location with new move
                    player.currentPlayerYX[0] += 1;
                    validMove = true;
                }
                break;
            case MOVE_RIGHT:
                // update the coordinates of next
      //          player.nextYX[0] = - 1;
                if ( ( player.currentPlayerYX[1] + 1 ) >  ( COL_X_SIZE - 1 ) ) {
                    cout << "You can't move through walls...Try a different move " << endl;
                }
                // valid move, update next
                else {
                    // save old y-coordinate
                    player.oldPlayerXY[0] = oldY;
                    // save old y-coordinate
                    player.oldPlayerXY[1] = oldX;
                    // update current player location with new move
                    player.currentPlayerYX[1] += 1;
                    validMove = true;
                }
                break;
            case MOVE_LEFT:
                // update the coordinates of next
      //          player.nextYX[0] = - 1;
                if ( ( player.currentPlayerYX[1] - 1 ) < ( 0 ) ) {
                    cout << "You can't move through walls...Try a different move " << endl;
                }
                // valid move, update next
                else {
                    // save old y-coordinate
                    player.oldPlayerXY[0] = oldY;
                    // save old y-coordinate
                    player.oldPlayerXY[1] = oldX;
                    // update current player location with new move
                    player.currentPlayerYX[1] -= 1;
                    validMove = true;
                }
                break;
            default:
                cout << "something is broken in get move" << endl;
                break;
        }
    }while (!validMove);
}


bool Game::checkEnemy(){

    if (currentLevel->arr[player.currentPlayerYX[0]][player.currentPlayerYX[1] ] == gameElements.MONSTER or currentLevel->arr[player.currentPlayerYX[0]][player.currentPlayerYX[1] ] == gameElements.OGRE or currentLevel->arr[player.currentPlayerYX[0]][player.currentPlayerYX[1] ] == gameElements.SPIDER or currentLevel->arr[player.currentPlayerYX[0]][player.currentPlayerYX[1] ] == gameElements.FIRE){
        // update old location to board element
        currentLevel->arr[player.oldPlayerXY[0]][player.oldPlayerXY[1]] = gameElements.BOARD_ELEMENT;
        currentLevel->arr[player.currentPlayerYX[0]][player.currentPlayerYX[1]] = player.getCharacter();
        return true;
    }
    
    return  false;
}
bool Game::checkWin(){
    
    // check if player next coordinates is on on good exit, ends the game if true
    if (currentLevel->arr[player.currentPlayerYX[0]][player.currentPlayerYX[1]] == gameElements.GOOD_EXIT){
        // update old location to board element
        currentLevel->arr[player.oldPlayerXY[0]][player.oldPlayerXY[1]] = gameElements.BOARD_ELEMENT;
        currentLevel->arr[player.currentPlayerYX[0]][player.currentPlayerYX[1]] = player.getCharacter();
        return true;
    }
    
    return  false;
}


void Game::movePlayer(){
    
    int player_coor_y = player.currentPlayerYX[0];
    int player_coor_x = player.currentPlayerYX[1];
    
    

    if (currentLevel->arr[player_coor_y][player_coor_x ] == gameElements.GOLD){
        cout << "You found GOLD! Your total is now: $" << player.getGold() << endl;
        player.updateGold();
        // update old player location with correct element
        currentLevel->arr[player.oldPlayerXY[0]][player.oldPlayerXY[1]] = gameElements.BOARD_ELEMENT;
        // update new player location in the arr with player character
        currentLevel->arr[player.currentPlayerYX[0]][player.currentPlayerYX[1]] = player.getCharacter();
    }
    
    else if (currentLevel->arr[player_coor_y][player_coor_x ] == gameElements.DOOR){
        
        // remove player from current level
        currentLevel->arr[player.oldPlayerXY[0]][player.oldPlayerXY[1]] = gameElements.BOARD_ELEMENT;
        // go to the next level
        currentLevel = currentLevel->getPrev();
        // reset current player location
        player.currentPlayerYX[0] = 0;
        player.currentPlayerYX[1] = 0;
        // reset old player location
        player.oldPlayerXY  [0] = 0;
        player.oldPlayerXY[1] = 0;
        // update player in the current level
        currentLevel->arr[player.currentPlayerYX[0]][player.currentPlayerYX[1]] = player.getCharacter();
    }
    
    
    else if (currentLevel->arr[player_coor_y][player_coor_x ] == gameElements.KEY){
        cout << "You found the key, the exit is now open. Get to the teleporter!" << endl;
        
        // get starting level and replace bad exit with good exit
        Node *temp = currentLevel;
        while (temp !=nullptr){
            if (temp->getLevelNumber() == STARTING_LEVEL){
                temp->arr[6][0] = gameElements.GOOD_EXIT;
                temp = nullptr;
            }else {
                temp = temp->getNext();
            }
        }
        
        // update old  player location with correct board element
        currentLevel->arr[player.oldPlayerXY[0]][player.oldPlayerXY[1]] = gameElements.BOARD_ELEMENT;
        // update player in the current level
        currentLevel->arr[player.currentPlayerYX[0]][player.currentPlayerYX[1]] = player.getCharacter();
        // special case spawn the teleporter
        currentLevel->arr[ROW_Y_SIZE - 1][COL_X_SIZE - 1] = gameElements.TELEPORTER; // ADD A DOOR HERE
    }
    
    else if (currentLevel->arr[player_coor_y][player_coor_x ] == gameElements.TELEPORTER){
        cout << "You found teleporter! **teleportation in progress** " << endl;
        // reset current player location
        player.currentPlayerYX[0] = 0;
        player.currentPlayerYX[1] = 0;
        // reset old player location
        player.oldPlayerXY  [0] = 0;
        player.oldPlayerXY[1] = 0;
        // update current level to be starting level
        while (currentLevel->getLevelNumber() != STARTING_LEVEL){
            currentLevel = currentLevel->getNext();
        }
        currentLevel->arr[player.currentPlayerYX[0]][player.currentPlayerYX[1]] = player.getCharacter();
    }
    
    else if (currentLevel->arr[player_coor_y][player_coor_x ] == gameElements.BAD_EXIT){
        cout << "You have not found the key, exit is not available!" << endl;
        // update old player location
        
        currentLevel->arr[player.currentPlayerYX[0]][player.currentPlayerYX[1]] = gameElements.BAD_EXIT;
        // move the player back to old location
        player.currentPlayerYX[0] = player.oldPlayerXY[0];
        player.currentPlayerYX[1] = player.oldPlayerXY[1];
        
    }
    else {
        // update old player location with board element
        currentLevel->arr[player.oldPlayerXY[0]][player.oldPlayerXY[1]] = gameElements.BOARD_ELEMENT;
        // update player location in the arr
        currentLevel->arr[player.currentPlayerYX[0]][player.currentPlayerYX[1]] = player.getCharacter();
    }
}

void Game::displayAllLevels(){
    
    
    Node *curLvl = gameLevels.getHead();
    
    while (curLvl != nullptr){
        cout <<"LEVEL #->> " << curLvl->getLevelNumber() << endl;
        for (int i = 0; i < ROW_Y_SIZE; i++){
            for (int j = 0; j < COL_X_SIZE; j++){
                cout << curLvl->arr[i][j] + " ";
            }
            cout << endl;
        }
        cout << endl << endl;
        curLvl  = curLvl->getNext();
    }

}



/*
 
 
 
 
 
 */
