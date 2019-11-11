#include "Room.h"
//#include "Chest.h"
//#include "Lock.h"
#include "Lever.h"
#include "Hero.h"
#include "Enemy.h"
//#include "Villager.h"
#include "Item.h"
//#include "Load.h"
//#include "Save.h"
#include<stdlib.h>
#include<string>
#include <map>
#include <fstream>
#include <iostream>

int titleScreen();
void clearScreen();
void newGame(Hero*, Room**);
void loadGame(Hero*, Room**);
void exitGame();

int main() {
  std::string inStr;
  Hero* h = null;
  Room** world = null;

  while (true) {
    if (titleScreen() == 1) {
      newGame(h, world);
    }
    else {
      newGame(h, world);
      loadGame(h, world);
    }
    getline(std::cin, inStr, '\n');
    while(inStr != "exit"){
      h.command(inStr);
      getline(std::cin, inStr, '\n'));
    }
  }
}

int titleScreen() {
  int in;
  while (true) {
    std::cout << "  _____          _   _       _____                       " <<
              std::endl
              << " / ____|        | | | |     / ____|                      " << std::endl
              << "| |     __ _ ___| |_| | ___| (___   ___ __ _ _ __   ___  " << std::endl
              << "| |    / _` / __| __| |/ _ \\___ \ / __/ _` | ' _\ / _ \ " << std::endl
              << "| |___| (_| \__ \ |_| |  __/____) | (_| (_| | |_) |  __/ " << std::endl
              << " \_____\__,_|___/\__|_|\___|_____/ \___\__,_| .__/ \___| " << std::endl
              << "                                            | |          " << std::endl
              << "                                            |_|          " << std::endl;
    std::cout << setw(22) << "1 - New Game" << std::endl
              << setw(22) << "2 - Load Game" << std::endl
              << setw(22) << "3 - Exit Game" << std:: endl;
    std::cout << "Selection -- ";
    std::cin >> in;
    switch (in) {
    case 1:
      return 1;
    case 2:
      return 2;
    case 3:
      exitGame();
    default:
      std::cout << "invalid selection";
      system("PAUSE");
      break;
    }
    clearScreen();
  }
}

void clearScreen() {
  std::cout << flush;
  system("CLS");
}

void newGame(Hero* h, Room** world) {
  h = new Hero;
  world = new Room*[5];
  for(int i = 0; i < 5; i++)
    world[i] = new Room[5] = {i*5 + 1001, i*5 + 1002, i*5 + 1003, i*5 + 1004, i*5 + 1005};
}

void loadGame(Hero* h, Room** world) {


}


