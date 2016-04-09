/*
File: generator.cc
Author: Georgios Kamaras
Purpose: Date and Time, Subject, Creator, ID, Title, Text
          and "random" ID generation for Objective 4 functions
*/
#include "generator.h"

using namespace std;
/* an integer that increments whenever an ID is requested (becoming the new ID, thus always being unique) */
static int newID = 0;
/* initialize random seed for generator */
void initializeGenerator(){
  srand(time(NULL));
}
/* set a pseudorandom number of threads */
int setNumberOfThreads(){
  int random;
  // generate random number between 1 and MAXTHREADNUM:
  random = rand() % MAXTHREADNUM + 1;

  return random;
}
/* set a pseudorandom number of posts/thread */
int setNumberOfPosts(){
  int random;
  // generate random number between 1 and MAXPOSTNUM:
  random = rand() % MAXPOSTNUM + 1;

  return random;
}
/* generate pseudorandom date and subject */
void generateDateAndTime(int& minute, int& hour, int& day, int& month, int& year){
  /* generate random minute(0-60), hour(0-24), day(0-31), month(1-12), year(2012-2015) */
  minute = rand() % 61;
  hour = rand() % 25;
  day = rand() % 32;
  month = rand() % 12 + 1;
  year = rand() % 4 + 2012;
}
/* set a random subject, from subjects' array */
string generateSubject(){
  static int currentThread = 0; // to know for which thread we are generating subject
  return subjectArr[currentThread++]; // we use a deterministic assignment method because subjects must be unique
}
/* set a random creator, from creators' array */
string setRandomCreator(){
  int random;
  /* generate random number between 0 and 9 (so, inside the limits of creators' array): */
  random = rand() % 10;

  return creatorArr[random];
}
/* set a random title, from titles' array */
string generateTitle(){
  static int currentPost = 0; // to know for which post we are generating title
  return titleArr[(currentPost++)%10]; // %10, because we want the titles of posts to differ per thread, 5 is the length of titleArr[]
}
/* set a random text, from texts' array */
string setRandomText(){
  int random;
  /* generate random number between 0 and 9 (so, inside the limits of texts' array): */
  random = rand() % 10;

  return textArr[random];
}
/* set a unique ID */
int setID(){
  return ++newID;
}
/* generate a random ID */
int generateRandomID(){
  int random;;
  /* generate random number between 1 and newID: */
  random = rand() % newID + 1;

  return random;
}
