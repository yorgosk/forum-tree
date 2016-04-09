/*
File: thread.cc
Author: Georgios Kamaras
Purpose: thread class member functions
*/
#include "thread.h"

using namespace std;
/* thread class constructor */
thread::thread(){
  int minute, hour, day, month, year;
  POSTNUM = setNumberOfPosts(); // generate a pseudorandom number of posts
  postArr = new post[POSTNUM];  // dynamically create the threads' array, with the above number of posts
  subject = generateSubject();  // generate a subject for this post
  creator = postArr[0].getCreator();  // thread's creator is the creator of it's first post
  postArr[0].getDateOfCreation(minute, hour, day, month, year); // get the date and time of creation of thread's first post
  dateOfCreation.setManually(minute, hour, day, month, year); // thread's dateOfCreation is the dateOfCreation of it's first post
  cout << "Thread with subject: " << subject << " has just been created!" << endl; // print thread's construction message
}
/* thread class destructor */
thread::~thread(){
  cout << "Thread with subject: " << subject << " is about to be destroyed" << endl;  // print thread's destruction message
  delete[] postArr; // delete the dynamically created posts' array
}
/* print the thread */
void thread::print() const{
  int i;
  cout << "Subject: " << subject << ", Creator: " << creator << endl; // print thread's subject and creator
  dateOfCreation.print(); // print when the thread was created
  for(i = 0; i < POSTNUM; i++) postArr[i].print();  // print each of the thread's posts
}
/* get thread's subject */
string thread::getSubject() const{
  return subject;
}
/* search (and print) a post that has a specific ID */
bool thread::searchPostByID(int id) const{
  int i;
  bool f = false;   // to know if we printed the post
  for(i = 0; i < POSTNUM; i++)  // for each one of the thread's posts
    if(postArr[i].getID() == id){ // if a post's ID matches with the requested one
      postArr[i].print();     // print that post
      f = true;     // we printed the post
      break;        // no need to search further
    }

  return f;       // return search's result (true if post was found, false if not)
}
/* get thread's creator */
string thread::getCreator() const{
  return creator;
}
/* get thread's array of posts */
post* thread::getPostArr(){
  return postArr;
}
/* get thread's number of posts */
int thread::getPostNum() const{
  return POSTNUM;
}
