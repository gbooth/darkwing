/**author  Jorge Aceytuno
 * @date 2019 -11
 */

#include "Person.h"
#include "Exceptions.h"
#include <string>
#include <fstream>
#include <utility>

Person::Person(int ident)
  : Object{ident} {
  if (id /1000 != 3 || id < 3000 || id > 3399)
    throw invalid_id("ERROR: this ID does not describe a person");
  std::string line;
  std::string idStr = std::to_string(ident);
  std::ifstream objData;
  objData.open("personStats.csv");
  if (objData.is_open()) {
    while (!objData.eof()) {
      std::getline(objData, line, ',');
      if (line == idStr) {
        std::getline(objData, line, ',');
        damageValue = std::stoi(line);
        std::getline(objData, line);
        health = std::stoi(line);
        break;
      } else {
        objData.ignore(1000, '\n');
      }
      if (line != idStr && objData.eof())
        throw invalid_id("ERROR: the person ID specified is not on file");
    }
    objData.close();
  } else {
    throw file_error("ERROR: file you are trying to open is missing");
  }
}

Person::~Person() {}

void Person::setHealth(int hp) {
  health = hp;
}

int Person::getHealth() {
  return health;
}

void Person::setDamage(int damValue) {
  damageValue = damValue;
}

int Person::getDamage()const {
  return damageValue;
}



