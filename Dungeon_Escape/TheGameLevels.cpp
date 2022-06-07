//
//  TheGameLevels.cpp
//  Dungeon_Escape
//
//  Created by Devin Daniels on 6/6/22.
//


#include "TheGameLevels.hpp"


#include <exception> // Used for throwing exceptions
using std::out_of_range;


/*============================= CONSTRUCTORS FOR CLASSES IN LEVELS.HPP  ================================*/

/*============= NODE CONSTRUCTOR ==========  */
Node::Node (){
    
    // init ptr's in the node
    this->next = nullptr;
    this->prev = nullptr;
    //
    this->levelNumber = - 1;  // no level with ever be less than 0
    
    // init the array
    for (int i = 0; i < ROW_Y_SIZE; i++){
        for (int j = 0; j < COL_X_SIZE; j++){
            arr[i][j] = "";
        }
    }
}

/*======================= LINKED LIST CONSTRUCTOR =====================  */
LinkedList::LinkedList(){
    // init head
    this->head = nullptr;
    // init counter
    this->levelCounter = 0;
}
/*============================= LINKED LIST CLASS METHODS  ================================*/

void LinkedList::addLevel(){
    
    // create pointer for new node
    Node *temp;
    
    // check if linked-list is empty
    if (isEmpty()){
        // create a new node
        temp = new Node;
        // set head
        head = temp;
        
        // next and prev in node conatainers are are initialized to nullptr, no extra code needed
        
    }
    
    // for non-empty list
    else{
        // create a new node
        temp = new Node;
        // first, update head prev container to point to new node
        head->setPrev(temp);
        // set temp next container to point what head is point to
        temp->setNext(head);
        // update head to point to temp
        head = temp;
    }
    
    // increment the level counter
    levelCounter++;
    // set the level number in node
    temp->setLevelNumber(levelCounter);
}

void LinkedList::removeHead(){
    if (isEmpty()){
        throw out_of_range("Head points to nulptr; list is empty");
    }
    // get address of first node
    Node *temp = head;
    // set head to point to second node
    head = head->getNext();
    // delete first node
    delete temp;
}

bool LinkedList::isEmpty() const{
    if (head == nullptr){
        return true;
    }
    return false;
}
