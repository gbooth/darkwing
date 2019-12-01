/**
 *@autor Wesley Waldern
 *@date 2019-11
 */
#include <Hero.h>
#include <Exceptions.h>
#include <string>
#include <utility>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

const int MAX_HERO_HP = 20;

Hero::Hero(): Person{3101}, weaponOfChoice{nullptr} {
  pos = std::make_pair(0, 0);
  Item* fist = new Item(4205);
  this->addInventory(fist, false);
  this->setWeapon(fist);
  this->setRef();
  this->setCommand();
}

Hero::~Hero() {
  for (auto it : inventory) {
    delete it.second.first;
    it.second.first = nullptr;
  }
}

void Hero::setWeapon(Item* w) {
  if (inventory.find(w->getID()) != inventory.end()
      && (w->getID()/100 % 10 == 2)) {
    if (weaponOfChoice == w) {
      std::cout << weaponOfChoice->getName()
                << " is already equipped." << std::endl;
    } else {
      weaponOfChoice = w;
    }
  } else {
    std::cout << "You don't have this weapon." << std::endl;
  }
}

Item* Hero::getWeapon() {
  return weaponOfChoice;
}

std::string Hero::inspect(Object* a) {
  if (a->getID()/100 == 23) {
    std::string str = a->getDesc();
    if (static_cast<Lever*>(a)->getState())
      str += " The lever is currently flipped down.\n";
    else
      str += " The lever is currently flipped up.\n";
    return str;
  } else {
    return a->getDesc();
  }
}

void Hero::mv(Direction a, Room** world) {
  int iPos = world[pos.first][pos.second].getDirection(a).second;
  iPos += (world[pos.first][pos.second].getDirection(a).first * 10);

  switch (iPos) {
  case -1:
    if (pos.first == 4 && pos.second == 0) {
      std::cout << "The drawbridge is raised, you cant pass it." << std::endl;
      break;
    } else if (pos.first == 3 && pos.second == 2) {
      std::cout << "A waterfall blocks your path." << std::endl;
      break;
    } else {
      std::cout << "The Door wont open and there is no keyhole." <<std::endl;
      break;
    }
  case -2:
    if (pos.first == 3 && pos.second == 1) {
      std::cout << "You are in the forest." <<std::endl;
      break;
    } else {
      std::cout << "The Door is locked" << std::endl;
      break;
    }
  case -11:
    std::cout << "You can't go that way." << std::endl;
    break;
  default:
    pos = world[pos.first][pos.second].getDirection(a);
    std::cout << "You are in the "
              << world[pos.first][pos.second].getMessage()
              << ".\n";
    break;
  }
}

void Hero::setPosition(std::pair<uint, uint> posi) {
  if (pos.first > 4  || pos.second > 4)
    throw invalid_pos("ERROR: position out of bounds");
  pos = posi;
}

std::pair<uint, uint> Hero::getPos() {
  return pos;
}

bool Hero::attack(Person* npc, Room** world) {
  int npcHealth = npc->getHealth();
  damageValue = 1 + weaponOfChoice->getItemValue();
  if (npc->getID() / 100 == 32) {
    std::cout << "The villagers take you off to jail for attacking one of them."
              << std::endl;
    this->lose(jail, world);
    return true;
  }
  if (npc->getID() / 100 == 33) {
    if (npcHealth <= 0) {
      std::cout << "The enemy is dead" << std::endl;
    } else if (npcHealth > 0 && health > 0) {
      npcHealth -= damageValue;
      std::cout << "You deal " << damageValue << " points of damage.\n";
      npc->setHealth(npcHealth);
    }
  }
  return false;
}

std::vector<std::pair<int, int>> Hero::invSave() {
  std::vector<std::pair<int, int>> l;
  for (auto it : inventory) {
    if (it.first != 4205)
      l.push_back(std::make_pair(it.first, it.second.second));
  }
  return l;
}

