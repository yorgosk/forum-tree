/*
File: date.h
Author: Georgios Kamaras
Purpose: date struct description
*/
#include <iostream> // for cout, endl
#include <iomanip> // for setfill(char_type), setw(int) functions
#include "generator.h"

struct date {
  void set();   // set pseudorandom date and time
  void setManually(int, int, int, int, int);    // set a specific date and time
  void get(int&, int&, int&, int&, int&) const; // get date and time
  void print() const;               // print date and time
private:
  int minute, hour, day, month, year;   // date and time's data
};
