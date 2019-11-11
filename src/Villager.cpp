#include "Villager.h"
#include "Exceptions.h"
#include <iostream>

Villager::Villager(int idnty)
  :Person{idnty} {
  if (idnty/100%10 != 2)
    throw invalid_id("ERROR: not a villager");
}

Villager::~Villager() {}

void Villager::attack(Person* npc){}

void Villager::response(){
  switch(id){
    case 3201: std::cout <<"I am " << name << ", I hope you have a pleasant stay with us.\n";
    break;
    case 3202: std::cout << "I am " << name << ", You don't want to cross...\n";
    break;
    case 3203: std::cout << "I am " << name << ", how may I help you my thane?\n";
    break;
    case 3204: std::cout << "I am " << name << ", by the thu'um you look like you've seen a ghost!\n";
    break;
    case 3205: std::cout << "I am " << name << ", got any rum?\n";
    break;
    case 3206: std::cout << "The name's " << name << ", I don't really like the see.\n";
    break;
    case 3207: std::cout << "Name's " << name << ", not many people like me. I hope you're different.\n";
    break;
    case 3208: std::cout << "I'm " << name << ", Hope you pay taxes on time.\n";
    break;
    case 3209: std::cout << "You can call me " << name << ", I got these here shoes from the demon infested Croc swamp. Mighty dangerous...\n";
    break;
    default: std::cout << "fact: a gray whale make 1 of the largest migrations of any mammal.\n";
    break;
  }
}
