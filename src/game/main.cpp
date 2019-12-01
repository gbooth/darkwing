#include "Room.h"
#include "Hero.h"
#include "Load.h"
#include "Enemy.h"
#include "Exceptions.h"
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm>

int titleScreen();
Room** newGame(Room**);
bool loadGame(Hero&, Room**);
bool combat(Hero&, Room**);

int main() {
  std::string inStr;
  Hero h;
  Room** world = nullptr;
  while (true) {
    int title = titleScreen();
    if (title == 1) {
      world = newGame(world);
      std::cout << "It is a pleasant spring day in Anates Terra, a province in"
                << " Avemland.\nEach province in Avemland is ruled over by a k"
                << "ing, and Anates Terra \nis no different. Our story begins "
                << "in Castle Anates, in the resident\nwizard tower, where an "
                << "eager young apprentice named Duck Norris is\nassisting wit"
                << "h the concoction of a new potion. The wizard, brilliant\na"
                << "s he is eccentric, still cannot determine why this potion "
                << "does not\nmake pigs fly.\n\"Norris, bring me the wooden du"
                << "ck we must do some debugging.\"\ncried the wizard.  Duck N"
                << "orris rushed to fetch the wooden duck and\nplaced it in fr"
                << "ont of the wizard.\"Your duck, master,\" murmured Norris."
                << "\nThe wizard took the duck without a second glance and pro"
                << "ceeded to\nexplain the potion properties. Minutes go by an"
                << "d the Wizard grows\nincreasingly frustrated to the point o"
                << "f him throwing the duck into\nthe bubbling cauldron. Upon "
                << "the duck touching the surface of the\npotion it comes aliv"
                << "e and grows to the size of a dragon. \"I AM FIREQUACKER\" "
                << "thundered the duck. \"You have\nused me for debugging for "
                << "the last time wizard!\" bellowed the giant\nduck. The duck"
                << " swoops a wooden wing down and picks up the wizard\nand st"
                << "orms out of the castle leaving a giant duck-sized hole in "
                << "the\nwall. As Duck Norris, you stand awestruck in the wiza"
                << "rd room you must\nsave your master.\n\n";
      std::cout << "what will you do now?(type for help for commands)\n";
      std::cin.ignore(1000, '\n');
    } else if (title == 2) {
      world = newGame(world);
      if (loadGame(h, world)) {
        std::cout << "Game loaded\n";
      } else {
        for (int i = 0; i < 5; i++) {
          delete [] world[i];
        }
        delete []world;
        world = nullptr;
        h.reset();
        continue;
      }
    } else {
      return 0;
    }
    while (true) {
      if (world[h.getPos().first][h.getPos().second].checkForEnemy()) {
        if (combat(h, world))
          return 0;
        else
          continue;
      }
      std::cout << "   _  " << std::endl << "__(0)>";
      std::getline(std::cin, inStr);
      std::cout << R"(\___))" << std::endl;
      if (inStr == "exit") {
        for (int i = 0; i < 5; i++) {
          delete [] world[i];
        }
        delete []world;
        world = nullptr;
        h.reset();
        break;
      }
      if (h.command(inStr, world))
        return 0;
    }
  }
}

int titleScreen() {
  std::string in;
  while (true) {
    std::cout << R"(    ____             __            _            )" << std::endl
              << R"(   / __ \____ ______/ /___      __(_)___  ______)" << std::endl
              << R"(  / / / / __ `/ ___/ //_/ | /| / / / __ \/ __ `/)" << std::endl
              << R"( / /_/ / /_/ / /  / ,<  | |/ |/ / / / / / /_/ / )" << std::endl
              << R"(/_____/\__,_/_/  /_/|_| |__/|__/_/_/ /_/\__, /  )" << std::endl
              << R"(                                       /____/   )" << std::endl;
    std::cout << std::setw(21) << "1 - New Game" << std::endl
              << std::setw(22) << "2 - Load Game" << std::endl
              << std::setw(22) << "3 - Exit Game" << std:: endl;
    std::cout << "Selection -- ";
    std::cin >> in;
    if (in == "1") {
      return 1;
    } else if (in == "2") {
      return 2;
    } else if (in == "3") {
      return 3;
    }
  }
}

Room** newGame(Room** world) {
  world = new Room*[5];
  for (int i = 0; i < 5; i++) {
    world[i] = new Room[5] {i + 1001, i + 1006, i + 1011, i + 1016, i + 1021};
  }
  Lever* bridge1 = static_cast<Lever*>(world[0][4].getObj(2305));
  Lever* bridge2 = static_cast<Lever*>(world[0][3].getObj(2306));
  Lever* bridge3 = static_cast<Lever*>(world[1][3].getObj(2302));
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++) {
      world[i][j].setDoor(world);
      if (world[i][j].getID() == 1005) {
        Lever* bridgeLever = static_cast<Lever*>(world[i][j].getObj(2301));
        bridgeLever->setDepLever(std::make_pair(bridge1, false));
        bridgeLever->setDepLever(std::make_pair(bridge2, true));
        bridgeLever->setDepLever(std::make_pair(bridge3, true));
      }
    }
  return world;
}

bool loadGame(Hero& h, Room** world) {
  std::string filename;
  std::ifstream loadFile;
  std::cin.ignore(1000, '\n');
  while (true) {
    std::cout << "Enter the save file name(without filetype)." << std::endl
              << "Enter \"exit\" to exit file loading -- ";
    getline(std::cin, filename);
    if (filename == "exit")
      return false;
    filename += ".txt";
    loadFile.open(filename);
    if (loadFile.is_open()){
      loadFile.close();
      break;
    } else {
      std::cout << "\nInvalid file\n" << std::endl;
    }
  }
  Load l(filename);
  l.loadGame(h, world);
  return true;
}

