/*
File: post.h
Author: Georgios Kamaras
Purpose: post class description
*/
#ifndef __POST__  // macro guards to avoid the problem of double inclusion
#define __POST__

#include <iostream> // for cout, endl, strings
#include "date.h"   // for date struct and whatever else is linked in it's header file
#include "generator.h"  // for our generator functions
/* post's class description */
class post{
private:
  int id;         // post's ID
  std::string title;    // post's title
  std::string creator;  // post's creator
  date dateOfCreation;  // post's date and time of creation (pseudorandom)
  std::string text;     // post's text
public:
  post();     // post class constructor
  ~post();    // post class destructor
  void print() const;   // print post
  std::string getCreator() const; // get post's creator
  int getID() const;    // get post's ID
  void getDateOfCreation(int&, int&, int&, int&, int&) const; // get post's date and time of creation
};

#endif
