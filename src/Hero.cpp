#include <Hero.h>
#include <string>
#include <utility>
#include <Exceptions.h>
#include <iostream>
#include <iomanip>

Hero::Hero(): Person{3101}, pos{std::make_pair(0, 0)} {}

Hero::~Hero() {
  for (auto it: inventory) {
    delete it.second.first;
  }
}

void Hero::setWeapon(Item* w) {
  if (inventory.find(w->getID()) != inventory.end() && (w->getID()/100 % 10 == 2))
    weaponOfChoice = w;
  else
    std::cout << "You don't have this weapon" << std::endl;
}

Item* Hero::getWeapon() {
  return weaponOfChoice;
}

std::string Hero::inspect(Object* a) {
  return a->getDesc();
}

void Hero::mv(Direction a, Room** world) {
  int iPos = world[pos.first][pos.second].getDirection(a).second;
  iPos += (world[pos.first][pos.second].getDirection(a).first * 10);

  switch (iPos) {
  case -1:
    std::cout << "The Door wont open and there is no keyhole." <<std::endl;
    break;
  case -2:
    if (pos.first == 3 && pos.second == 1) {
      std::cout << "you're in the forest" <<std::endl;
      break;
    } else {
      std::cout << "The Door is locked" << std::endl;
      break;
    }
  case -11:
    std::cout << "You can't go that way" << std::endl;
    break;
  default:
    pos = world[pos.first][pos.second].getDirection(a);
    std::cout << world[pos.first][pos.second].getMessage();
    break;
  }
}

void Hero::setPosition (std::pair<uint, uint> posi) {
  if (pos.first > 4  || pos.second > 4)
    throw invalid_pos("ERROR: position out of bounds");
  pos = posi;
}

std::pair<uint, uint> Hero::getPos() {
  return pos;
}


void Hero::attack(Person* npc) {
    if (npc == Villager) {
      std::cout<<"You attacked a villager and they hauled you off to jail for a life time"<<endl;
      std::cout<<"You Lose"<<endl;
    }
    if(npc -> Enemy){
      enemy.sethealth(health - (dmg + ))
    }
}

/*std::list<std::pair<int,int>> invSave(){
  std::list<std::pair<int,int>> l;
  std::pair<int, int> stuff;
  for(auto it = inventory.begin(); it != inventory.end(); it++){
    stuff = std::make_pair(it->first, it->second)
    l.push_back(stuff);
  }
  return l;
}*/
/*
void Hero::command(std::string s, Room** world) {
  std::string cmd = "", op = "";
  cmd = s.substr(0, s.find(' '));
  op = s.substr(s.find(' ')+1);
  switch (cmd) {
  case "use":
    switch (op) {
    case "major health potion":
      //check that you have a healthpotion1
      break;
    case "minor health potion":
      //check that you have healthpotion2
      break;
    case "orange key":
      break;
    case "blue key":
      break;
    case "brown key":
      break;
    default:
      std::cout<<"not a useable item" << std::endl;
    }
    break;
  case "flip":
    switch (op) {
    case "bone lever":
      break;
    case "gold lever":
      break;
    case "stone lever":
      break;
    case "mossy lever":
      break;
    case "wooden lever":
      break;
    case "flimsy lever":
      break;
    default:
      std::cout << "that isn't a lever to flip" std::endl;
      break;
    }
    break;
  case "inspect":
    std::ifstream file;
    std::string line;
    std::string name;
    int idVar;
    file.open("identifierMap.csv");
    if (file.is_open()) {
      while (!file.eof()) {
        getline(file, line, ':');
        idVar = line;
        getline(file, line, ':');
        name = line;
        if (op == name) {
          if (idVar/100 == 32) { //its a villager
            Person* p = world[getPos().first][getPos().second].getNPC(idVar);
            Object* o = p;
            inspect(p);
            //std::cout << p->getDesc() << std::endl;
            delete p;
            delete o;
            p = o = nullptr;
            break;
          } else if (idVar/1000 == 1) { // its a room
            std::cout << world[getPos().first][getPos().second].getDesc() std::endl;
            break;
          } else if (idVar/1000 = 2) { //its a roomobject
            RoomObject* r = world[getPos().first][getPos().second].getObj(idVar);
            Object* a = r;
            inspect(r);
            //std::cout << r->getDesc() << std::endl;
            delete r;
            delete a;
            r = a = nullptr;
            break;
          } else { //its an item
            for(auto it:inventory){
              if(op == it.first->getName()){
               Object* ptr = it.first;
               inspect(ptr);
               break;
              }
            }
          }
        } else {
          file.ignore(1000, '\n');
        }
      }
    }
    break;
  case "attack":
    break;
  case "move":
    break;
  case "talk":
    break;
  case "open":
    break;
  case "equip":
    break;
  case "help":
    break;
  case "inventory":
    break;
  default:
    std::cout << "not a possible" << std::endl;
  }

}
*/
void Hero::getInventory() {
  std::cout << "Items" << std::setw(30) << "Amount" << std::endl;
  for (auto it: inventory)
    std::cout << std::left << std::setw(20) << std::setfill('-') <<
              it.second.first->getName() << std::setw(15) << std::setfill('-') << std::right
              <<
              it.second.second << std::endl;
}

void Hero::addInventory(Item* a) {
  int itemID = a->getID();
  if (inventory.find(itemID) == inventory.end())
    inventory[itemID] = std::make_pair(a, 1);
  else
    inventory[itemID].second++;
}

void Hero::usePotion(Item* a) {
  int potionID = a->getID();
  if (health == 10) {
    std::cout << "You are already at full health" << std::endl;
  } else if (health + a->getItemValue() > 10) {
    health = 10;
    inventory[potionID].second--;
  } else {
    health += a->getItemValue();
    inventory[potionID].second--;
  }
}

void Hero::useKey(Item* a, Lock* l) {
  l->unlock(a->getID());
}

void Hero::talk(Villager* v) {
  v->response();
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

void Hero::interact(RoomObject* r const) {
  if (r->getID() / 100 % 10 == 3 && r->getID() / 1000 == 2) {
    r->setState(!r->getState());
    std::cout << "The Lever has been flipped" << std::endl;
  } else if (r->getID() / 100 % 10 == 1 && r->getID() / 1000 == 2) {
    if (!r->getState()) {
        Item* a = static_cast<Chest*>(r)->getContents();
          std::cout << a->getName() << " has been added to your inventory" << std::endl;
      this->addInventory(a);
    }
  } else {
    std::cout << "This is not a Chest, nor is it a Lever" << std::endl;
  }
}
