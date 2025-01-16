/*****************************************
** File: Shotgun.cpp
** Project: CMSC 202 Project 4, Fall 2024
** Author: Saim Siddique
** Date: 11/14/2024
** Section: Lecture: 20 Discussion: 21
** E-mail: saims1@umbc.edu
**
** This program controls the shotgun class which is a sub class of weapon
** 
***********************************************/

#include "Shotgun.h"
// Name: Shotgun(int damage)
// Preconditions: None
// Postconditions: Can create a Shotgun
Shotgun::Shotgun(int damage) : Weapon(damage){}

// Name: SpecialAttack
// Preconditions: None
// Postconditions: Returns damage from special attack
int Shotgun::SpecialAttack(){
  cout << "You fire both barrels of the shotgun." << endl;
  // gets a random number between getdamage and 1
  int randAttack = (rand() % GetDamage()) + 1;
  // multiplies the random number by 2
  int randTotalAttack = randAttack * 2;
  return randTotalAttack;
}

// Name: GetName()
// Preconditions: None
// Postconditions: Returns name of weapon (shotgun)
string Shotgun::GetName(){
  string name = "shotgun";
  return name;
}