/*****************************************
** File: Line.cpp
** Project: CMSC 202 Project 3, Fall 2024
** Author: Saim Siddique
** Date: 10/31/2024
** Section: Lecture: 20 Discussion: 21
** E-mail: saims1@umbc.edu
**
** This file implements the line class, which represents a metro line wit a linked list of stops.
** The class manages the stops as a linked list, allowing fro dynamic insertion and traversal.
** 
***********************************************/


#include "Line.h"
// constant
const string DEFAULT = "default";

// Name: Line() - Default Constructor
// Preconditions: None
// Postconditions: Sets everything to either nullptr or 0
Line::Line(){
  m_head = nullptr; //First stop of the line (head of linked list)
  m_tail = nullptr; //Last stop of the line (tail of linked list)
  m_totalStops = 0; //Total stops on the line (size of linked list)
  m_lineName = DEFAULT;
}

// Name: Line() - Overloaded Constructor
// Preconditions: None
// Postconditions: Sets everything to either nullptr or 0
Line::Line(string line){
  m_head = nullptr; //First stop of the line (head of linked list)
  m_tail = nullptr; //Last stop of the line (tail of linked list)
  m_totalStops = 0; //Total stops on the line (size of linked list)
  m_lineName = line;
}

// Name: ~Line - Destructor
// Preconditions: Line must have nodes
// Postconditions: Line will be empty and m_head and m_tail
//                  will be nullptr
Line::~Line(){
  Stop* current = m_head;
  while (current != nullptr){
    Stop* temp = current;
    current = current -> GetNext();
    delete temp;
  }
  // sets our pointers to nullpointers
  m_head = nullptr;
  m_tail = nullptr;
  m_totalStops = 0;
}

// Name: GetLineName
// Preconditions: Line must have a name
// Postconditions: Returns m_lineName;
string Line::GetLineName(){
  return m_lineName;
}

// Name: AddStop()
// Preconditions: Line allocated and data for stop available
// Postconditions: New stop inserted in end of line
void Line::AddStop(int number, string name){
  // creates a new stop, which is a part of our linked list
  Stop* newStop = new Stop(number, name);
  if (m_head == nullptr){
    // if the linked list is at the end (meaning connected to nullpt), it rather gets linked to newstop
    m_head = newStop;
    m_tail = newStop;
  }else{
    // links our tail to our new stop
    m_tail -> SetNext(newStop);
    m_tail = newStop;
  }
  // increments our total stops by 1
  m_totalStops++;
}

// Name: PrintLineDetails()
// Preconditions: Line allocated and data for next stop available
// Postconditions: Displays list of each stop on a line
//                 including number, name, and (lineName)
void Line::PrintLineDetails() {
  // iterates our full loop up until we reach a nullptr
  for (Stop* current = m_head; current != nullptr; current = current->GetNext()) {
    // Print the stop's number, name, and line name in the specified format.
    cout << current->GetNumber() << ". " << current->GetName() << " (" << GetLineName() << ")" << endl;
  }
}

// Name: CalculateDistance(string start, string end)
// Preconditions: Line allocated with start and stop on correct line
// Postconditions: Returns number of stops between two stations
int Line::CalculateDistance(string start, string end) {
  Stop* current = m_head; // initializes current pointer to head of linked list
  int startIndex = -1;
  int endIndex = -1;
  int index = 0;
  
  // Transverse the linked list up until nullptr
  while (current != nullptr){
    // if current stop is the start, sets startindex to the current one
    if (current->GetName() == start){
      startIndex = index;
    }
    // checks if current stop is the end stop, if so sets end index to the current index
    if (current->GetName() == end){
      endIndex = index;
    }
    // moves to the next stop in the list 
    current = current->GetNext();
    // increments the index counter
    index++;
  }
  
  // returns the distance between start and end if start index is before end index
  if (startIndex != -1 && endIndex != -1 && startIndex < endIndex){
    return endIndex - startIndex + 1;
  // OTHERWISE its reversed, therefore we do the opposite
  }else{
    return startIndex - endIndex + 1;
  }
  
  return 0;
}

// Name: ReverseLine (ONLY REQUIRED FOR EXTRA CREDIT)
// Preconditions: Line has been completed
// Postconditions: Reverses this line in place (no new nodes)
void Line::ReverseLine(){
  int count = 0;
  Stop* prev = nullptr;
  Stop* current = m_head;
  Stop* next = nullptr;

  while (current != nullptr){
    // stores our next stop
    next = current -> GetNext();
    // Reverses our current stops pointer by setting it equal to previous
    current -> SetNext(prev); 
    prev = current;
    current = next;
    count++;
  }
  // updates our head to the new first stop
  m_head = prev;
  m_stopCount = count;

}

int Line::GetStopCount() {
  // Returns the number of stops reversed
  return m_stopCount; 
}