#ifndef _SHOTGUN_H_ //Header guard
#define _SHOTGUN_H_ //Header guard

#include "Weapon.h"

// The Shotgun is double barrelled gun.
// Chooses a random number between 1 and m_damage once then returns result*2
// If m_damage is 6, it would do two times between 1 and 6 so maybe 4 * 2

class Shotgun: public Weapon {
 public:
  // Name: Shotgun(int damage)
  // Description: Creates a new Shotgun
  // Preconditions: None
  // Postconditions: Can create a Shotgun
  Shotgun(int);
  // Name: SpecialAttack
  // Description: Defines the Shotgun's special attack
  // Preconditions: None
  // Postconditions: Returns damage from special attack
  int SpecialAttack();
  // Name: GetName()
  // Description: Returns the name of the weapon (shotgun)
  // Preconditions: None
  // Postconditions: Returns name of weapon (shotgun)
  string GetName();
};
#endif
