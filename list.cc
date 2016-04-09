/*
File: list.cc
Author: Georgios Kamaras
Purpose: list class member functions
*/
#include "list.h"   // include the respective header file

using namespace std;
/* list's constructor */
list::list(post& p){
  firstNode = new listNode(p);  // first node is initialized with the reference to a post passed as argument
  numOfNodes = 1;               // we have 1 node in our list
  cout << "List has just been created!" << endl;    // list's construction message
}
/* list's destructor */
list::~list(){
  cout << "List is about to be destroyed" << endl;  // list's destruction message
  delete firstNode;               // delete pointer to the list's first node
}
/* insert a node, in the front of the list */
void list::pushFront(post& p){
  listNode* n = new listNode(p);  // construct a new list node, initialized with the reference to a post passed as argument
  n->next = firstNode;         // new list node's next node, is gonna be the current list's first node
  firstNode = n;               // new list's first node is the just constructed node
  numOfNodes++;                // we have one more node in our list
}
/* print the list */
void list::print() const{
  if(!numOfNodes) cout << "No posts." << endl; // if there are 0 zero nodes, there are no posts
  else{
    listNode* temp = firstNode;     // have a temporary pointer to node (for iterating the list)
		while(temp != NULL){            // while we haven't reach the end of the list
			temp->data.print();           // print current's list node data (a post)
			temp = temp->next;            // point to the next list node
		}
  }
}
/* insert to a list the members of another list, essentially combine them */
void list::insertListOfPosts(list& l){
  if(!empty()){                     // if (*this) list is not empty
    listNode* temp = firstNode;     // temporary pointer to current (*this) list's first node
    while(temp->next != NULL) temp = temp->next;  // reach to the end of (*this) list
    temp->next = l.firstNode;       // connect l's last node with (*this) list's first node
    numOfNodes += l.numOfNodes;     // add l's number of nodes to (*this) list's number of nodes
    l.numOfNodes = 0;               // l will have no nodes now
    l.firstNode = NULL; // "forget" l's firstNode, we don't care about l's integrity
  }                  // and we don't want problems with the list of the enhanced tree, or memory leaks
}
/* check if a list is empty */
int list::empty() const{
  return firstNode == NULL; // if firstNode == NULL, list is empty, so return 1, else return 0
}
