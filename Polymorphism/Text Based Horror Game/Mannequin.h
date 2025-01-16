#ifndef _MANNEQUIN_H_
#define _MANNEQUIN_H_

#include "Enemy.h"

// The Mannequin is a monster that looks like two fashion dummies stitched together, consisting of two pairs of legs.

//***Constants***
const int MANNEQUIN_SPECIAL = 2; //Base addition for Mannequin special attack

class Mannequin: public Enemy {
 public:
  // Name: Mannequin(string name, int health, int damage, string desc)
  // Description: Creates a new Mannequin
  // Preconditions: None
  // Postconditions: Creates a new Mannequin
  Mannequin(string, int, int, string);
  // Name: SpecialAttack
  // Description: Defines the Mannequin's special attack
  // Preconditions: None
  // Postconditions: Returns damage from special attack
  int SpecialAttack();
};
#endif
