/*****************************************
** File: Mannequin.cpp
** Project: CMSC 202 Project 4, Fall 2024
** Author: Saim Siddique
** Date: 11/14/2024
** Section: Lecture: 20 Discussion: 21
** E-mail: saims1@umbc.edu
**
** This program handles our Mannequin class which is a sub class of enemy
** 
***********************************************/

#include "Mannequin.h"
// Name: Mannequin(string name, int health, int damage, string desc)
// Description: Creates a new Mannequin
// Preconditions: None
// Postconditions: Creates a new Mannequin
Mannequin::Mannequin(string name, int health, int damage, string desc) : Enemy(name, health, damage, desc){}

// Name: SpecialAttack
// Description: Defines the Mannequin's special attack
// Preconditions: None 
// Postconditions: Returns damage from special attack
int Mannequin::SpecialAttack(){
  cout << "The mannequin smashes with their kick!" << endl;
  return MANNEQUIN_SPECIAL;
}