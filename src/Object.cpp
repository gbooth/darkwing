#include "Object.h"
#include"Exceptions.h"
#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<typeinfo>
#include<utility>

Object::~Object() {}

void Object::setMap() {
  int colon = 0;
  int semicolon = 0;
  int ident;
  int nameSize;
  std::string line;
  std::string name;
  std::string desc;
  std::ifstream objData;
  objData.open("identifierMap.csv");
  if (objData.is_open()) {
    while (!objData.eof()) {
      std::getline(objData, line, ':');
      ident = std::stoi(line, nullptr, 10);
      std::getline(objData, line, ':');
      name = line;
      std::getline(objData, line);
      desc = line;
      auto p = make_pair(name, desc);
      objectMap[ident] = p;
      objData.ignore(1000,'\n');
    }
    objData.close();
  }

}



std::string Object::getID() {
  return "left";
}

