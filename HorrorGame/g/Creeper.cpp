/*****************************************
** File: Creeper.cpp
** Project: CMSC 202 Project 4, Fall 2024
** Author: Saim Siddique
** Date: 11/14/2024
** Section: Lecture: 20 Discussion: 21
** E-mail: saims1@umbc.edu
**
** This program handles our Creeper class which is a sub class of enemy
** 
***********************************************/
#include "Creeper.h"
// Name:  Creeper(string name, int health, int damage, string desc)
// Preconditions: None
// Postconditions: Can create a Creeper
Creeper::Creeper(string name, int health, int damage, string desc) : Enemy(name, health, damage, desc){}

// Name: SpecialAttack
// Preconditions: None
// Postconditions: Returns damage from special attack
int Creeper::SpecialAttack(){
  cout << "A Creeper takes a large bite out of you!" << endl;
  return CREEPER_SPECIAL;
}