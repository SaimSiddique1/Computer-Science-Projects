/*****************************************
** File: Chainsaw.cpp
** Project: CMSC 202 Project 4, Fall 2024
** Author: Saim Siddique
** Date: 11/14/2024
** Section: Lecture: 20 Discussion: 21
** E-mail: saims1@umbc.edu
**
** This program handles our chainsaw class, which is a subclass of weapon
** 
***********************************************/
#include "Chainsaw.h"
const double MAX = 2.5;
const double MIN = 0.5;
// Name: Chainsaw(int damage)
// Preconditions: None
// Postconditions: Can create a Chainsaw
Chainsaw::Chainsaw(int damage) : Weapon(damage){}
// Name: SpecialAttack
// Preconditions: None
// Postconditions: Returns damage from special attack
int Chainsaw::SpecialAttack(){
  cout << "Your chainsaw shreds the enemy!" << endl;
  // multiplies our damage by 2.5 for our maxdamage
  int maxDamage = GetDamage() * MAX;
  // muliplies our damage by .5 for our mindamage
  int minDamage = GetDamage() * MIN;
  // gets a random number between our max damage and our min damage
  int specDamage = minDamage + rand() % (maxDamage - minDamage + 1);
  // returns the random number
  return specDamage;
}

// Name: GetName()
// Preconditions: None
// Postconditions: Returns name of weapon (chainsaw)
string Chainsaw::GetName(){
  string name = "chainsaw";
  return name;
}