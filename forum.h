/*
File: forum.h
Author: Georgios Kamaras
Purpose: forum class description
*/
#ifndef __FORUM__   // macro guards to avoid the problem of double inclusion
#define __FORUM__

#include <iostream>   // for cout, endl, strings
#include "thread.h"   // for thread class and whatever else is linked in it's header file
#include "tree.h"     // for tree class and whatever else is linked in it's header file
/* forum's class description */
class forum{
private:
  std::string title;  // forum's title
  int THREADNUM;      // number of forum's threads (pseudorandom)
  thread* threadArr;  // an array of the forum's threads
public:
  forum(const std::string); // forum class constructor
  ~forum();                 // forum class destructor
  int getThreadNum() const; // get the number of forum's threads
  void print() const;       // print the forum
  void printSpecificThread(const std::string) const;  // print a specific forum's thread
  void printPostByID(int) const;  // print the forum's post with a specific ID
  void print_sorted();  // for Exercise 2, create tree, enhance it with other trees, print it
};

#endif
