/*
File: list.h
Author: Georgios Kamaras
Purpose: list class and listNode struct descriptions
*/
#include <iostream>   // for cout, endl
#include "post.h"     // for post class and whatever else is linked in it's header file
/* list's class description */
class list{
private:
  struct listNode{  // struct listNode, so it's members are public by default -> I use less functions
    post& data;           // reference to a forum's post, which is our listNode's data
    listNode* next;       // pointer to the next node
    /* listNode's constructor */
    listNode(post& p) : data(p), next(NULL) {
      std::cout << "List node has just been created!" << std::endl; // listNode construction message
    }
    /* listNode's destructor */
    ~listNode(){
      std::cout << "List node is about to be destroyed" << std::endl; // listNode destruction message
      delete next;        // delete next node
    }
  };
  listNode* firstNode;  // pointer to the list's first node
  int numOfNodes; // how many nodes we have in our list, I didn't need/use it, but some other user may want to
public:
  list(post&);                   // list's constructor
  ~list();                       // list's destructor
  void pushFront(post&);         // insert a node, in the front of the list
  void print() const;            // print the list
  void insertListOfPosts(list&); // insert to a list the members of another list, essentially combine them
  int empty() const;             // check if a list is empty
};