bool combat(Hero& h, Room** world) {
  int turnCount = 0;
  bool stupidUser = false;
  std::string line, comd, oper;
  int i = h.getPos().first;
  int j = h.getPos().second;
  Enemy* e;
  switch (world[i][j].getID()) {
  case 1004: {
    e = static_cast<Enemy*>(world[i][j].getNPC(3301));
    break;
  }
  case 1005: {
    e = static_cast<Enemy*>(world[i][j].getNPC(3302));
    break;
  }
  case 1011: {
    e = static_cast<Enemy*>(world[i][j].getNPC(3303));
    break;
  }
  case 1012: {
    e = static_cast<Enemy*>(world[i][j].getNPC(3305));
    break;
  }
  case 1015: {
    e = static_cast<Enemy*>(world[i][j].getNPC(3304));
    break;
  }
  }
  int eOrigHP = e->getHealth();
  if (e->getID() != 3305) {
    std::cout << "A cow sized duck blocks your path wielding a dagger in his bil"
              << "l. He appears to be rather angry. Firequacker must have enchan"
              << "ted him, perhaps with the help of the captive wizard."
              << std::endl << "\"Hello Duck Norris. I'm " << e->getName() << "\""
              << " the duck rasps through his clenched bill. \"I'm going to enjo"
              << "y killing you\"" << std::endl;
  } else {
    std::cout <<
              "Firequacker is standing in the middle of the chamber.\n\"I've been expecting you Duck Norris.\" growled Firequacker.\n\"I've always liked you but if you're here to rescue this jerk wizard we are going to have a problem.\" huffed Firequacker.\n";
    while (true) {
      std::cout <<
                "\n\"Are you here to rescue this jerky pants?\" asked Firequacker\n";
      std::cout << "(yes/no)--";
      std::getline(std::cin, line);
      if (line == "no") {
        std::cout <<
                  "\n\"Well then I have no quarrel with you Duck Norris\" chuffed Firequacker\n \"Lets go back to the castle and we can study potions and magic together. As long as the wizard rots here I'm good\" quacked Firequacker.\n";
        h.lose(friends, world);
        return true;
      } else if (line == "yes") {
        std::cout <<
                  "\n\"Then prepare yourself for death Duck Norris!\" hissed Firequacker.\n\n";
        break;
      } else {
        std::cout << "\n\"A simple yes or no will do Norris\" growls Firequacker.\n\n";
      }
    }
  }
  while (h.getHealth() > 0 && e->getHealth() > 0) {
    std::cout << "Enter a command--";
    std::getline(std::cin, line);
    std::transform(line.begin(), line.end(), line.begin(), ::tolower);
    comd = line.substr(0, line.find(' '));
    oper = line.substr(line.find(' ') + 1);
    if (comd  != "attack" && comd != "run" && comd != "use" && comd != "inventory") {
      if (stupidUser) {
        std::cout << e->getName() << " has managed to get his dagger to your n"
                  << "eck while you've been standing there. \"All too easy Duc"
                  << "k Norris\" " << e->getName() << " chuckles as he slits y"
                  << "our throat." << std::endl;
        h.lose(moronUser, world);
        return true;
      } else {
        std::cout << "You really shouldn't do that right now. You kind of have m"
                  << "ore pressing matters, namely a duck the size of a cow who "
                  << "wants to kill you. A smart man would probably either fight"
                  << " or run away." << std::endl;
        stupidUser = true;
      }
    } else {
      stupidUser = false;
      if (comd == "attack") {
        h.attack(e, world);
        if (e->getHealth() < 1) {
          if (e->getID() == 3305) {
            h.win(world);
            return true;
          }
          std::cout << e->getName() <<
                    " crumbles at your feet sucumbing to the wounds you"
                    << "'ve inflicted. \"You win this time Duck Norris.\" sputters"
                    << " " << e->getName() << " as he coughs up blood and exhales "
                    << "one last time" << std::endl;
          world[i][j].setHasEnemy();
          break;
        }
        std::cout << e->getName() << " still stands." << std::endl;
        e->attack(&h, world);
        turnCount++;
        if (world[i][j].getID() == 1015) {
          switch (turnCount) {
          case 1: {
            std::cout << "Your blows at each other echo throughout the cave."
                      << std::endl;
            break;
          }
          case 2: {
            break;
          }
          case 3: {
            break;
          }
          case 4: {
            std::cout << "Stalactites start falling all around you and your "
                      << "opponent. As they slam against the ground echos bo"
                      << "unce around the cave causing more stalactites to f"
                      << "all." << std::endl;
            break;
          }
          case 5: {
            std::cout << "A large stalactite falls and squishes the duck. Wh"
                      << "at luck! You raise your sword and cheer at your vi"
                      << "tory. You hear your cheer echo throughout the cave"
                      << "and look up just in time to see a massive stalacti"
                      << "te that is about to fall on your head. You quickly"
                      << " leap aside as the stalactite lands on your legs "
                      << "crushing your legs and pinning you to the ground."
                      << " You screech out in pain and everything goes blac"
                      << "k." << std::endl;
            h.lose(stalactite, world);
            return true;
          }
          default: {
            throw combat_error("Something really broke when you did or didn't hit that guy");
          }
          }
        }
      } else if (comd == "run") {
        h.mv(west, world);
        e->setHealth(eOrigHP);
        break;
      } else {
        if (h.command(line, world))
          return true;
      }
    }
  }
  if (h.getHealth() < 1) {
    std::cout << "The duck has triumphed over you. You lay there contemplating"
              << " your life as you bleed to death." << std:: endl;
    h.lose(ducked, world);
    return true;
  }
  return false;
}
