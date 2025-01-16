/*****************************************
** File: NavigationEntry.cpp
** Project: CMSC 202 Project 5, Fall 2024
** Author: Saim Siddique
** Date: 12/1/2024
** Section: Lecture: 20 Discussion: 21
** E-mail: saims1@umbc.edu
**
** This program defines the navigation entry class
** 
***********************************************/

#include "NavigationEntry.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Default Constructor
NavigationEntry::NavigationEntry(){
  // sets our memebers to default values
  m_url = "";
  m_timeStamp = 0;
}

// Name: NavigationEntry (Overloaded constructor)
// Preconditions: None
// Postconditions: Creates a new NavigationEntry object
NavigationEntry::NavigationEntry(const string& url, const int& timestamp){
  // sets our members to the provided info
  m_url = url;
  m_timeStamp = timestamp;
}

// Accessor for URL
string NavigationEntry::GetURL() const{
  return m_url;
}

// Accessor for Timestamp
int NavigationEntry::GetTimeStamp() const{
  return m_timeStamp;
}

// Mutator for URL
void NavigationEntry::SetURL(const string& url){
  m_url = url;
}

// Mutator for Timestamp
void NavigationEntry::SetTimeStamp(const int& time){
  m_timeStamp = time;
}

// Name: IsEmpty
// Preconditions: None
// Postconditions: Returns true if m_url is empty else false
bool NavigationEntry::IsEmpty() const{
  return m_url.empty();
}

// Name: Overloaded <<
// Preconditions: None
// Postconditions: Returns an ostream with output of a navigation entry
ostream& operator<<(ostream& os, NavigationEntry& entry) {
  os << "URL:" << entry.GetURL() 
      << " Visited On: " << entry.DisplayTimeStamp(entry.GetTimeStamp());
  return os;
}