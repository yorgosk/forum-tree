/*
File: post.cc
Author: Georgios Kamaras
Purpose: post class member functions
*/
#include "post.h"

using namespace std;
/* post class constructor */
post::post(){
  id = setID();             // set post's ID
  title = generateTitle();  // generate post's title
  creator = setRandomCreator(); // generate post's creator
  dateOfCreation.set();         // set post's date and time of creation
  text = setRandomText();       // generate post's text
  print();  // after construction, print post's data... so, basically print the post
}
/* post class destructor */
post::~post(){
  cout << "Post number: " << id << " is about to be destroyed" << endl; // print destruction message
}
/* print post */
void post::print() const{
  cout << "ID = " << id << ", Title: " << title << ", Creator: " << creator << endl; // print post's id, title, creator
  dateOfCreation.print();     // print post's date and time of creation
  cout << "Text: " << endl << text << endl;   // print post's text
}
/* get post's creator */
string post::getCreator() const{
  return creator;
}
/* get post's ID */
int post::getID() const{
  return id;
}
/* get post's date and time of creation */
void post::getDateOfCreation(int& minute, int& hour, int& day, int& month, int& year) const{
  dateOfCreation.get(minute, hour, day, month, year);
}
