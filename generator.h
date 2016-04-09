/*
File: generator.h
Author: Georgios Kamaras
Purpose: generator.cpp functions' declarations and constants' definitions
*/
#ifndef __GENERATOR__ // macro guards to avoid the problem of double inclusion
#define __GENERATOR__

#include <string>
#include <cstdlib>
#include <ctime>
/* definitions of constant integers and arrays of strings */
const int MAXTHREADNUM = 10;   // maximum number of generated threads
const int MAXPOSTNUM = 10;     // maximum number of generated posts
/* if at any case the above maximum numbers are changed (upwards), user should take care of adding
  extra elements to the following arrays and modifying their codes if necessary */
/* array of subjects */
const std::string subjectArr[] = {"Rules and useful information", "Exercise 1 Subject", "Exercise 2 Subject",
                                        "Course Project Subject", "Exercise 1 Support", "Exercise 2 Support",
                                        "Team project Support", "Deadline extension requests", "Various Subjects", "Older Posts"};
/* array of creators */
const std::string creatorArr[] = {"Costas", "George", "Jane", "John", "Ioanna", "Eva", "Mike",
                                          "Javier", "Manos", "Maria"};
/* array of titles */
const std::string titleArr[] = {"Title 1.", "Title 2.", "Title 3.", "Title 4.", "Title 5.",
                                    "Title 6.", "Title 7.", "Title 8.", "Title 9.", "Title 10."};
/* array of texts */
const std::string textArr[] = {"Text 1.", "Text 2.", "Text 3.", "Text 4.", "Text 5.", "Text 6.",
                                      "Text 7.", "Text 8.", "Text 9.", "Text 10."};
/* functions' declarations */
void initializeGenerator();    // initialize random seed
int setNumberOfThreads();      // set a pseudorandom number of threads
int setNumberOfPosts();        // set a pseudorandom number of posts/thread
void generateDateAndTime(int&, int&, int&, int&, int&); // generate pseudorandom date and subject
std::string generateSubject();    // set a random subject, from subjects' array
std::string setRandomCreator();   // set a random creator, from creators' array
std::string generateTitle();      // set a random title, from titles' array
std::string setRandomText();      // set a random text, from texts' array
int setID();                      // set a unique ID
int generateRandomID();           // generate a random ID

#endif
