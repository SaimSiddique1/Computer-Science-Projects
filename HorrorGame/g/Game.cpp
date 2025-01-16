/*****************************************
** File: Game.cpp
** Project: CMSC 202 Project 4, Fall 2024
** Author: Saim Siddique
** Date: 11/14/2024
** Section: Lecture: 20 Discussion: 21
** E-mail: saims1@umbc.edu
**
** This program handles the Game class
** 
***********************************************/
#include "Game.h"

// Name: Game(string filename) - Overloaded Constructor
// Preconditions: None
// Postconditions: Initializes all game variables to defaults (constants)
Game::Game(string file){
  m_myHero = nullptr; // sets m_myHero to nullptr
  m_curEnemy = nullptr; // sets m_curEnemy to nullptr
  m_filename = file; // sets m_filename to file
  m_curArea = START_AREA; // sets m_curArea to START_AREA
}

// Name: ~Game
// Preconditions: None
// Postconditions: Deallocates anything dynamically allocated
Game::~Game(){
  // clears out our enemy pointer
  delete m_curEnemy;
  m_curEnemy = nullptr;

  // clears out our hero pointer
  delete m_myHero;
  m_myHero = nullptr;

  // iterates through our vector holding area pointers and clears our those area pointers
  for (unsigned int i = 0; i < m_myMap.size(); ++i){
    delete m_myMap[i];
    m_myMap[i] = nullptr;
  }
}

// Name: LoadMap()
// Precondition: m_filename is populated
// Postcondition: Map is populated with area objects.
void Game::LoadMap(){
  // ensures everything is empty prior to loading in areas
  for (unsigned int i = 0; i < m_myMap.size(); ++i){
    delete m_myMap[i];
  }

  ifstream myfile(m_filename);
  if (myfile.is_open()){
    // our ID storage
    int ID;
    string IDstring;
    // our name storage
    string name;
    // our description storage
    string desc;
    // our north storage
    int north;
    string northString;
    // our east storage
    int east;
    string eastString;
    // our south storage
    int south;
    string southString;
    // our west storage
    int west;
    string westString;

    // uses getline to read in the info needed from the myfile
    while (getline(myfile, IDstring, DELIMITER) && getline(myfile, name, DELIMITER) &&
      getline(myfile, desc, DELIMITER) && getline(myfile, northString, DELIMITER) &&
      getline(myfile, eastString, DELIMITER) && getline(myfile, southString, DELIMITER)
      && getline(myfile, westString, DELIMITER)){
        
        // converts the strings to the integers where we need them
        ID = stoi(IDstring);
        north = stoi(northString);
        east = stoi(eastString);
        south = stoi(southString);
        west = stoi(westString);

        Area* newArea = new Area(ID, name, desc, north, east, south, west);
        // appends our new areas to our vector
        m_myMap.push_back(newArea);
      }
  }
}

// Name: HeroCreation()
// Preconditions: None
// Postconditions: m_myHero is populated (and m_name in m_myHero)
void Game::HeroCreation(){
  string myHero;
  // gets the heros name
  cout << "Hero Name: ";
  getline(cin, myHero);

  // points m_myHero to a new hero
  m_myHero = new Hero(myHero, HERO_HEALTH);
}

// Name: Look()
// Preconditions: None
// Postconditions: None
void Game::Look(){
  // prints the area of our current area
  m_myMap[m_curArea]->PrintArea();
  if (m_curEnemy == nullptr){
    cout << "It is peaceful here." << endl;
  }else{
    // prints out the description when we are at a location
    cout << m_curEnemy->GetDesc() << endl;
  }
}

// Name: StartGame()
// Preconditions: Input file must exist
// Postconditions: Map is loaded, User has chosen a hero to play with,
void Game::StartGame(){
  // calls loadMap
  LoadMap();
  cout << "Silent Hill 2 Remake" << endl;
  // calls herocreation
  HeroCreation();
  cout << "You start with a " << m_myHero->GetWeaponName() << '!' << endl; 
  // calls randomenemy
  RandomEnemy();
  Look();
  Action();
}

