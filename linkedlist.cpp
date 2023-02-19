//CS311 Yoshii S22 Linked List class

//INSTRUCTION:
//It helps to first create if-then-else structure to fill in later.
//- Make sure PURPOSE and PARAMETER comments are given in detail
//  Highly recommended to copy HW3P1-help as PURPOSE of each function.
//  Add sufficient comments to your code body to describe what it does.
//      - Make sure all if-then-else are commented describing which case it is
//      - Make sure all local variables are described fully with their purposes

//You must complete the TODO parts and then complete LinkedList.cpp. Delete "TODO" after you are done.

// ====================================================
//Your name: Erik Hechavarria Suarez (TODO: Add your name)
//Complier:  g++
//File type: linkedList.cpp implementation file
//=====================================================

#include <iostream>
#include "linkedlist.h"
using namespace std;

/**
 * @brief Destructor to destroy all nodes and release memory
 */
LinkedList::~LinkedList() {
//TODO: Add code here. Make sure memory is released properly.
  Node *ptr = this->front; 
  while(ptr != nullptr){
    Node *temp = ptr; 
    ptr = ptr->next;
    delete temp;
  }
}

/**
 * @brief Purpose: Checks if the list is empty
 * @return true if the list is empty, false otherwise
 */
bool LinkedList::isEmpty() const {
  if(this->front == nullptr){
    return true;
  }else{
    return false; 
  }
} 

/**
 * @brief  Get the number of nodes in the list
 * @return int The number of nodes in the list
 */
int LinkedList::length() const{
//TODO: Add code here
  int counter = 0;
  Node *ptr = this->front; 
  if(this->front == nullptr){
    return counter;
  }
  while(ptr != nullptr){
    counter++;
    ptr = ptr->next; 
  }
  return counter;
}

/**
 * @brief Convert the list to a string
 *
 */
string LinkedList::toString() {
  string str = "[";
  Node *ptr = front;
  if (ptr != nullptr) {
// Head node is not preceded by separator
    str += to_string(ptr->val);
    ptr = ptr->next;
  }
  while (ptr != nullptr) {
    str += ", " + to_string(ptr->val);
    ptr = ptr->next;
  }
  str  += "]";
  return str;
}

/**
 * @brief Displays the contents of the list
 */
void LinkedList::displayAll() {
  cout << toString() << endl;
}

//TODO: Add comments
void LinkedList::addRear(T val) {
// TODO: Add code here
// 1st case
  Node *ptr = new Node;
  ptr->val = val;
  this->count++;
    //ptr = this->front;
  if(this->front == nullptr){
    this->front = ptr;
    this->rear = ptr;
  }else{
    this->rear->next = ptr;
    this->rear = ptr;
  }
// consider the two cases of whether the list was empty
}

//TODO: Add comments
void LinkedList::addFront(T val) {
//1st case if it was empty
  Node *ptr = new Node;
  ptr->val = val;
  this->count++;
//ptr = this->front;
  if(this->front == nullptr){
    this->front = ptr;
    this->rear = ptr;
  } else {
      ptr->next = this->front; 
      this->front = ptr;
    }
// consider the two cases of whether the list was empty
} 

//TODO: Add comments
bool LinkedList::deleteFront(T &OldNum) {
// TODO: Add code here
// consider if the list was empty and return false if the list is empty
  if(this->isEmpty() == true){
    return false; 
  }
  Node *temp = this->front;
  this->front = this->front->next; 
  OldNum = temp->val;
  this->count--;
  delete temp;
  return true;
// consider if the list was empty and return false if the list is empty
// consider the special case of deleting the only node in the list
} 

//TODO: Add comments
bool LinkedList::deleteRear(T &OldNum) {
// TODO: Add code here
// consider if the list was empty and return false if the list is empty
  if(this->isEmpty() == true){
    return false; 
  }else if(this->front->next == nullptr){
    Node *temp = this->front;
    OldNum = temp->val;
    this->front = nullptr;
    this->rear = nullptr;
    this->count--;
    delete temp;
    return true;
    }
    Node *temp = this->front;
    while(temp->next != this->rear){
        temp = temp->next; 
    }
    this->rear = temp;
    temp = temp->next; 
    this->rear->next = nullptr;
    OldNum = temp->val;
    this->count--;
    delete temp;
    return true;
// consider if the list was empty and return false if the list is empty
// consider the special case of deleting the only node in the list
} 
/* --- harder ones for test 2 and 3 -- */

