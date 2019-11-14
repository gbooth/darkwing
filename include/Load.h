///**
// *@autor Gavin Booth
// * @date 2019-11
// */
//
//#ifndef LOAD_H
//#define LOAD_H
//#include "HeroAtt.h"
//#include "Room.h"
//#include "Hero.h"
//#include<map>
//#include<fstream>
//#include<string>
//
///**
// *This class will provide the load for the player and rooms conditions.
// */
//class Load {
// public:
//  /**
//   *Default Constructor
//   *@parameter readIn, objData
//   *@parameter roomID, objID, objState representing the Id for rooms,objects and objects state.
//   *In the Constructor will be asked the player for the save filename without the typefilename.
//  *providing the options for health,position,inventory and weapon.
//   */
//  Load();
//
//  /**
//   *Default Destructor
//   */
//  virtual ~Load();
//
//  /**
//   *Function that load the game.
//   *Parameter const h that load the Hero.
//   *@parameter const world that will load the room position.
//   */
//  void loadGame(Hero* const, Room** const);
//
//  /**
//   *@param loadfile that will hold the information at the time of load.
//   *@param heroLoadMap will provide the map for the Hero.
//   *@parameter roomLoadState will give the room state at load for the Hero.
//   *@parameter filename provides the name for the file.
//   */
// private:
//  std::ifstream loadFile;
//  std::map<HeroAtt, std::string> heroLoadMap;
//  std::map<int, std::map<int, int>> roomLoadState;
//  std::string filename;
//
//  /**
//   *This function considering private,will give the condition for the Hero at the load time as Health
//   * Position,Inventory and Weapon.
//   * @parameter const h for the conditions mentioned before for the
//   *Hero at loading time.
//   */
//  void loadHero(Hero* const);
//
//  /**
//   *This function,considering private will give the condition for the room when loading as state,
//   * npc,health,objects.
//   * @parameter throw file_error("Load file has corrupted or invalid data")
//   * in case of file misreading.
//   */
//  void loadRooms(Room** const);
//};
//
//#endif // LOAD_H
