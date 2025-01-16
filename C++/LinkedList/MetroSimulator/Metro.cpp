/*****************************************
** File: Metro.cpp
** Project: CMSC 202 Project 3, Fall 2024
** Author: Saim Siddique
** Date: 10/31/2024
** Section: Lecture: 20 Discussion: 21
** E-mail: saims1@umbc.edu
**
** This file defines the metro class, which manages a metro system by loading lines and passengers
** from files/ This class provides a main menu for user interaction with the metro system.
** 
***********************************************/


#include "Metro.h"
//constant
const string DEFAULT = "default.txt";
const char DELIMETER = ',';
// Name: Metro (default constructor)
// Preconditions: None
// Postconditions: A new metro system is created.
Metro::Metro(){
  m_fileLines = DEFAULT; //sets to default 
  m_filePass = DEFAULT; //sets to default
  // calls load lines
  LoadLines();
  // calls load passes
  LoadPasses();
  // calls the main menu
  MainMenu(); 
}

// Name: Metro (overloaded constructor)
// Preconditions: Filename is included
// Postconditions: A new metro system is created with lines and
//                 passengers using passed input files
Metro::Metro(string fileLine, string filePass){
  m_fileLines = fileLine; // sets our given fileline
  m_filePass = filePass; // sets our given filepass
  // calls load lines
  LoadLines(); 
  // calls load passes
  LoadPasses();
  // calls the main menu
  MainMenu();
}

// Name:  Metro (destructor)
// Preconditions: None
// Postconditions: All lines (linked lists) are destroyed.
//                 All vectors are cleared out.
Metro::~Metro(){
  for (unsigned int i = 0; i < m_lines.size(); i++){
    // clears our dynamically allocated m_lines
    if (m_lines[i] != nullptr){
      delete m_lines[i];
      // sets the empty pointers to nullptrs
      m_lines[i] = nullptr;
    }
  }
  m_lines.clear();

  for (unsigned int i = 0; i < m_passengers.size(); i++){
    // clears our dynamically allocated m_passengers
    if (m_passengers[i] != nullptr){
      delete m_passengers[i];
      // sets the empty pointers to nullptrs
      m_passengers[i] = nullptr;
    }
  }
  m_passengers.clear();
}

// Name:  LoadLines
// Preconditions: Valid file name of lines
// Postconditions: Loads all lines in input file (can be many)
void Metro::LoadLines() {
  // reads through our given file
  ifstream myfile(m_fileLines);
  // code only runs if something gets read
  if(myfile.is_open()){
    int stopNumb; // int for our stop number
    string stopNumbString; // string to temporarily store our stop number before we convert it
    string lineName; // string for the line color
    string startLocation; // string for our locations

    // loops through our file and begins storing after two delimeters have been hit
    while (getline(myfile, stopNumbString, DELIMETER) && (getline(myfile, lineName, DELIMETER))
            && (getline(myfile, startLocation))){
      // string to integer for our stop number
      stopNumb = stoi(stopNumbString);
      // gets the index of where our line name is located
      int index = LineToIndex(lineName);
      // if index = -1 that means that it isnt present, therefore we make a newline and put it in our vector
      if (index == -1){
        Line* newLine = new Line(lineName);
        m_lines.push_back(newLine);
        index = m_lines.size() - 1;
      }
      m_lines[index] -> AddStop(stopNumb, startLocation);
    }
  }
}

// Name:  LoadPasses
// Preconditions: Valid file name of lines
// Postconditions: Loads all passengers in input file to m_passengers
void Metro::LoadPasses() {
  // same structure as our loadlines
  ifstream myfile(m_filePass);
  if(myfile.is_open()){
    int stopNumb;
    string stopNumbString;
    string lineName;
    string startLocation;
    string finalDestination; // string for final destination
    
    while (getline(myfile, stopNumbString, DELIMETER) && (getline(myfile, lineName, DELIMETER))
        && (getline(myfile, startLocation, DELIMETER)) && (getline(myfile, finalDestination))){
      
      stopNumb = stoi(stopNumbString);
      // creates a new passenger object, and dynamically allocates it using the new keyword
      Passenger* passenger = new Passenger(stopNumb, lineName, startLocation, finalDestination);
      // appends the object to the end of the vector
      m_passengers.push_back(passenger);
    }
  }
}