// Name: Action()
// Preconditions: Everything in start has been completed
// Postconditions: Game continues until quit or player dies in during attack
void Game::Action(){
  int choice;
  bool gameOn = true;
  do{
    // prints the main menu
    cout << "What would you like to do?" << endl;
    cout << "1. Look" << endl;
    cout << "2. Move" << endl;
    cout << "3. Attack Enemy" << endl;
    cout << "4. Improve Weapon" << endl;
    cout << "5. Check Stats" << endl;
    cout << "6. Quit" << endl;
    cin >> choice;
    // uses a switch staatement to handle main menu commands
    switch(choice){
      case 1:
        Look();
        break;
      case 2:
        Move();
        break;
      case 3:
        gameOn = Attack();
        if (!gameOn)
          choice = 6;
        break;
      case 4:
        ImproveWeapon();
        break;
      case 5:
        Stats();
        break;
      case 6:
        break;
    }
  }while (choice != 6);
  cout << "Thank you for playing Silent Hill 2 Remake" << endl;
}

// Name: RandomEnemy()
// Preconditions: None
// Postconditions: Populates m_curEnemy (sets to nullptr if nothing)
void Game::RandomEnemy(){
  if (m_curEnemy != nullptr){
    delete m_curEnemy;
    m_curEnemy = nullptr;
  } 
  int randNumber = (rand() % 4) + 1;
  switch(randNumber){
    case 1:
      // creates a new creeper enemy
      m_curEnemy = new Creeper(CREEPER_NAME, CREEPER_HEALTH, CREEPER_DAMAGE, CREEPER_DESC);
      break;
    case 2:
      // creates new mandarin enemy
      m_curEnemy = new Mandarin(MANDARIN_NAME, MANDARIN_HEALTH, MANDARIN_DAMAGE, MANDARIN_DESC);
      break;
    case 3:
      // creates new mannequin enemy
      m_curEnemy = new Mannequin(MANNEQUIN_NAME, MANNEQUIN_HEALTH, MANNEQUIN_DAMAGE, MANNEQUIN_DESC);
      break;
    case 4:
      m_curEnemy = nullptr;
      break;
    default:
      m_curEnemy = nullptr;
      break;
  }
}

// Name: ImproveWeapon
// Preconditions: First checks to see if they have enough xp to improve.
// Postconditions: m_curHero's weapon is improved
void Game::ImproveWeapon(){
  // checks if we have enough XP
  if (m_myHero->GetExperience() < COST_IMPROVEMENT){
    cout << "You don't have enough money to improve your weapon." << endl;
  }else{
    int amount;
    bool valid = false;
    // retrieves how many levels we can use
    int levelsAvailable = m_myHero->GetExperience() / COST_IMPROVEMENT;
    while (!valid){
      cout << "How much would you like to Improve your weapon? (max " << levelsAvailable << ")." << endl;
      cin >> amount;
      if (amount <= levelsAvailable && amount > 0){
        // valid being true breaks us out of the loop
        valid = true;
      }
    }
    // improve our weapon by given amount
    m_myHero->ImproveWeapon(amount);
    cout << "You have improved your weapon by " << amount << " damage." << endl;
  }
}

// Name: Move
// Preconditions: Must be valid move (area must exist)
// Postconditions: Displays area information and new monster
void Game::Move(){
  char directionChar;
  int nextAreaID = -1;
  do{
    cout << "Which direction? (N E S W)" << endl;
    cin >> directionChar;
    if (directionChar == 'N' || directionChar == 'n' || 
        directionChar == 'E' || directionChar == 'e' ||
        directionChar == 'S' || directionChar == 's' ||
        directionChar == 'W' || directionChar == 'w') {
      // sets nextAreaID to our next area
      nextAreaID = m_myMap[m_curArea] -> CheckDirection(directionChar);
    }else{
      nextAreaID = -1;
    }

  }while (nextAreaID == -1);

  m_curArea = nextAreaID;
  // calls RandomEnemy
  RandomEnemy();
  // calls look
  Look();
}

