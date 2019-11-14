/**
 *@autor Wesley Waldern
 *@date 2019-11
 */
#include <Hero.h>
#include <string>
#include <utility>
#include <Exceptions.h>
#include <iostream>
#include <iomanip>

Hero::Hero(): Person{3101} {
  pos = std::make_pair(0,0);
  this->setRef();
  this->setCommand();
}
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
    Item temp(4203);
    if (npc -> Villager) {
      std::cout<<"You attacked a villager and they hauled you off to jail for a life time"<<endl;
      std::cout<<"You Lose"<<endl;
    }
    if(npc -> Enemy){
      enemy.sethealth(health - (dmg + ))
    }
}

std::list<std::pair<int,int>> Hero::invSave(){
  std::list<std::pair<int,int>> l;
  std::pair<int, int> stuff;
  for(auto it : inventory){
    stuff = std::make_pair(it.first, it.second.second);
    l.push_back(stuff);
  }
  return l;
}

void Hero::command(std::string s, Room** world) {
  std::string cmd = "", op = "";
  int i = this->getPos().first;
  int j = this->getPos().second;
  cmd = s.substr(0, s.find(' '));
  op = s.substr(s.find(' ')+1);
  switch (cRefs[cmd]) {
  case Command::use:
    auto it = refs.find(op);
    if (it != refs.end()) {
      if (it->second/100 == 41) { //its a potion
        auto itr = inventory.find(it->second);
        if (itr != inventory.end()) {
          this->usePotion(itr->second.first);
          break;
        }
      } else {
        if(op == "orange key"){
          auto it = refs.find(op);
          if (it != refs.end() && world[i][j].checkForObj(2201)) {
            RoomObject* lck = world[i][j].getObj(2201);
            Lock* l = static_cast<Lock*>(lck);
            auto itr = inventory.find(it->second);
            if (itr != inventory.end()) {
              this->useKey(itr->second.first, l);
            }
          }
        } else {
          if(op == "blue key") {
            auto it = refs.find(op);
            if (it != refs.end()&& world[i][j].checkForObj(2202)) {
              RoomObject* lck = world[i][j].getObj(2202);
              Lock* l = static_cast<Lock*>(lck);
              auto itr = inventory.find(it->second);
              if (itr != inventory.end()) 
                this->useKey(itr->second.first, l);
            }
          } else {
            if(op == "brown key"){
              auto it = refs.find(op);
              if (it != refs.end() && world[i][j].checkForObj(2203)) {
                RoomObject* lck = world[i][j].getObj(2203);
                Lock* l = static_cast<Lock*>(lck);
                auto itr = inventory.find(it->second);
                if (itr != inventory.end()) 
                  this->useKey(itr->second.first, l);
              }
            } else {
              std::cout<<"not a usable item" << std::endl;
            }
          }
        }
      }
    } else {
      std::cout << "That is not the name of an item" << std::endl;
    }

  case Command::flip:
    auto it = refs.find(op);
    if(it != refs.end() && world[i][j].checkForObj(it->second)){
      RoomObject* const robj = world[i][j].getObj(it->second);
      this->interact(robj);
    }else{
      std::cout <<"you can't flip that" << std::endl;
    }
    break;
  case Command::inspect:
    auto it = refs.find(op);
    if (it != refs.end()) {
      if (it->second/100 == 3) { //its a villager
        Person* const p = world[i][j].getNPC(it->second);
        Object* o = p;
        inspect(o);
        break;
      } else if (it->second/1000 == 1) { // its a room
        std::cout << world[i][j].getDesc() << std::endl;
        break;
      } else if (it->second/1000 == 2) { //its a roomobject
        RoomObject* r = world[i][j].getObj(it->second);
        Object* a = r;
        inspect(a);
        break;
      } else { //its an item
        auto itr = inventory.find(it->second);
        if (itr!= inventory.end()) {
          Object* pt = itr->second.first; //item*
          inspect(pt);
        }
      }
    } else {
      std::cout << "you can't inspect that" << std::endl;
    }
    break;
  case Command::attack:
    auto it = refs.find(op);
    if(it != refs.end() && world[i][j].checkForNPC(it->second)){
      Person* const eny = world[i][j].getNPC(it->second);
      this->attack(eny);
    }
    break;
  case Command::move:
    if(op == "north") {
      mv(north, world);
      break;
    } else if(op == "south"){
      mv(south, world);
      break;
    }
    else if(op == "east"){
      mv(east, world);
      break;
    }
    else if(op == "west"){
      mv(west, world);
      break;
    }
    else{
      std::cout << "That is not a direction" << std::endl;
      break;
    }
  case Command::talk:
    auto it = refs.find(op);
    if (it != refs.end() && world[i][j].checkForNPC(it->second) && (it->second/100 == 32)) {
      Person* prn = world[i][j].getNPC(it->second);
      Villager* v = static_cast<Villager*>(prn);
      this->talk(v);
    } else if (it->second/100 == 31 || it->second/100 == 33) {
      std::cout << "you can't talk to this person" << std::endl;
    } else {
      std::cout << "this person isn't here" << std::endl;
    }
    break;
  case Command::open:
    auto it = refs.find(op);
    if (it != refs.end() && (it->second/100 == 21) && world[i][j].checkForObj(it->second)) {
      RoomObject* const rmb = world[i][j].getObj(it->second);
      this->interact(rmb);
    } else {
      std::cout << "you can't open that" << std::endl;
    }
    break;
  case Command::equip:
    auto it = refs.find(op);
    if(it != refs.end()){
      auto ptr = inventory.find(it->second);
      setWeapon(ptr->second.first);
    }
    break;
  case Command::help:
    this->help();
    break;
  case Command::inv:
    this->getInventory();
    break;
  default:
    std::cout << "not a possible" << std::endl;
    break;
  }
}

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

void Hero::setRef() {
  std::ifstream file;
  std::string line;
  std::string name;
  int idVar;
  file.open("identifierMap.csv");
  if (file.is_open()) {
    while (!file.eof()) {
      getline(file, line, ':');
      idVar = stoi(line);
      getline(file, line, ':');
      refs[name] = idVar;
      file.ignore(1000, '\n');
    }
  }
}

void Hero::setCommand(){
  cRefs["move"] = Command::move;
  cRefs["use"] = Command::use;
  cRefs["inspect"] = Command::inspect;
  cRefs["inventory"] = Command::inv;
  cRefs["talk"] = Command::talk;
  cRefs["attack"] = Command::attack;
  cRefs["flip"] = Command::flip;
  cRefs["open"] = Command::open;
  cRefs["help"] = Command::help;
  cRefs["equip"] = Command::equip;
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

void Hero::interact(RoomObject* const r) {
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
