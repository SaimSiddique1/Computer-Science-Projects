/*****************************************
** File: Enemy.cpp
** Project: CMSC 202 Project 4, Fall 2024
** Author: Saim Siddique
** Date: 11/14/2024
** Section: Lecture: 20 Discussion: 21
** E-mail: saims1@umbc.edu
**
** This program handles the enemy class
** 
***********************************************/
#include "Enemy.h"
// Name: Enemy(string name, int hp, int damage, string desc)
// Preconditions: None
// Postconditions: Used to populate child class data
Enemy::Enemy(string name, int health, int damage, string desc){
  m_name = name; // Initializes m_name
  m_health = health; // Initializes m_health
  m_damage = damage; // Initializes m_damage
  m_desc = desc; // Initializes m_desc
}

// Name ~Enemy()
Enemy::~Enemy(){}


// Name: Attack()
// Preconditions: None
// Postconditions: Returns damage
int Enemy::Attack(){
  cout << m_name << " attacks!" << endl;
  return m_damage;
}

// Name: GetName()
// Preconditions: None
// Postconditions: Returns enemy name
string Enemy::GetName(){
  return m_name;
}

// Name: GetHealth
// Preconditions: None
// Postconditions: Returns enemy health
int Enemy::GetHealth(){
  return m_health;
}

// Name: SetHealth
// Description: Used to update enemy health (used for battle)
// Preconditions: None
// Postconditions: Updates enemy health
void Enemy::SetHealth(int doneDamage){
  m_health = m_health - doneDamage;
}

// Name: GetDamage
// Preconditions: None
// Postconditions: Returns enemy damage
int Enemy::GetDamage(){
  return m_damage;
}

// Name: GetDesc
// Preconditions: None
// Postconditions: Returns the description of the enemy
string Enemy::GetDesc(){
  return m_desc;
}

// Name: Overloaded <<
// Preconditions: None
// Postconditions: returns an ostream with output of enemy
ostream& operator<<(ostream& out, Enemy& enemy){
  out << "Enemy: " << enemy.m_name << endl;
  out << "Health: " << enemy.m_health << endl;
  out << "Power: " << enemy.m_damage << endl;
  out << "Description: " << enemy.m_desc << endl;
  return out;
}