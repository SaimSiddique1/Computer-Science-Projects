/*****************************************
** File: Weapon.cpp
** Project: CMSC 202 Project 4, Fall 2024
** Author: Saim Siddique
** Date: 11/14/2024
** Section: Lecture: 20 Discussion: 21
** E-mail: saims1@umbc.edu
**
** This program controls the Weapon class
** 
***********************************************/

#include "Weapon.h"

// Name: Weapon(int damage) - Overloaded constructor
// Preconditions: None
// Postconditions: Can be used to populate weapon or child classes
Weapon::Weapon(int damage){
  m_damage = damage;
}

// Name: ~Weapon()
Weapon::~Weapon() {}


// Name: Attack()
// Preconditions: None
// Postconditions: Returns damage
int Weapon::Attack(){
  return m_damage;
}
// Name: GetDamage()
// Preconditions: None
// Postconditions: Returns damage
int Weapon::GetDamage(){
  return m_damage;
}

// Name: ImproveWeapon(int)
// Preconditions: None
// Postconditions: Increases m_damage of this weapon by the value passed
void Weapon::ImproveWeapon(int increase){
  m_damage = m_damage + increase;
}
