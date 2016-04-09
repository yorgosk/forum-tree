/*
File: forum.cc
Author: Georgios Kamaras
Purpose: forum class member functions
*/
#include "forum.h"  // include the respective header file

using namespace std;
/* forum class constructor */
forum::forum(const string t) : title(t) { // initialize title with the string passed as argument
  THREADNUM = setNumberOfThreads(); // generate a pseudorandom number of threads
  threadArr = new thread[THREADNUM];  // dynamically create the threads' array, with the above number of threads
  cout << "Forum with title: " << title << " has just been created!" << endl; // print forum's construction message
}
/* forum class destructor */
forum::~forum(){
  cout << "Forum with title: " << title << " is about to be destroyed" << endl; // print forum's destruction message
  delete[] threadArr; // delete the dynamically created threads' array
}
/* get the number of forum's threads */
int forum::getThreadNum() const{
  return THREADNUM;   // return the number of forum's posts
}
/* print the forum */
void forum::print() const{
  int i;
  cout << "Forum: " << title << endl;   // forum's title
  for(i = 0; i < THREADNUM; i++) threadArr[i].print();  // print each thread
}
/* print a specific forum's thread */
void forum::printSpecificThread(const string subject) const{
  int i;
  for(i = 0; i < THREADNUM; i++)    // search all the threads
    if(!((threadArr[i].getSubject()).compare(subject))) // if you find the one with the requested subject
      threadArr[i].print(); // print it
}
/* print the forum's post with a specific ID */
void forum::printPostByID(int id) const{
  int i;
  for(i = 0; i < THREADNUM; i++)  // search all threads
    if(threadArr[i].searchPostByID(id)) // for the post with a specific ID (to print it)
      break;  // if you just found the post, there's no need to search further
}
/* for Exercise 2, create tree, enhance it with other trees, print it */
void forum::print_sorted(){
  /* Objective 1 */
  tree t(threadArr[0]);           // create a tree with the forum's first thread
  cout << endl;
  /* Objective 2 */
  if(THREADNUM > 1){              // if there are more than one threads
    int i;
    for(i = 1; i < THREADNUM; i++){ // for each one of the other threads
      tree* temp = new tree(threadArr[i]);    // create a temporary tree with this forum's thread
      t.enhance(*temp);                // add the temporary tree temp into tree t
      delete temp; // delete the tree pointer, so the destructor of the tree is called...
    }              // ...(this tree is destroyed - no memory problems, when creating the next one)
  }
  cout << endl;
  /* Objective 3 */
  t.print();      // print the enhanced tree
  cout << endl;
}
