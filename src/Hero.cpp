#include <Hero.h>
#include <string>
#include <utility>
#include <Exceptions.h>
#include <iostream>

Hero::Hero(int id = 3101,std::pair<unsigned int, unsigned int> pos = std::make_pair(0, 0))
  : Person{id} {
  if (id / 100 % 10 != 1)
    throw invalid_id("ERROR: THIS ISNT DUCK NORRIS");
}

Hero::~Hero() {}

void Hero::setWeapon(Item w) {
  if (w.getID() / 100 % 10 == 2)
    weaponOfChoice = w;
}

Item Hero::getWeapon() {
  return weaponOfChoice;
}

std::string Hero::inspect(Object a) {
  return a.getDesc();
}

void Hero::mv(Direction a){

}

void Hero::setPosition (std::pair<uint, uint> pos) {
  if(pos.first > 4  || pos.second > 4)
    throw invalid_pos("ERROR: position out of bounds");
  position = pos;
}

std::pair<uint, uint> Hero::getPos() {
  return position;
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

