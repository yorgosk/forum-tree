/*
File: main.cc
Author: Georgios Kamaras
Purpose: main function of OOP Project 1, Exercise 2
*/
#include "forum.h"  // all header files that we need are there, or can be found from there on (through linking)

using namespace std;  // we have discussed that putting "using namespace something" in header files is generally a bad choice/practise
                      // ... so I avoid it in the whole Exercise 2 solution (same for Exercise 1)

int main(void){
  /* initialize random seed for generator: */
  initializeGenerator();
  // Exercise 2, objective 1
  forum f("Object Oriented Programming"); // create our forum
  cout << endl;
  // Exercise 2, objective 2
  f.print_sorted();   // create a tree with forum's first thread, enhance it...
  cout << endl;         // ...with the trees of the other threads, print it in inorder

  return 0;
}
