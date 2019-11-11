#include "Load.h"

Load::Load() {
  while(true){
    cout << "Enter the save file name(without filetype) --"
    getline(std::cin, filename);
    if(loadFile.open(filename))
      break;
    else
      std::cout << "Invalid file" << std::endl;
  }
}

Load::~Load()
{
  //dtor
}
