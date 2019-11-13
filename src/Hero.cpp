#include <Hero.h>
#include <string>
#include <utility>
#include <Exceptions.h>
#include <iostream>
#include <iomanip>

Hero::Hero(int id = 3101,
           std::pair<unsigned int, unsigned int> posi = std::make_pair(0, 0))
  : Person{id} {
  if (id / 100 % 10 != 1)
    throw invalid_id("ERROR: THIS ISNT DUCK NORRIS");
}

Hero::~Hero() {}

void Hero::setWeapon(Item* w) {
  if (inventory.find(w) != inventory.end() && (w->getID()/100 % 10 == 2))
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
  /*  Item temp(4203);
    if (npc -> Villager) {
      std::cout<<"You attacked a villager and they hauled you off to jail for a life time"<<endl;
      std::cout<<"You Lose"<<endl;
    }
    if(npc -> Enemy){
      enemy.sethealth(health - (dmg + ))
    }*/
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

/*void Hero::command(std::string s, Room** world) {
  std::string first, second, third;
  first = s.substr(0, s.find(' '));
  s.erase(first.begin(), first.end()+1);
  if (s.find(' ')) {
    second = s.substr(0, s.end());
    second = s.substr(0, s.find(' '));
    s.erase(second.begin(), second.end());
    third = s.substr(0, s.end());
  } else {
    second = s.substr(0, s.end());
  }
  switch(first){
    case "":
  }
}*/



void Hero::getInventory() {
  std::cout << "Items" << std::setw(25) << "Amount" << std::endl;
  for (auto it: inventory)
    std::cout << std::left << std::setw(15) << std::setfill('-') <<
              it.first->getName() << std::setw(15) << std::setfill('-') << std::right <<
              it.second << std::endl;
}

void Hero::addInventory(Item* a) {
  if (inventory.find(a) == inventory.end())
    inventory[a] = 1;
  else
    inventory[a]++;
}

void Hero::usePotion(Item* a) {
  if (health == 10)
    std::cout << "You are already at full health" << std::endl;
  else if (health + a->getItemValue() > 10)
    health = 10;
  else
    health += a->getItemValue();
}

void Hero::talk(Villager* v){
  v->response();
}