bool Hero::command(std::string s, Room** world) {
  std::transform(s.begin(), s.end(), s.begin(), ::tolower);
  std::string cmd = "", op = "";
  int i = this->getPos().first;
  int j = this->getPos().second;
  cmd = s.substr(0, s.find(' '));
  op = s.substr(s.find(' ')+1);
  if (!s.empty()) {
    if (cRefs.find(cmd) != cRefs.end()) {
      switch (cRefs[cmd]) {
      case Command::use: {
        auto it = refs.find(op);
        if (it != refs.end()) {
          if (it->second/100 == 41) { //its a potion
            auto itr = inventory.find(it->second);
            if (itr != inventory.end()) {
              this->usePotion(itr->second.first);
              break;
            }
          } else {
            if (op == "orange key") {
              auto it = refs.find(op);
              if (it != refs.end() && world[i][j].checkForObj(2201)) {
                RoomObject* lck = world[i][j].getObj(2201);
                Lock* l = static_cast<Lock*>(lck);
                auto itr = inventory.find(it->second);
                if (itr != inventory.end()) {
                  this->useKey(itr->second.first, l);
                  world[i][j].objChanged(l->getID());
                  break;
                }
              } else if (inventory.find(it->second) == inventory.end()) {
                std::cout << "You don't have that key." << std::endl;
                break;
              } else {
                std::cout << "This key can't be used right now.\n";
                break;
              }
            } else {
              if (op == "blue key") {
                auto it = refs.find(op);
                if (it != refs.end()&& world[i][j].checkForObj(2202)) {
                  RoomObject* lck = world[i][j].getObj(2202);
                  Lock* l = static_cast<Lock*>(lck);
                  auto itr = inventory.find(it->second);
                  if (itr != inventory.end()) {
                    this->useKey(itr->second.first, l);
                    world[i][j].objChanged(l->getID());
                    break;
                  }
                } else if (inventory.find(it->second) == inventory.end()) {
                  std::cout << "You don't have that key." << std::endl;
                  break;
                } else {
                  std::cout << "This key can't be used right now.\n";
                  break;
                }
              } else {
                if (op == "forest map") {
                  auto it = refs.find(op);
                  if (it != refs.end() && world[i][j].checkForObj(2203)) {
                    RoomObject* lck = world[i][j].getObj(2203);
                    Lock* l = static_cast<Lock*>(lck);
                    auto itr = inventory.find(it->second);
                    if (itr != inventory.end()) {
                      this->useKey(itr->second.first, l);
                      world[i][j].objChanged(l->getID());
                      break;
                    }
                  } else if (inventory.find(it->second) == inventory.end()) {
                    std::cout << "You don't have that key." << std::endl;
                    break;
                  } else {
                    std::cout << "This map can't be used right now.\n";
                    break;
                  }
                } else {
                  std::cout<< "This isn't a usable item." << std::endl;
                  break;
                }
              }
            }
          }
        } else {
          std::cout << "That is not the name of an item." << std::endl;
          break;
        }
      }
      case Command::flip: {
        auto it = refs.find(op);
        if (it->second/100 == 23 &&  it != refs.end()
            && world[i][j].checkForObj(it->second)) {
          RoomObject* const robj = world[i][j].getObj(it->second);
          if (this->interact(robj))
            world[i][j].objChanged(it->second);
          if (op == "bone lever") {
            std::cout << "You hear the sound of heavy rocks moving "
                      << "\nsomewhere south of you and the sound of"
                      << "splashing in the distance";
            if (robj->getState())
              std::cout << " stops.\n";
            else
              std::cout << " starts.\n";
          } else if (op == "mossy lever") {
            std::cout << "That sound again...you suspect "
                      << "a door might be open elsewhere."
                      << std::endl;
          } else if (op != "stone lever") {
            std::cout  << "Hmm, that's strange, you "
                       << "don't hear anything happen."
                       << std::endl;
          }
        } else {
          std::cout << "You can't flip that." << std::endl;
        }
        if (it->second == 2307)
            system("firefox https://www.youtube.com/watch?v=Ll82POMkb8g");
        break;
      }
      case Command::inspect: {
        if (op == "room") {
          std::cout << this->inspect(&world[i][j]) << std::endl;
          break;
        }
        auto it = refs.find(op);
        if (it != refs.end()) {
          if (it->second/100 == 32) { //its a villager
            if (world[i][j].checkForNPC(it->second)) {
              Person* const p = world[i][j].getNPC(it->second);
              Object* o = p;
              std::cout << this->inspect(o) << std::endl;
              break;
            } else {
              std::cout << op << " is not in the room.\n";
              break;
            }
          } else if (it->second/1000 == 2) { //its a roomobject
            if (world[i][j].checkForObj(it->second)) {
              RoomObject* r = world[i][j].getObj(it->second);
              Object* a = r;
              std::cout << this->inspect(a) << std::endl;
            } else {
              std::cout << "This "<< op << " is not in the room.\n";
            }
            break;
          } else { //its an item
            auto itr = inventory.find(it->second);
            if (itr!= inventory.end()) {
              Object* pt = itr->second.first; //item*
              std::cout << this->inspect(pt) << std::endl;
            }
          }
        } else {
          std::cout << "you can't inspect that" << std::endl;
        }
        break;
      }
      case Command::attack: {
        auto it = refs.find(op);
        if (it->second/1000 == 3 && it != refs.end()
            && world[i][j].checkForNPC(it->second)) {
          Person* const eny = world[i][j].getNPC(it->second);
          if (this->attack(eny, world))
            return true;
        } else if (it->second/1000 == 1
                   || it->second /1000 == 2 || it->second == 4) {
          std::cout << "your " << weaponOfChoice->getName()
                    << " bounces off the "
                    << world[i][j].getObj(it->second)->getName()
                    << " and hits you in the face.\n";
          if (getHealth() -1 <= 0) {
            std::cout << "The great duck god quackri saves you and tells you "
                      "\nthat you have more important "
                      "\nthings to be doing." << std::endl;
          } else {
            this->setHealth(this->getHealth() - 1);
            std::cout << "You take 1 point of damage.\n";
            std::cout << "Your current health is now: "
                      << this->getHealth() << std::endl;
          }
        } else {
          if (op == "attack")
            std::cout << "Attack what?\n";
          else
            std::cout << op << " is not in the area." << std::endl;
        }
        break;
      }
      case Command::go: {
        if (op == "north") {
          mv(north, world);
          break;
        } else if (op == "south") {
          mv(south, world);
          break;
        } else if (op == "east") {
          mv(east, world);
          break;
        } else if (op == "west") {
          mv(west, world);
          break;
        } else {
          std::cout << "That is not a direction." << std::endl;
          break;
        }
      }
      case Command::talk: {
        auto it = refs.find(op);
        if (it != refs.end() && world[i][j].checkForNPC(it->second)) {
          if (it->second/100 == 31 || it->second/100 == 33) {
            std::cout << "You can't talk to this person." << std::endl;
            break;
          }
          Person* prn = world[i][j].getNPC(it->second);
          Villager* v = static_cast<Villager*>(prn);
          if (v->getID() == 3207 && this->getHealth() < MAX_HERO_HP) {
            this->setHealth(MAX_HERO_HP);
            std::cout << "You now have full health." << std::endl;
          }
          if (this->talk(v, world))
            return true;
        } else {
          std::cout << "This person isn't here." << std::endl;
          break;
        }
        break;
      }
      case Command::open: {
        auto it = refs.find(op);
        if (it != refs.end() && (it->second/100 == 21)
            && world[i][j].checkForObj(it->second)) {
          RoomObject* const rmb = world[i][j].getObj(it->second);
          if (rmb->getState()) {
            std::cout << "That chest is already open.\n";
            break;
          }
          this->interact(rmb);
          world[i][j].objChanged(it->second);
        } else {
          std::cout << "You can't open that." << std::endl;
        }
        break;
      }
      case Command::equip: {
        if (op == "equip") {
          std::cout  << "Your weapon: "
                     << this->getWeapon()->getName() << std::endl;
          break;
        } else {
          auto it = refs.find(op);
          if (it->second / 100 == 42) {
            if (it != refs.end()) {
              auto ptr = inventory.find(it->second);
              if (this->getWeapon()->getName() == op) {
                this->setWeapon(ptr->second.first);
              } else {
                this->setWeapon(ptr->second.first);
                std::cout << "Your weapon of choice is: "
                          << this->getWeapon()->getName()
                          << std::endl;
              }
            }
          } else {
            std::cout << op << " isn't an equipable item." << std::endl;
          }
          break;
        }
      }
      case Command::help: {
        this->help();
        break;
      }
      case Command::inv: {
        this->getInventory();
        break;
      }
      case Command::save: {
        Save s(this, world);
        s.saveGame();
        break;
      }
      }
    } else {
      std::cout <<"I didn't catch that, perhaps you need HELP."
                <<"\nType help for available commands."
                << std::endl;
    }
  }
  return false;
}