// Name: LineToIndex
// Preconditions: m_lines must be populated
// Postconditions: Returns the index of the line based on the name
int Metro::LineToIndex(string name){
  for (unsigned int i = 0; i < m_lines.size(); i++){
    // returns the index if it exists in our function, else returns -1
    if (m_lines[i] -> GetLineName() == name){
      return i;
    }
  }
  return -1;
}

// Name: MainMenu
// Preconditions: None
// Postconditions: When exit, quits program with no memory leaks or errors
void Metro::MainMenu(){
  int choice;
  cout << "*********************************" << endl;
  cout << "Welcome to the Metro System!" << endl;
  // do while loop for our main menu
  do {
    cout << "What would you like to do?:" << endl;
    cout << "1. Display Lines" << endl;
    cout << "2. Display Passengers" << endl;
    cout << "3. Calculate Earnings" << endl;
    cout << "4. Reverse Route" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    // switch statement for our main menu
    switch(choice){
      case 1:
        DisplayLines();
        break;
      case 2:
        DisplayPassengers();
        break;
      case 3:
        CalcEarnings();
        break;
      case 4:
        for (unsigned int i = 0; i < m_lines.size(); i++) {
          if (m_lines[i] != nullptr) {
            // calls reverse line for each element
            m_lines[i] -> ReverseLine();
            // gets the number for how many stops have been reversed
            cout << m_lines[i] -> GetStopCount() << " Stops reversed." << endl;
          }
        }
        break;
      case 5:
        cout << "Thank you for using the Metro" << endl;
        break;
      default:
        break;
    }
  } while(choice != 5);
}

// Name:  DisplayLines
// Preconditions: At least one line in m_lines;
// Postconditions: Displays details of each line in m_lines
void Metro::DisplayLines(){
  for (unsigned int i = 0; i < m_lines.size(); i++){
    // Assigns a pointer to the existing line instance at m_lines[j]
    Line* line = m_lines[i];
    // outputs what color we are on
    cout << "**" << line -> GetLineName() << " Line Stops**" << endl;
    // calls a function to print out the details
    line -> PrintLineDetails();
    cout << endl;
  }
}

// Name:  DisplayPassengers
// Preconditions: Has lines loaded and passengers loaded
// Postconditions: Displays informationo mn about each passenger
void Metro::DisplayPassengers(){
  for (unsigned int i = 0; i < m_lines.size(); i++){
    cout << endl;
    // prints out what color we are on
    cout << "*** " << m_lines[i] -> GetLineName() << " Line ***" << endl;
    for (unsigned int j = 0; j < m_passengers.size(); j++){
      // Assigns a pointer to the existing Passenger instance at m_passengers[j]
      Passenger* passenger = m_passengers[j];
      if (passenger -> GetLine() == m_lines[i] -> GetLineName()){
        // uses passenger inorder to print out all the passengers
        passenger -> DisplayPassenger();
      }
    }
  }
}

// Name:  CalcEarnings()
// Preconditions: Has lines and passengers loaded
// Postconditions: Displays line with stop data
void Metro::CalcEarnings(){
  int totalStops = 0; // declares an integer for our total number of stops
  for (unsigned int i = 0; i < m_lines.size(); i++){
    // Assigns a pointer to the existing line instance at m_lines[j]
    Line* line = m_lines[i];
    double lineEarnings = 0.0; // initializes our lineearnings variable as a double

    for (unsigned int j = 0; j < m_passengers.size(); j++){
      // Assigns a pointer to the existing Passenger instance at m_passengers[j]
      Passenger* passenger = m_passengers[j];
      if (passenger -> GetLine() == line -> GetLineName()){
        // gathers our stops and store it as an integer using our calculate distance function
        int stops = line -> CalculateDistance(passenger -> GetStartLocation(), passenger -> GetFinalDestination());
        // multiplies our stops by perstop inroder to get line earnings
        lineEarnings += stops * PER_STOP;
        totalStops += stops;
      }
    }
    // prints out the line color, followed by the amount of money made
    cout << "**" << line -> GetLineName() << " Line Total Earnings**" << endl;
    cout << '$' << lineEarnings << endl;
    cout << "Total Stops:" << totalStops << endl;
    cout << endl;
    // resets the total stops count for each of our different colors
    totalStops = 0;
  }
}