/**
 *@author Ben Hunt
 * @date 2019-11
 */


#include "Object.h"
#include"Exceptions.h"
#include<iostream>
#include<fstream>
#include<string>
#include <algorithm>

Object::Object(int ident) {
  id = ident;
  std::string line;
  std::string idStr = std::to_string(ident);
  std::ifstream objData;
  objData.open("identifierMap.csv");
  if (objData.is_open()) {
    while (!objData.eof()) {
      getline(objData, line, ':');
      if (line == idStr) {
        getline(objData, line, ':');
        std::transform(line.begin(), line.end(), line.begin(), ::tolower);
        name = line;
        getline(objData, line);
        description = line;
        break;
      } else {
        objData.ignore(1000, '\n');
      }
      if (line != idStr && objData.eof())
        throw invalid_id("ERROR: the object ID specified is not on file");
    }
    objData.close();
  } else {
    throw file_error("ERROR: file you are trying to open is missing");
  }
}
Object::~Object() {}

int Object::getID() {
  return id;
}
std::string Object::getDesc() {
  return description;
}
std::string Object::getName() {
  return name;
}
