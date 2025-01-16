#ifndef _CREEPER_H_
#define _CREEPER_H_

#include "Enemy.h"

//Creepers are an extremely large and aggressive cockroach.
//These critters will actively seek you out if you get close enough.

//***Constants***
const int CREEPER_SPECIAL = 4; //Base damage for Creeper special attack

class Creeper: public Enemy {
 public:
  // Name:  Creeper(string name, int health, int damage, string desc)
  // Description: Creates a new Creeper
  // Preconditions: None
  // Postconditions: Can create a Creeper
  Creeper(string, int, int, string);
  // Name: SpecialAttack
  // Description: Defines the Creeper's special attack
  // Preconditions: None
  // Postconditions: Returns damage from special attack
  int SpecialAttack();
};
#endif
