#ifndef _GAME_H_ //Header guard
#define _GAME_H_ //Header guard

//Includes of required classes
#include "Area.h" //Manages area
#include "Hero.h" //Manages hero including name, health, xp, and weapon
#include "Enemy.h" //Manages name, health, damage, and description of enemies
#include "Creeper.h" //Specific type of Enemy
#include "Mandarin.h" //Specific type of Enemy
#include "Mannequin.h" //Specific type of Enemy
#include "Weapon.h" //Manages damage of base attack of weapons
#include "Plank.h" //Specific type of Weapon
#include "Chainsaw.h" //Specific type of Weapon
#include "Shotgun.h" //Specific type of Weapon

//Includes of required libraries
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

//************************Constants*********************
// HERO CONSTANTS
const int HERO_HEALTH = 8; //starting health for hero

//GAME CONSTANTS
const int START_AREA = 0; //starting area number
const char DELIMITER = '|'; //delimiter for input file (map file)
const int COST_IMPROVEMENT = 3; //experience points per 1 increase in damage
const int EXPERIENCE_WIN = 2; //number of experience points earned per win

// ENEMY CONSTANTS
const string CREEPER_NAME = "Creeper"; //creeper name
const string MANDARIN_NAME = "Mandarin"; //mandarin name
const string MANNEQUIN_NAME = "Mannequin"; //mannequin name
const int CREEPER_HEALTH = 10;  //starting health for creeper
const int MANDARIN_HEALTH = 12; //starting health for mandarin
const int MANNEQUIN_HEALTH = 14; //starting health for mannequin
const int CREEPER_DAMAGE = 3; //starting damage for creeper
const int MANDARIN_DAMAGE = 2; //starting damage for mandarin
const int MANNEQUIN_DAMAGE = 1; //starting damage for mannequin
const string CREEPER_DESC = "A large grotesque cockroach is here.";
const string MANDARIN_DESC = "A monster with a female-like figure bound in a garment that resembles a straitjacket and has grotesquely large arms lies here."; //mandarin desc
const string MANNEQUIN_DESC = "A monster that looks like two fashion dummies stitched together, consisting of two pairs of legs stands here.";
//******************************************************

class Game {
public:
  // Name: Game(string filename) - Overloaded Constructor
  // Description: Creates a new Game
  // Preconditions: None
  // Postconditions: Initializes all game variables to defaults (constants)
  // including m_myHero (null), m_curEnemy (null), filename (passed value),
  // and starting area (START_AREA)
  Game(string);
  // Name: ~Game
  // Description: Destructor
  // Preconditions: None
  // Postconditions: Deallocates anything dynamically allocated
  //                 in Game (weapons, enemies, and map)
  ~Game();
  // Name: LoadMap()
  // Description: Dynamically creates areas and inserts them into
  //              the m_myMap vector. Use getlines and delimiters.
  // Note: the size of the map is not known - you should not use constants
  //       Also, you can use stoi to convert strings to integers
  // Precondition: m_filename is populated
  // Postcondition: Map is populated with area objects.
  void LoadMap();
  // Name: HeroCreation()
  // Description: Populates m_myHero and asks name (can have spaces in name)
  // Preconditions: None
  // Postconditions: m_myHero is populated (and m_name in m_myHero)
  void HeroCreation();
  // Name: Look()
  // Description: Displays the current area's description and
  //              the current enemy's desc (if there is one) otherwise, says
  //              "It is peaceful here."
  // Preconditions: None
  // Postconditions: None
  void Look();
  // Name: StartGame()
  // Description: Welcomes the player to the game. Calls LoadMap, HeroCreation,
  //              Randomizes an enemy, Look, and Action
  // Preconditions: Input file must exist
  // Postconditions: Map is loaded, User has chosen a hero to play with,
  //                 prints the starting area, chooses a random enemy
  //                 and calls action
  void StartGame();
  // Name: Action()
  // Description: Menu for game. Displays menu.
  //              Player can look, move, attack, improve weapon, stats, or quit
  //              Can only attack if there is actually a enemy in this area
  // Preconditions: Everything in start has been completed
  // Postconditions: Game continues until quit or player dies in during attack
  void Action();
  // Name: RandomEnemy()
  // Description: Used to dynamically allocated a random enemy
  //            (25% chance of nothing, 25% chance of Creeper, 25% of Mandarin, and
  //            25% of Mannequin.)
  // Preconditions: None
  // Postconditions: Populates m_curEnemy (sets to nullptr if nothing)
  void RandomEnemy();
  // Name: ImproveWeapon
  // Description: Allows user to improve their weapon
  // Preconditions: First checks to see if they have enough xp to improve.
  //                If they have xp, for each COST_IMPROVEMENT, damage in the
  //                weapon increases by one (permanently)
  // Postconditions: m_curHero's weapon is improved
  void ImproveWeapon();
  // Name: Move
  // Description: Asks a player which direction they would like to move.
  //              Moves player from one area to another (updates m_curArea)
  //              Once successfully moved, chooses a new random enemy and
  //              Calls Look
  // Preconditions: Must be valid move (area must exist)
  // Postconditions: Displays area information and new monster
  void Move();
  // Name: Attack
  // Description: Allows player to attack an enemy.
  // Preconditions: Must have enemy Enemy in current area
  // Postconditions: Checks to make sure that there is an enemy to fight.
  //                 Asks the user if they want to use a normal or special attack
  //                 Updates health(hp) as battle continues.
  //                 Both Hero and Enemy attack every round until
  //                 one or more has <= 0 health
  //                 May need to deallocate enemy Enemy to prevent memory leaks.
  //                 When either Enemy or Hero <= 0 health, calls ProcessBattle
  //                 Returns true if hero still alive else false
  bool Attack();
  // Name: Stats()
  // Description: Displays the information about the hero (name, health, xp)
  // Preconditions: None
  // Postconditions: None
  void Stats();
  // Name: ProcessAttack
  // Description: Called when either the enemy or hero have no health left
  //       Displays who won (Enemy, Hero, mutual destruction)
  //       If hero wins, gives EXPERIENCE_WIN and resets health to starting value
  // Preconditions: Enemy or hero are <= 0 health
  // Postconditions: Returns true if hero is alive else false
  bool ProcessAttack(bool enemyAlive, bool alive);
private:
  vector<Area*> m_myMap; // Vector for holding all areas in game
  Hero* m_myHero; // Hero pointer for Hero (Player)
  int m_curArea; // Current area that player (Hero) is in
  Enemy* m_curEnemy; // Current enemy loaded for current area
  string m_filename; //Name of the input file for the map (holds area objects)
};

#endif