void Hero::getInventory() {
  std::cout << "HP: " << getHealth() << std::endl;
  std::cout << "Equipped Weapon: " << getWeapon()->getName() << std::endl;
  std::cout << "Items" << std::setw(30)
            << std::setfill(' ') << "Amount" << "\n";
  std::cout << std::setw(36) << std::setfill('*') << "\n";
  for (auto it : inventory)
    std::cout << std::left << std::setw(20) << std::setfill('-')
              << it.second.first->getName() << std::setw(15)
              << std::setfill('-') << std::right
              << it.second.second << std::endl;
}

void Hero::addInventory(Item* a, bool messSup) {
  if (messSup)
    std::cout << a->getName()
              << " has been added to your inventory!" << std::endl;
  int itemID = a->getID();
  if (inventory.find(itemID) == inventory.end())
    inventory[itemID] = std::make_pair(a, 1);
  else
    inventory[itemID].second++;
}

void Hero::usePotion(Item* a) {
  int potionID = a->getID();
  if (health == MAX_HERO_HP) {
    std::cout << "You are already at full health." << std::endl;
  } else if (health + a->getItemValue() > MAX_HERO_HP) {
    health = MAX_HERO_HP;
    inventory[potionID].second--;
    std::cout << "The potion healed you for "
              << a->getItemValue() << std::endl;
  } else {
    health += a->getItemValue();
    inventory[potionID].second--;
    std::cout << "The potion healed you for "
              << a->getItemValue() << std::endl;
  }
  if (inventory[potionID].second == 0) {
    delete a;
    inventory.erase(potionID);
  }
}

