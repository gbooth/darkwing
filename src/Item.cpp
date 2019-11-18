/**
 *@author Wesley Waldern
 *@date 2019-11
 */

#include <Item.h>
#include <string>
#include <Exceptions.h>
#include <fstream>

Item::Item(int id): Object{id} {
  std::string line;
  std::string idStr = std::to_string(id);
  std::fstream itemData;
  itemData.open("Items.csv");
  if (itemData.is_open()) {
    while (!itemData.eof()) {
      getline(itemData, line, ',');
      if (line == idStr) {
        getline(itemData, line);
        itemValue = std::stoi(line);
        break;
      } else {
        itemData.ignore(1000, '\n');
      }
      if (line != idStr && itemData.eof())
        throw invalid_id("ERROR: the item ID specified is not on file");
    }
    itemData.close();
  } else {
    throw file_error("ERROR: the file you are trying to open is missing");
  }
}


int Item::getItemValue() {
  return itemValue;
}

