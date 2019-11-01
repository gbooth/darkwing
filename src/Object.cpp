#include "Object.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
//using namespace std;


Object::~Object() {}

void Object::setMap() {
  int colon = 0;
  std::map<std::string, Identifier> change;
  change["goldenChest"] = goldenChest;
  change["Chest"] = Chest;
  change["goldenSword"] = goldenSword;
  change["sword"] = sword;
  change["goldenDagger"] = goldenDagger;
  change["dagger"] = dagger;
  change["goblin1"] = goblin1;
  change["goblin2"] = goblin2;
  change["goblin3"] = goblin3;
  change["goblin4"] = goblin4;
  change["duckDragon"] = duckDragon;
  change["jzargo"] = jzargo;
  change["serana"] = serana;
  change["lydia"] = lydia;
  change["greyBeard"] = greyBeard;
  change["jackSparrow"] = jackSparrow;
  change["billTurner"] = billTurner;
  change["dinkleBerg"] = dinkleBerg;
  change["phyllis"] = phyllis;
  change["healthPotion1"] = healthPotion1;
  change["healthPotion2"] = healthPotion2;
  change["blueLock"] = blueLock;
  change["orangeLock"] = orangeLock;
  change["blueKey"] = blueKey;
  change["orangeKey"] = orangeKey;
  change["lever1"] = lever1;
  change["lever2"] = lever2;
  change["lever3"] = lever3;
  change["lever4"] = lever4;
  change["lever5"] =lever5 ;
  change["lever6"] = lever6;
  std::string line;
  std::string key;
  std::string val ;
  std::ifstream objectData;
  objectData.open("obf.txt");
  if (objectData.is_open()) {
    while (getline(objectData, line)) {
      for (uint i = 0; i < line.size(); i++) {
        if (line[i] == ':') {
          colon = i;
          key = line.substr(0, colon);
          val = line.substr(colon + 1);
          for (auto it = change.begin(); it != change.end(); it++) {
            if (it->first == key) {
              ObjectMap[it->second] = val;
            }
          }
          val = "";
          key = "";
        }
      }
    }
    objectData.close();
  } else {
    std::cout << "no file to open"<<std::endl;
  }

}

std::string Object::getID() {
  switch (id) {
  case goldenChest:
    return "goldenChest";
    break;
  case Chest:
    return "Chest";
    break;
  case goldenSword:
    return "goldenSword";
    break;
  case sword:
    return "sword";
    break;
  case goldenDagger:
    return "goldenDagger";
    break;
  case dagger:
    return "dagger";
    break;
  case goblin1:
    return "goblin1";
  case goblin2:
    return "goblin2";
    break;
  case goblin3:
    return "goblin3";
    break;
  case goblin4:
    return "goblin4";
    break;
  case duckDragon:
    return "duckDragon";
    break;
  case jzargo:
    return "jzargo";
    break;
  case serana:
    return "serana";
    break;
  case lydia:
    return "lydia";
    break;
  case greyBeard:
    return "greyBeard";
    break;
  case jackSparrow:
    return "jackSparrow";
    break;
  case billTurner:
    return "billTurner";
    break;
  case dinkleBerg:
    return "dinkleBerg";
    break;
  case kingOrlando:
    return "kingOrlando";
    break;
  case phyllis:
    return "phyllis";
    break;
  case healthPotion1:
    return "healthPotion1";
    break;
  case healthPotion2:
    return "healthPotion1";
    break;
  case blueLock:
    return "blueLock";
    break;
  case orangeLock:
    return "orangeLock";
    break;
  case blueKey:
    return "blueKey";
    break;
  case orangeKey:
    return "orangeKey";
    break;
  case lever1:
    return "lever1";
    break;
  case lever2:
    return "lever2";
    break;
  case lever3:
    return "lever3";
    break;
  case lever4:
    return "lever4";
    break;
  case lever5:
    return "lever5";
    break;
  case lever6:
    return "lever6";
    break;
  default:
    return "not an identifier";
    break;
  }
}

