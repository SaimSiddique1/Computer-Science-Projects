/*****************************************
** File: Browser.cpp
** Project: CMSC 202 Project 5, Fall 2024
** Author: Saim Siddique
** Date: 12/1/2024
** Section: Lecture: 20 Discussion: 21
** E-mail: saims1@umbc.edu
**
** This program defines the Browser class
** 
***********************************************/

#include "Browser.h"
#include <iostream>
#include <ctime>

using namespace std;

// Name: Browser (Overloaded constructor)
// Preconditions: None
// Postconditions: Sets m_fileName and m_currentPage to nullptr
Browser::Browser(string filename){
  // sets m_filename to filename
  m_fileName = filename;
  // sets m_currentPage to nullptr
  m_currentPage = nullptr;
}


// Name: ~Browser (Destructor)
// Preconditions: None
// Postconditions: Deallocates all dynamically allocated memory
Browser::~Browser(){
  // Deletes all entries in the back stack
  while (!m_backStack.IsEmpty()){
    delete m_backStack.Pop();
  }

  // Deletes all entries in the forward stack
  while (!m_forwardStack.IsEmpty()){
      delete m_forwardStack.Pop();
  }

  // Deletes the current page if it exists
  if (m_currentPage != nullptr){
    delete m_currentPage;
    m_currentPage = nullptr;
  }
}


// Name: StartBrowser
// Preconditions: None
// Postconditions: Menu keeps running until exited
void Browser::StartBrowser(){
  // calls loadfile
  LoadFile();
  // sets our current page
  NavigationEntry currentPage = GetCurrentPage();
  cout << "Current Website: " << endl;
  // couts our current page
  cout << currentPage << endl;
  // calls menu
  Menu();
}


// Name: Menu
// Preconditions: None
// Postconditions: When exiting, thanks user.
void Browser::Menu(){
  int choice = 0;
  // bool for if our program should be running
  bool on = true;
  cout << "Welcome to the Browser History Simulator" << endl;
  while (on) {
    // prints our menu
    cout << "\nWhat would you like to do?" << endl;
    cout << "1. Display browsing history" << endl;
    cout << "2. Go back" << endl;
    cout << "3. Go forward" << endl;
    cout << "4. Visit Site" << endl;
    cout << "5. Quit" << endl;
    cin >> choice;

    switch (choice) {
      case 1:
        Display();
        break;
      case 2:
        Back(1);
        break;
      case 3:
        Forward(1);
        break;
      case 4:
        NewVisit();
        break;
      case 5:
        // sets on to false to exit the menu
        on = false;
      default:
        break;
    }

    if (on){
      // Displays current page after each action
      NavigationEntry currentPage = GetCurrentPage();
      cout << "Current Website: " << endl;
      cout << currentPage << endl;
    }
  }
  cout << "Thank you for using Browser History Simulator" << endl;
}


// Name: Visit
// Preconditions: None
// Postconditions: Adds things to m_backStack or m_currentPage
void Browser::Visit(const string& url, int timestamp){
  if (m_currentPage != nullptr){
    // extends the backstack by adding m_currentpage using the pop function
    m_backStack.Push(m_currentPage);
  }
  // sets the current page pointer to a dynamically allocated entry
  m_currentPage = new NavigationEntry(url, timestamp);
}


// Name: NewVisit
// Preconditions: None
// Postconditions: Adds new URL to m_backStack or m_currentPage
void Browser::NewVisit(){
  string userUrl;
  // asks the user for the url they wish to visit
  cout << "Enter the URL to visit: " << endl;
  cin >> userUrl;
  // code from browser.h
  auto now = chrono::system_clock::now();
  time_t nowAsTimeT = std::chrono::system_clock::to_time_t(now);
  int64_t timestamp = static_cast<int64_t>(nowAsTimeT);
  // calls visit using the timestamp and the user provided url
  Visit(userUrl, timestamp);

}

// Name: Display
// Preconditions: None
// Postconditions: None
void Browser::Display(){
  
  // handles the back stack
  cout << "\n**Back Stack**" << endl;
  // prints empty if the backstack is empty
  if (m_backStack.IsEmpty()){
    cout << "Empty" << endl;
  }else{
    int count = 0;
    // Copys the stack to keep it intact
    Stack<NavigationEntry*> tempBack = m_backStack;
    while (!tempBack.IsEmpty()){
      // Pops the top element
      NavigationEntry* entry = tempBack.Pop();
      // prints the URL in our backstack followed by the timestamps
      cout << ++count << ". URL: " << entry->GetURL()
        << " Visited On: " << entry->DisplayTimeStamp(entry->GetTimeStamp()) << endl;
    }
  }
  
  // handles the forward stack
  cout << "\n**Forward Stack**" << endl;
  if (m_forwardStack.IsEmpty()){
    cout << "Empty" << endl;
    cout << endl;
  }else{
    int count = 0;
    // Copys the stack to keep it intact
    Stack<NavigationEntry*> tempForward = m_forwardStack;
    while (!tempForward.IsEmpty()){
      // Pops the top element
      NavigationEntry* entry = tempForward.Pop();
      // prints the URL in our forward stack followed by the timestamps
      cout << ++count << ". URL: " << entry->GetURL()
        << " Visited On: " << entry->DisplayTimeStamp(entry->GetTimeStamp()) << endl;
    }
  cout << endl;
  }
}


// Name: Back (steps)
// Preconditions: m_backStack must not be empty.
// Postconditions: Rotates items as above
NavigationEntry Browser::Back(int steps){
  // checks if the backstack is not empty
  if (!m_backStack.IsEmpty()){
    // adds currentpage to forward stack
    m_forwardStack.Push(m_currentPage);
    // removes current page from backstack
    m_currentPage = m_backStack.Pop();

  }
  // returns deallocated currentpage
  return *m_currentPage;
}


// Name: Forward (steps)
// Preconditions: m_forwardStack must not be empty
// Postconditions: Rotates items as above
NavigationEntry Browser::Forward(int steps){
  // checks if the forwardstack is not empty
  if (!m_forwardStack.IsEmpty()){
    // adds currentpage to back stack
    m_backStack.Push(m_currentPage);
    // removes current page from forwardstack
    m_currentPage = m_forwardStack.Pop();

  }
  // returns deallocated currentpage
  return *m_currentPage;
}


// Name: GetCurrentPage
// Preconditions: None
// Postconditions: None
NavigationEntry Browser::GetCurrentPage() const{
  return *m_currentPage;
}


// Name: LoadFile
// Preconditions: None
// Postconditions: Adds things to m_backStack or m_currentPage
void Browser::LoadFile(){
  // loads the file to start reading
  ifstream myfile(m_fileName);

  if (myfile.is_open()){
    string url; // sets a url string
    string timestampString; // sets a time stamp string
    int timestamp; // sets a time stamp integer

    while (getline(myfile, url, DELIMITER) && getline(myfile, timestampString)){
      // converts timestamp string to integer
      timestamp = stoi(timestampString);
      // adds the read in url's using the visit functuon
      Visit(url, timestamp);
    }
    // closes the file
    myfile.close();
  }
}
