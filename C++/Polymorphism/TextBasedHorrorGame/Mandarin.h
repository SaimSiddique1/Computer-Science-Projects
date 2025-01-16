#ifndef _MANDARIN_H_
#define _MANDARIN_H_

#include "Enemy.h"

/* Mandarins are monsters with a female-like figure bound in a garment that resembles a straightjacket and has grotesquely large arms.
*/

//***Constants***
const int MANDARIN_SPECIAL = 3; //Base for Mandarin special attack

class Mandarin: public Enemy {
 public:
  // Name: Mandarin(string name, int health, int damage, string desc)
  // Description: Creates a new Mandarin
  // Preconditions: None
  // Postconditions: Can create a Mandarin
  Mandarin(string, int, int, string);
  // Name: SpecialAttack
  // Description: Defines the Mandarin's special attack
  // Preconditions: None
  // Postconditions: Returns damage from special attack
  int SpecialAttack();
};
#endif
