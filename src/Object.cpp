#include "Object.h"
#include"Exceptions.h"
#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<typeinfo>
#include<utility>

Object::~Object() {}

void Object::setPairs(){
  ifstream
}

void Object::setMap() {
  int colon = 0;
  std::string line;
  std::string name;
  std::string desc;
  std::ifstream objectData;
  objectData.open()
  if(objectData.is_open)
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
    throw not_an_identifier_error("not specified identifier");
    break;
  }
}

