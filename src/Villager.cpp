#include "Villager.h"
#include "Exceptions.h"
#include <string>
#include <iostream>
#include <ctype.h>

Villager::Villager(int idnty)
  :Person{idnty} {
  if (idnty/100%10 != 2)
    throw invalid_id("ERROR: not a villager");
}

Villager::~Villager() {}

void Villager::attack(Person* npc) {}

void Villager::response() {
  switch (id) {
  case 3201:
    std::cout <<"I am " << name << ", I hope you have a pleasant stay with us.\n";
    break;
  case 3202:
    std::cout << "I am " << name << ", You don't want to cross...\n";
    break;
  case 3203:
    std::cout << "I am " << name << ", how may I help you my thane?\n";
    break;
  case 3204:
    std::cout << "I am " << name <<
              ", by the thu'um you look like you've seen a ghost!\n";
    break;
  case 3205:
    std::cout << "I am " << name << ", got any rum?\n";
    break;
  case 3206:
    std::cout << "The name's " << name << ", I don't really like the see.\n";
    break;
  case 3207:
    std::cout << "Name's " << name <<
              ", not many people like me. I hope you're different.\n";
    break;
  case 3208: {
    std::cout << "I'm " << name << ". I love the lake county\n";
    break;
  }
  case 3209:
    std::cout << "You can call me " << name <<
              ", I got these here shoes from the demon infested Croc swamp. Mighty dangerous...\n";
    break;
  default:
    std::cout <<
              "fact: a gray whale make 1 of the largest migrations of any mammal.\n";
    break;
  }
}

bool Villager::riddle() {
  std::string guess;
  std::string ans = "chuck norris";
  std::string rdl = "Who are you named after in the world up above?\n";
  std::cout << rdl;
  std::getline(std::cin, guess);
  std::string newGuess ="";
  for (uint i = 0 ; i < guess.size(); i++) {
    newGuess += tolower(guess[i]);
  }
  if (newGuess == ans)
    return true;
  else
    return false;
}
