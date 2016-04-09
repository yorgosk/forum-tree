/*
File: date.cc
Author: Georgios Kamaras
Purpose: date struct member functions
*/
#include "date.h"

using namespace std;
/* set pseudorandom date and time */
void date::set(){
  int minute, hour, day, month, year;
  /* generate random minute(0-60), hour(0-24), day(0-31), month(1-12), year(1970-2015) */
  generateDateAndTime(minute, hour, day, month, year);
  /* assign generated values */
  this->minute = minute;
  this->hour = hour;
  this->day = day;
  this->month = month;
  this->year = year;
}
/* set a specific date and time, passed by arguments */
void date::setManually(int minute, int hour, int day, int month, int year){
  this->minute = minute;
  this->hour = hour;
  this->day = day;
  this->month = month;
  this->year = year;
}
/* get date and time, using reference */
void date::get(int& minute, int& hour, int& day, int& month, int& year) const{
  minute = this->minute;
  hour = this->hour;
  day = this->day;
  month = this->month;
  year = this->year;
}
/* print date and time */
void date::print() const{
  cout << "Created at " << day << "/" << month << "/" << year << ", " << setfill('0') << setw(2) << hour << ":" << setfill('0') << setw(2) << minute << endl;
}
