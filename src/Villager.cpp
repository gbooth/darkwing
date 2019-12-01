#include "Villager.h"
#include "Exceptions.h"
#include "Room.h"
#include <ctype.h>
#include <string>
#include <iostream>

Villager::Villager(int idnty)
  :Person{idnty} {
  if (idnty/100%10 != 2)
    throw invalid_id("ERROR: not a villager");
}

Villager::~Villager() {}

bool Villager::attack(Person* npc, Room** world) {
  return false;
}

void Villager::response() {
  switch (id) {
  case 3201:
    std::cout << "I am " << name << ", I know kung-fu.\n";
    break;
  case 3202:
    std::cout << "Is that any way to address the king?\n";
    break;
  case 3203:
    std::cout << "Pond, " << name << ". Care for a vodka martini?\n";
    break;
  case 3204:
    std::cout << "I am " << name << ". How do you like my upgrades?\n";
    break;
  case 3205:
    std::cout << "I am " << name <<
              ", I have a large collection of rubber ducks. You?\n";
    break;
  case 3206:
    std::cout << "The name's " << name << ", and no I haven't seen the play.\n";
    break;
  case 3207:
    std::cout << "Name's " << name <<
              " If you ever need healing be sure to see me.\n";
    break;
  case 3208:
    std::cout << "I'm " << name << ". I love the lake county\n";
    break;
  case 3209:
    std::cout << "You can call me " << name <<
              ". I ever tell of the time I wrestled a goose?\n";
    break;
  case 3210:
    std::cout << "They call me " << name << " because...well I can't waddle.\n";
  default:
    std::cout << "fact: a gray whale make 1 of "
              << "the largest migrations of any mammal.\n";
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
