/*****************************************
** File: Passenger.cpp
** Project: CMSC 202 Project 3, Fall 2024
** Author: Saim Siddique
** Date: 10/31/2024
** Section: Lecture: 20 Discussion: 21
** E-mail: saims1@umbc.edu
**
** This file implements the passenger class, which manages information about metro passengers.
** The class provides access to the attributes within it, and holds the ability to
** easily display passenger information.
**
***********************************************/

#include "Passenger.h"

// Name: Passenger() 
// Preconditions: None
// Postconditions: Creates a new Passenger
Passenger::Passenger(){
  m_number = -1;
  m_line = "-1";
  m_startLocation = "-1";
  m_finalDestination = "-1";
}

// Name: Passenger(int, string, string, string)
// Preconditions: Passenger num, line, start, and end required
// Postconditions: Creates a new Passenger
Passenger::Passenger(int number, string line, string startLocation, string finalDestination){
  m_number = number;
  m_line = line;
  m_startLocation = startLocation;
  m_finalDestination = finalDestination;
}

// Name: GetNumber
// Preconditions: Passenger number required
// Postconditions: Returns passenger number
int Passenger::GetNumber(){
  return m_number;
}

// Name: GetLine
// Preconditions: Passenger line required
// Postconditions: Returns passenger line
string Passenger::GetLine(){
  return m_line;
}

// Name: GetStartLocation
// Preconditions: Passenger start location required
// Postconditions: Returns starting location
string Passenger::GetStartLocation(){
  return m_startLocation;
}

// Name: GetFinalDestination
// Preconditions: Passenger final destination required
// Postconditions: Returns final destination
string Passenger::GetFinalDestination(){
  return m_finalDestination;
}

// Name: DisplayPassenger
// Preconditions: Passenger data required
// Postconditions: Outputs passenger data
void Passenger::DisplayPassenger(){
    cout << "Passenger " << m_number << ": " << m_startLocation << " to " << m_finalDestination << endl;
}