void Hero::setRef() {
  std::ifstream file;
  std::string line;
  std::string name;
  int idVar;
  file.open("identifierMap.csv");
  if (file.is_open()) {
    while (!file.eof()) {
      std::getline(file, line, ':');
      if (std::stoi(line)/1000 == 1) {
        file.ignore(1000, '\n');
        continue;
      }
      idVar = std::stoi(line);
      std::getline(file, line, ':');
      std::transform(line.begin(), line.end(), line.begin(), ::tolower);
      name = line;
      refs[name] = idVar;
      std::getline(file, line);
      //file.ignore(1000, '\n');
    }
  } else {
    std::cout <<"file not open" << std::endl;
  }
}

void Hero::setCommand() {
  cRefs["use"] = Command::use;
  cRefs["inspect"] = Command::inspect;
  cRefs["inventory"] = Command::inv;
  cRefs["talk"] = Command::talk;
  cRefs["go"] = Command::go;
  cRefs["attack"] = Command::attack;
  cRefs["flip"] = Command::flip;
  cRefs["open"] = Command::open;
  cRefs["help"] = Command::help;
  cRefs["equip"] = Command::equip;
  cRefs["save"] = Command::save;
}

void Hero::useKey(Item* a, Lock* l) {
  l->unlock(a->getID());
}

bool Hero::talk(Villager* v, Room** world) {
  if (v->getID() == 3208 && inventory.find(4303) == inventory.end()) {
    if (v->riddle()) {
      std::cout << "Correct! Here, take this map to the woods."
                << "You'll likely get lost without it."
                << std::endl;
      Item* mapKey = new Item(4303);
      this->addInventory(mapKey, true);
    } else {
      std::cout << v->getName()
                << " looks at you with great disappointment. "
                << "A wave of his hands opens the ground"
                << "beneath your feet and you die!\n";
      this->lose(riddle, world);
      return true;
    }
  } else {
    v->response();
  }
  return false;
}

