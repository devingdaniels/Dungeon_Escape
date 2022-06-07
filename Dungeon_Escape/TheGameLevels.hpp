//
//  TheGameLevels.hpp
//  Dungeon_Escape
//
//  Created by Devin Daniels on 6/6/22.
//

#ifndef TheGameLevels_hpp
#define TheGameLevels_hpp



#include <string>
using std::string;


static const int ROW_Y_SIZE = 7;
static const int COL_X_SIZE = 9;

class Node{
private:
    // ptr to next level
    Node *next;
    
    // ptr to previous level
    Node *prev;
    
    // the number of the level
    int levelNumber;
    
    // constant variables for array size
 
    
public:
    // string array for game elements
    string arr[ROW_Y_SIZE][COL_X_SIZE];
    
   // constructor
    Node();
    
    // destructor
    virtual ~Node() = default;
    
    // getters
    int getLevelNumber () const {return this->levelNumber;}
    Node *getNext() const {return this->next;}
    Node *getPrev() const {return this->prev;}
    
    // setters
    void setLevelNumber(int number){this->levelNumber = number;}
    void setNext(Node* ptr)  {this->next = ptr;}
    void setPrev(Node *ptr)  {this->prev = ptr;}
};

class LinkedList{
private:
    
    Node *head; // pointer to head of the list
    
    int levelCounter; // tracks number of levels in the list
    
public:
   // constructor
    LinkedList(); // in TheGameLevels.cpp
    
    // destuctor
    virtual ~LinkedList()
    {
        while (isEmpty()) {  removeHead(); }
    }
    // getters
    Node *getHead() const {return this->head;}
    
    // methods
    void addLevel();// creates a node with 2D-array, assigns a level number, 
    void removeHead();
    bool isEmpty()const;
};
#endif /* Levels_hpp */