// Name: Attack
// Preconditions: Must have enemy Enemy in current area
// Postconditions: Checks to make sure that there is an enemy to fight.
bool Game::Attack(){
  bool special = false; // boolean for if a special attack is used
  bool active = false; // boolean for if a fight has begun
  bool heroAlive = true; // boolean for if hero is alive
  bool enemyAlive = true; // boolean fofr of enemy is alive
  int heroHealth;
  int enemyHealth;
  if (m_curEnemy == nullptr){
    cout << "No enemy to fight. Continue on sir " << m_myHero->GetName() << endl;
    return true;
  }else{
    // retrieves our info needed from our enemy and hero pointers
    heroHealth = m_myHero->GetHealth();
    enemyHealth = m_curEnemy->GetHealth();

    int choice = 0;
    do{
      active = false;
      special = false;
      // displays our options in combat
      cout << "1. Punch Enemy" << endl;
      cout << "2. Use " << m_myHero->GetWeaponName() << endl;
      cin >> choice;

      switch(choice){

        case 1:
          active = true;
          special = false;
          break;
        case 2:
          active = true;
          // tells us that a special weapon for our hero is being used
          special = true; 
          break;
        default:
          break;
      }
      if (active == true){
        int damageToEnemy;
        // tells us if we're using the special attack
        if (special){
          damageToEnemy = m_myHero->SpecialAttack();
        }else{
          damageToEnemy = m_myHero->Attack();
        }
        cout << "It does " << damageToEnemy << " damage." << endl;
        // drains our enemies health accordingly
        enemyHealth = enemyHealth - damageToEnemy;

        // enemy turn to attack
        int enemyAttack;
        // randomizes to see if a special enemy attack will be used
        int specialEnemyAttack = (rand() % (COST_IMPROVEMENT + 1)) + 1;
        if (specialEnemyAttack == 1){
          enemyAttack = m_curEnemy->SpecialAttack();
          cout << "You take " << enemyAttack << " points of damage." << endl;
        }else{
          enemyAttack = m_curEnemy->Attack();
        }
        // drains our heros health accord
        heroHealth = heroHealth - enemyAttack;
        
        // total healths of each
        if (heroHealth > 0 && enemyHealth > 0){
          cout << m_myHero->GetName() << " Health: " << heroHealth << endl;
          cout << m_curEnemy->GetName() << ": Health: " << enemyHealth << " Damage: "
          << m_curEnemy->GetDamage() << endl;
        }

      }
    }while(heroHealth > 0 && enemyHealth > 0);
  }
  
  if (heroHealth <= 0){
    heroAlive = false;
  }
  if (enemyHealth <= 0){
    enemyAlive = false;
  }
  bool gameOn = ProcessAttack(enemyAlive, heroAlive);
  return gameOn;
}

// Name: Stats()
// Preconditions: None
// Postconditions: None
void Game::Stats(){
  cout << "Name: " << m_myHero->GetName() << endl;
  cout << "HP: " << m_myHero->GetHealth() << endl;
  cout << "Experience points: " << m_myHero->GetExperience() << endl;
}

// Name: ProcessAttack
// Preconditions: Enemy or hero are <= 0 health
// Postconditions: Returns true if hero is alive else false
bool Game::ProcessAttack(bool enemyAlive, bool alive){
  if (enemyAlive && !alive){
    cout << "You have been defeated. Try again!" << endl;
    // deallocates as the game is now over
    delete m_curEnemy;
    m_curEnemy = nullptr;
    return false;
  }
  if (!enemyAlive && alive){
    // handles our cout statements for winning the fight
    cout << "You have defeated the " << m_curEnemy->GetName() << "!" << endl;
    cout << "You have earned " << EXPERIENCE_WIN << " experience points." << endl;
    // sets our earned xp
    int newXP = m_myHero->GetExperience() + EXPERIENCE_WIN;
    m_myHero->SetExperience(newXP);
    m_myHero->SetHealth(HERO_HEALTH);
    // gets rid of the dead enemys
    delete m_curEnemy;
    m_curEnemy = nullptr;
  }
  if (!enemyAlive && !alive){
    cout << "You defeated each other at the same time!" << endl;
    // deallocates as the game is now over
    delete m_curEnemy;
    m_curEnemy = nullptr;
    return false;
  }
  return true;
}