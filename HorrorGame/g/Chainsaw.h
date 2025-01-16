#ifndef _CHAINSAW_H_ //Header guard
#define _CHAINSAW_H_ //Header guard

#include "Weapon.h"

// The Chainsaw is a mechanical weapon with a moving blade.
// It's special attack shreds and does between 1/2 m_damage and 2.5x damage
// For example, if m_damage is 7, it would do between 3 and 17 (round down)

class Chainsaw: public Weapon {
 public:
  // Name: Chainsaw(int damage)
  // Description: Creates a new Chainsaw
  // Preconditions: None
  // Postconditions: Can create a Chainsaw
  Chainsaw(int);
  // Name: SpecialAttack
  // Description: Defines the Chainsaw's special attack
  // Preconditions: None
  // Postconditions: Returns damage from special attack
  int SpecialAttack();
  // Name: GetName()
  // Description: Returns the name of the weapon (chainsaw)
  // Preconditions: None
  // Postconditions: Returns name of weapon (chainsaw)
  string GetName();
};
#endif
