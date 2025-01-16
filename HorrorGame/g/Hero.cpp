/*****************************************
** File: Hero.cpp
** Project: CMSC 202 Project 4, Fall 2024
** Author: Saim Siddique
** Date: 11/14/2024
** Section: Lecture: 20 Discussion: 21
** E-mail: saims1@umbc.edu
**
** This program handles the Hero class
** 
***********************************************/

#include "Hero.h"
// Name: Hero(string name, int health) - Overloaded Constructor
// Preconditions: None
// Postconditions: Used to populate hero (Link)
Hero::Hero(string name, int health){
  m_name = name; // sets m_name to name
  m_health = health; // sets m_health to health
  m_experience = 0; // sets m_experience to 0
  // calls randomweapon
  RandomWeapon();
}

// Name: ~Hero Destructor
// Preconditions: None
// Postconditions: Used to deallocate anything dynamically allocated
Hero::~Hero(){
  // frees our m_weapon data, and sets it equal to nullptr
  delete m_weapon;
  m_weapon = nullptr;
}

// Name: Attack()
// Preconditions: None
// Postconditions: Returns damage
int Hero::Attack(){
  return WEAPON_BASE;
}

// Name: GetName()
// Preconditions: None
// Postconditions: Returns the current name
string Hero::GetName(){
  return m_name;
}

// Name: SetName()
// Preconditions: None
// Postconditions: Updates m_name
void Hero::SetName(string name){
  m_name = name;
}

// Name: GetHealth()
// Preconditions: None
// Postconditions: Returns the health of the hero
int Hero::GetHealth(){
  return m_health;
}

// Name: SetHealth(int)
// Preconditions: None
// Postconditions: Updates m_health of the hero
void Hero::SetHealth(int health){
  m_health = health;
}

// Name: GetExperience()
// Preconditions: None
// Postconditions: Returns the experience of the hero
int Hero::GetExperience(){
  return m_experience;
}

// Name: SetExperience(int)
// Preconditions: None
// Postconditions: Updates m_experience of the hero
void Hero::SetExperience(int experience){
  m_experience = experience;
}

// Name: RandomWeapon
// Preconditions: Called when hero is instantiated
// Postconditions: Updates m_weapon to point at random weapon
void Hero::RandomWeapon(){

  int randNumber = (rand() % WEAPON_BASE) + 1;
  switch(randNumber){
    case 1:
      // sets m_weapon to a chainsaw
      m_weapon = new Chainsaw(WEAPON_BASE);
      break;
    case 2:
      // sets m_weapon to a plank
      m_weapon = new Plank(WEAPON_BASE);
      break;
    case 3:
      // sets m_weapon to a shotgun
      m_weapon = new Shotgun(WEAPON_BASE);
      break;
    default:
      break;
      //how would this even happen fr
  }
}

// Name: ImproveWeapon()
// Preconditions: None
// Postconditions: Increases m_weapon and decreases m_experience
void Hero::ImproveWeapon(int improvement){
  m_weapon->ImproveWeapon(improvement);
  m_experience = m_experience - (WEAPON_BASE * improvement);
}

// Name: SpecialAttack()
// Preconditions: None
// Postconditions: Used to attack an enemy using the weapon's special attack
int Hero::SpecialAttack(){
  // sets damage done to our special attack value
  int damageDone = m_weapon->SpecialAttack();
  return damageDone;
}

// Name: GetWeaponName()
// Preconditions: None
// Postconditions: Returns the name of the weapon held by the hero
string Hero::GetWeaponName(){
  // gets our names weapon
  string weaponName = m_weapon->GetName();
  return weaponName;
}

// Name: Overloaded <<
// Preconditions: None
// Postconditions: Returns an ostream with output of hero
ostream& operator<<(ostream& out, Hero& hero){
  out << "Hero: " << hero.GetName() << ", Health: " << hero.GetHealth();
  return out;
}