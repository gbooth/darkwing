/**
 *@author Wesley Waldern / Gavin Booth
 *@date 2019-11
 */

#include <Chest.h>
#include <Exceptions.h>
#include <string>

Chest::Chest(int id): RoomObject{id} {
  std::string line;
  std::string idStr = std::to_string(id);
  std::fstream chestData;
  chestData.open("Chests.csv");
  if (chestData.is_open()) {
    while (!chestData.eof()) {
      std::getline(chestData, line, ',');
      if (line == idStr) {
        getline(chestData, line);
        contents = new Item(std::stoi(line));
        break;
      } else {
        chestData.ignore(1000, '\n');
      }
      if (line != idStr && chestData.eof())
        throw invalid_id("ERROR: the chest ID specified is not on file");
    }
    chestData.close();
  } else {
    throw file_error("ERROR: the file you are trying to open is missing");
  }
}

Chest::~Chest() {
  if (contents)
    delete contents;
}

Item* Chest::getContents() {
  this->setState(true);
  Item* temp = contents;
  contents = nullptr;
  return temp;
}
