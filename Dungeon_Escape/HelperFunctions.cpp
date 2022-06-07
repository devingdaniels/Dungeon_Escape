//
//  HelperFunctions.cpp
//  Dungeon_Escape
//
//  Created by Devin Daniels on 6/6/22.
//

#include "HelperFunctions.hpp"


/*------------------------- DISPLAY INSTRUCTIONS-----------------------------  */
void displayInsructions(){
    cout << "Welcome to the Dungeon!" << endl << endl;
    cout << "Collect as much 💰 as you can" << endl;
    cout << "Avoid 👾 and 🔥" << endl;
    cout << "🚪's take you to other levels" << endl;
    cout << "The exit of the game --> ⛔ will turn into --> ✅, once you find the 🗝️..." << endl;
    cout << "Controls: W = UP, A = LEFT, D = RIGHT, S = DOWN, followed by ENTER to execute move" << endl;
    cout << "Before the game begins, enter your name and choose characater" << endl << endl;
}
/*------------------------- DISPLAY INSTRUCTIONS-----------------------------  */

string getName(){
    string name;
    cout << "Character's name: ";
    cin >> name;
    return name;
}

/*------------------------------------------ SYMBOL CHOICE ------------------------------------------------- */

string getCharacterChoice(){

    // First, display the characters
    static const int MAX_OPTIONS = 5;
     const string choiceArray[MAX_OPTIONS] = {"🧑‍🚒","👨‍🎤","🧑‍🚀","🥷","🦹"};
    // first display the options
    for (int i = 0; i < MAX_OPTIONS; i++){
        cout << "Option " << i << ": " << choiceArray[i] << endl;
    }
    
    // Next, get a choice
    
    // the choice
    int choice = 0;
    
    // the character
    string character = "";
    
    // flag for loop
    bool valid = false;
    
    do{
        cout << "Enter your choice, 0-4: ";
        cin >> choice;
        if (cin.fail() or choice < 0 or choice >= MAX_OPTIONS){
            if (cin.fail()){
                cout << "Invalid input, try again: ";
            }else {
                cout << "Input outside the range, try again: ";
            }
            cin.clear();
            cin.ignore(INT_MAX, '\n'); // ignore max numbers or till new line
        }else{
            valid = true;
        }
    }while(!valid);
    
    character = choiceArray[choice];
    
    return character;
}
/*------------------------- GET USER MOVE -----------------------------  */

char getUserMove(){
    
    //variable init
    const int BIG_NUM = INT_MAX;
    const char END_LINE = '\n';
    
    // the current move
    char move;
    // flag for do/while
    bool valid = false;
    
    cout << "Enter a move: ";
    do {
        cin >> move;
        // check for bad input
        if (cin.fail() and move != MOVE_UP and MOVE_DOWN and move != MOVE_LEFT and move != MOVE_RIGHT){
            cout << "Invalid move, try again: ";
            // clear the error flag
            cin.clear();
            // flush the buffer
            cin.ignore(BIG_NUM, END_LINE);
        }else{
            valid = true;
        }
    }while(!valid);
    return move;
}


/*------------------------- PLAY AGAIN-----------------------------  */
bool playAgain(){
    //variable init
    const int BIG_NUM = INT_MAX;
    const char END_LINE = '\n';
    bool valid; // used in dowhile loop for data validation
    char userInput; // used as return value, true to playagain, false to end the game
    bool result = false; // init to fix init warning
    cout << "Do you want to play again (y/n): ";
    do{
        cin >> userInput;
        userInput = tolower(userInput);
        if (userInput != 'y' and  userInput != 'n')
        {
            cout <<"That is invalid input. Try again: ";
            cin.clear();
            cin.ignore(BIG_NUM, END_LINE);
            valid = true;
        }else if (userInput == 'y'){
            valid = false;
            result = true;
        }else{
            valid = false;
            result = false;
        }
    }while(valid);
    return result;
}
