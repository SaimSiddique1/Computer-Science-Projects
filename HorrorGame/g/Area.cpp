/*****************************************
** File: Area.cpp
** Project: CMSC 202 Project 4, Fall 2024
** Author: Saim Siddique
** Date: 11/14/2024
** Section: Lecture: 20 Discussion: 21
** E-mail: saims1@umbc.edu
**
** This program defines the area class which handles making a new areas for the game
** 
***********************************************/
#include "Area.h"

//Name: Area (Overloaded Constructor)
//Precondition: Must have valid input for each part of a area
// North, East, South, and West
//Postcondition: Creates a new area
Area::Area(int ID, string name, string desc, int north, int east, int south, int west){
  m_ID = ID;  // initializes ID
  m_name = name;  // initializes name
  m_desc = desc;  // initializes desc
  // initializes elements in the array
  m_direction[n] = north;
  m_direction[e] = east;
  m_direction[s] = south;
  m_direction[w] = west;
}

//Name: GetName
//Precondition: Must have valid area
//Postcondition: Returns area name as string
string Area::GetName(){
  return m_name;
}

//Name: GetID
//Precondition: Must have valid area
//Postcondition: Returns area id as int
int Area::GetID(){
  return m_ID;
}

//Name: GetDesc
//Precondition: Must have valid area
//Postcondition: Returns area desc as string
string Area::GetDesc(){
  return m_desc;
}

//Name: CheckDirection
//Precondition: Must have valid area
//Postcondition: Returns id of area in that direction if the exit exists
int Area::CheckDirection(char myDirection){
  direction chosenPath;
  // switch statement to handle different directions we can travel in
  switch(myDirection){
    case 'n': case 'N':
      chosenPath = n; 
      break;
    case 'e': case 'E':
      chosenPath = e; 
      break; 
    case 's': case 'S':
      chosenPath = s;
      break;  
    case 'w': case 'W':
      chosenPath = W;
      break;   
  }
  if (m_direction[chosenPath] == -1){
    // returns -1 if invalid path
    return -1;
  }else{
    // returns pathID if valid path
    return m_direction[chosenPath];
  }
}

//Name: PrintArea
//Precondition: Area must be complete
//Postcondition: Outputs the area name, area desc, then possible exits
void Area::PrintArea(){
  // prints out our location details
  cout << m_name << endl;
  cout << m_desc << endl;
  cout << "Possible Exits: ";
    for (unsigned int i = 0; i < W + 1; i++){
    if (m_direction[i] != -1){
      // loops through our array and prints out the valid locations we can travel to
      if (i == N){
        cout << "N ";
      }else if (i == E){
        cout << "E ";
      }else if (i == S){
        cout << "S ";
      }else if (i == W){
        cout << "W ";
      }
    }
  } cout << endl;
}