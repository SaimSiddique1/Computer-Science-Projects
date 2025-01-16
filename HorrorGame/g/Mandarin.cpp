/*****************************************
** File: Mandarin.cpp
** Project: CMSC 202 Project 4, Fall 2024
** Author: Saim Siddique
** Date: 11/14/2024
** Section: Lecture: 20 Discussion: 21
** E-mail: saims1@umbc.edu
**
** This program handles our Mandarin class which is a sub class of enemy
** 
***********************************************/
#include "Mandarin.h"

// Name: Mandarin(string name, int health, int damage, string desc)
// Description: Creates a new Mandarin
// Preconditions: None
// Postconditions: Can create a Mandarin
Mandarin::Mandarin(string name, int health, int damage, string desc) : Enemy(name, health, damage, desc){}

// Name: SpecialAttack
// Description: Defines the Mandarin's special attack
// Preconditions: None
// Postconditions: Returns damage from special attack
int Mandarin::SpecialAttack(){
  cout << "The Mandarin hammers you with their large arms!" << endl;
  return MANDARIN_SPECIAL;
}