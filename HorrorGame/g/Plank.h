#ifndef _PLANK_H_
#define _PLANK_H_

#include "Weapon.h"

// The wooden plank is a basic piece of wood used to bash enemies.
// It's special attack bashes and does between 1 and m_damage (twice)
// For example, if m_damage is 4 then it would could do 2 and 4 for a total of 6

class Plank: public Weapon {
 public:
  // Name: Plank(int damage)
  // Description: Creates a new Plank
  // Preconditions: None
  // Postconditions: Can create a Plank
  Plank(int);
  // Name: SpecialAttack
  // Description: Defines the Plank's special attack
  // Preconditions: None
  // Postconditions: Returns damage from special attack
  int SpecialAttack();
  // Name: GetName()
  // Description: Returns the name of the weapon (plank)
  // Preconditions: None
  // Postconditions: Returns name of weapon (plank)
  string GetName();
};
#endif