void Hero::help() {
  std::string output;
  std::ifstream helpFile("help.txt");

  if (helpFile.is_open())
    getline(helpFile, output, '*');
  else
    throw file_error("help file missing");
  std::cout << output;
}

bool Hero::interact(RoomObject* const r) {
  if (r->getID() != 2301) {
    if (r->getID() / 100 % 10 == 3 && r->getID() / 1000 == 2) {
      r->setState(!r->getState());
      std::cout << "The Lever has been flipped" << std::endl;
      return true;
    } else if (r->getID() / 100 % 10 == 1 && r->getID() / 1000 == 2) {
      if (!r->getState()) {
        Item* a = static_cast<Chest*>(r)->getContents();
        this->addInventory(a, true);
        return true;
      }
    } else {
      std::cout << "This is not a Chest, nor is it a Lever." << std::endl;
      return false;
    }
  } else {
    Lever* lev = static_cast<Lever*>(r);
    std::vector<std::pair<Lever*, bool>> depLever = lev->getDepLever();
    if ((!depLever[0].first->getState() && !depLever[0].second)
        && (depLever[1].first->getState() && depLever[1].second)
        && (depLever[2].first->getState() && depLever[2].second)) {
      lev->setState(!lev->getState());
      std::cout << "The Lever has been flipped" << std::endl;
      std::cout << "The draw bridge lowers." << std::endl;
      return true;
    } else {
      std::cout << "When you attempt to flip the lever it feels as "
                << "though something is preventing the lever from "
                << "flipping. Perhaps you need to do something else first?\n";
      return false;
    }
  }
}

void Hero::lose(GitGud l, Room** world) {
  switch (l) {
  case riddle: {
    std::cout << "You've offended Sirius Quack and he is very serious about "
              << "that.\n\nGame Over.\n";
    break;
  }
  case ducked: {
    std::cout << "You've been slain by a duck.\n\nGame Over.\n";
    break;
  }
  case moronUser: {
    std::cout << "Standing around when fighting a duck can get you killed..."
              << " and it did.\n\nGame Over.\n";
    break;
  }
  case stalactite: {
    std::cout << "You've been impaled by a falling stalactite. How unfortuna"
              << "te.\n\nGame Over.\n";
    break;
  }
  case jail: {
    std::cout << "Who would've ever thought attempted murder would land you"
              << " in jail?\n\nGame Over.\n";
    break;
  }
  case friends: {
    std::cout << "You and Firequacker walk back to the castle exchanging a"
              << "necdotes of instances the wizard had been a jerky pants."
              << "\n Upon arriving at the castle the guards attack and kil"
              << "l you and Firequacker with a barrage of arrows, ballista"
              << "e, and spears.\n I guess the guards dont like wooden duc"
              << "ks the size of a dragon nor their friends.\n\nGame over."
              << "\n";
    break;
  }
  }
  for (int i = 0; i < 5; i++)
    delete [] world[i];
  delete [] world;
  world = nullptr;
}

void Hero::win(Room** world) {
  std::cout << "As you stike your final blow, Firequacker shrieks a terrible r"
            << "oar quack and falls to the floor. You rush over to free your c"
            << "aptive mentor in the corner of the chamber. As you help him to"
            << " his feet you both notice Firequacker has transformed back int"
            << "o a wooden duck. \n\n\"Thank you for freeing me Duck Norris.\""
            << " the wizard coughs as he stumbles over to Firequacker. \n\n\"H"
            << "ow big do you think we can make him this time Norris?\" asks t"
            << "he wizard as he picks Firequacker up from the cave floor\n"
            << "You Win. Congratulations!!\n";
  for (int i = 0; i < 5; i++)
    delete [] world[i];
  delete []world;
  world = nullptr;
}

void Hero::reset() {
  this->setPosition(std::make_pair(0, 0));
  this->setHealth(MAX_HERO_HP);
  if (this->getWeapon()->getID() != 4205)
    this->setWeapon(inventory[4205].first);
  for (auto it : inventory) {
    if (it.first != 4205) {
      delete it.second.first;
      inventory.erase(it.first);
    }
  }
}
