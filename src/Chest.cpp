#include <Chest.h>
#include <Exceptions.h>

Chest::Chest(int id, bool st): RoomObject{id, st}{
  std::string line;
  std::string idStr = std::to_string(id);
  std::fstream chestData;
  chestData.open("Chests.csv");
  if (chestData.is_open()) {
    while (!chestData.eof()) {
      getline(chestData, line, ',');
      if(line == idStr){
        getline(chestData,line);
        contents = std::stoi(line);
        break;
      }
      else{
        chestData.ignore(1000, '\n');
      }
      if(line != idStr && chestData.eof())
        throw invalid_id("ERROR: the ID specified is not on file");
    }
    chestData.close();
  }
  else{
    throw file_error("ERROR: the file you are trying to open is missing");
  }
}

Item Chest::getContents(){
  state = true;
return contents;
}
