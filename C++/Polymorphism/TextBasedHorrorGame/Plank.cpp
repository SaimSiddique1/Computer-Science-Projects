/*****************************************
** File: Plank.cpp
** Project: CMSC 202 Project 4, Fall 2024
** Author: Saim Siddique
** Date: 11/14/2024
** Section: Lecture: 20 Discussion: 21
** E-mail: saims1@umbc.edu
**
** This program controls the plank class which is a sub class of weapon
** 
***********************************************/

#include "Plank.h"

// Name: Plank(int damage)
// Preconditions: None
// Postconditions: Can create a Plank
Plank::Plank(int damage) : Weapon(damage){}

// Name: SpecialAttack
// Preconditions: None
// Postconditions: Returns damage from special attack
int Plank::SpecialAttack(){
  cout << "You bash twice with your plank!" << endl;
  // gets a random number between getdamage and 1
  int firstAttack = (rand() % GetDamage()) + 1;
  int secondAttack = (rand() % GetDamage()) + 1;
  // adds the two random numbers together
  int totalAttack = firstAttack + secondAttack;
  return totalAttack;
}

// Name: GetName()
// Preconditions: None
// Postconditions: Returns name of weapon (plank)
string Plank::GetName(){
  string name = "plank";
  return name;
}