/**
     * @brief Delete a node at a given position from the list. The
     * node at position pos is deleted and the value of the deleted node is returned in val.
     * The valid range of pos is 1 to count. pos = 1 is the first node, and pos = count is the last node.
     * @param pos: position of the node to be deleted
     * @param val: it is set to the value of the node to be deleted
     * @return true: if the node was deleted successfully
     * @return false: if the node was not deleted successfully because the position was out of range
    */
bool LinkedList::deleteAt(int pos, T &val) {
//TODO: Add code here
// check if the pos is valid first, then move the ptr to the rigth positon
  if(pos < 0 || pos >= count){
    return false;
  }
  if(pos == 0){
    this->deleteFront(val);
    return true;
  } 
  if(pos == (count - 1)){
    this->deleteRear(val);
    return true;
  }
  Node *before_ptr = this->front;
  Node *ptr = this->front;
  for(int i = (pos - 1); i > 0; i--){
    before_ptr = before_ptr->next;
    if(before_ptr->next == nullptr){
      return false;
    }
  }
  ptr = before_ptr->next;  
  before_ptr->next = ptr->next;   
  ptr->next = nullptr;
  val = ptr->val;
  this->count--;
  delete ptr;
  return true;
// consider the special case of deleting the first node and the last node
// Do not forget to set value.
}

/**
     * @brief Insert a value at a specified position in the list. The valid pos is in the range of 1 to count+1.
     * The value will be inserted before the node at the specified position. if pos = 1, the value will be inserted
     * at the front of the list. if pos = count+1, the value will be inserted at the rear of the list.
     * @param pos: position to insert the value at.
     * @param val: value to insert.
     * @return true: if the value was inserted.
     * @return false: if the value was not inserted because pos is out of the range.
     */
bool LinkedList::insertAt(int pos, T val) {
    //TODO: Add code here
    // check if the pos is valid first, then move the ptr to the rigth positon
  if(pos < 0 || pos > (count + 1)){
    return false;
  }
  if(pos == 0){
    this->addFront(val);
    return true;
  } 
  if(pos == count){
    this->addRear(val);
    return true;
  }
  Node *before_ptr = this->front;
  Node *ptr = new Node;
  ptr->val = val;
  this->count++;
  for(int i = (pos - 1); i > 0; i--){
    before_ptr = before_ptr->next;
    if(before_ptr->next == nullptr){
      return false;
    }
  }
  ptr->next = before_ptr->next;  
  before_ptr->next = ptr;   
  return true;
// consider the special case of inserting the first node and the last node
}

/**
 * @brief Copy Constructor to allow pass by value and return by value of a LinkedList
 * @param other LinkedList to be copied
 */
LinkedList::LinkedList(const LinkedList &other) {
// Start with an empty list
  front = nullptr;
  rear = nullptr;
  count = 0;
  Node *ptr = other.front;

  while(ptr != nullptr){
    this->addRear(ptr->val);
    ptr = ptr->next; 
    count++;
  }
// TODO: Add code here. Interate through the other list and add a new node to this list
// for each node in the other list. The new node should have the same value as the other node.
}

/**
 * @brief Overloading of = (returns a reference to a LinkedList)
 * @param other LinkedList to be copied
 * @return reference to a LinkedList
 */
LinkedList &LinkedList::operator=(const LinkedList &other) {
  if(this != &other) { // check if the same object
    int n = 0;
    int counter = 0;
// Delete all nodes in this list
  while(this->front != nullptr){
    this->deleteRear(n);
  }
  Node *ptr = other.front;
  while(ptr != nullptr){
    this->addRear(ptr->val);
    counter++;
    ptr = ptr->next; 
  }
  this->count = counter;
// Interate through the other list and add a new node to this list
// Be sure to set the front and rear pointers to the correct values
// Be sure to set the count to the correct value
  }
  return *this;
}
 