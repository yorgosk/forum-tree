/*
File: thread.h
Author: Georgios Kamaras
Purpose: thread class description
*/
#ifndef __THREAD__  // macro guards to avoid the problem of double inclusion
#define __THREAD__

#include <iostream> // for cout, endl, strings
#include "post.h"   // for post class and whatever else is linked in it's header file
/* thread's class description */
class thread{
private:
  std::string subject;  // thread's subject
  std::string creator;  // thread's creator
  date dateOfCreation;  // thread's date and time of creation (pseudorandom)
  int POSTNUM;          // number of thread's posts (pseudorandom)
  post* postArr;        // an array of the thread's posts
public:
  thread();   // thread class constructor
  ~thread();  // thread class destructor
  void print() const;   // print the thread
  std::string getSubject() const;   // get thread's subject
  bool searchPostByID(int) const;   // search (and print) a post that has a specific ID
  std::string getCreator() const;   // get thread's creator
  post* getPostArr();               // get thread's array of posts
  int getPostNum() const;           // get thread's number of posts
};

#endif
