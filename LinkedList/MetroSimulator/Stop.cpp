/*****************************************
** File: Stop.cpp
** Project: CMSC 202 Project 3, Fall 2024
** Author: Saim Siddique
** Date: 10/31/2024
** Section: Lecture: 20 Discussion: 21
** E-mail: saims1@umbc.edu
**
** This Stop class is a node class that represents each of the stops on a train
** line.
** 
***********************************************/

#include "Stop.h"
// Name: Stop - Default constructor
// Preconditions - None
// Postconditions - Creates a new Stop (for the Route)
Stop::Stop(){
  m_number = -1;
  m_name = "-1";
  m_next = nullptr;
}

// Name: Stop (number, name) - Overloaded Constructor
// Preconditions - Must have number and name to create new stop
// Postconditions - Creates a new Stop (for the Line)
Stop::Stop(int number, string name){
  m_number = number;
  m_name = name;
  m_next = nullptr;
}

// Name: GetNumber()
// Preconditions - None
// Postconditions - Returns a read-only m_number
int Stop::GetNumber(){
  return m_number;
}

// Name: GetName()
// Preconditions - None
// Postconditions - Returns a read-only m_name
string Stop::GetName(){
  return m_name;
}

// Name: GetNext()
// Preconditions - None
// Postconditions - Returns the pointer to the next stop
Stop* Stop::GetNext(){
  return m_next;
}

// Name: SetNext()
// Preconditions - Pointer has been defined
// Postconditions - Updates m_next to next stop on Route
void Stop::SetNext(Stop* newStop){
  m_next = newStop;
}