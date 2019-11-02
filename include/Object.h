#ifndef OBJECT_H
#define OBJECT_H

#include<fstream>
#include<map>
#include<string>


class Object {
 public:
  /**
  *an enum holding all of our identifiers
  */
  enum Identifier {goldenChest, Chest, goldenSword, sword, goldenDagger,
                   dagger, goblin1, goblin2, goblin3, goblin4, duckDragon,
                   jzargo, serana, lydia, greyBeard, jackSparrow, billTurner,
                   dinkleBerg, kingOrlando, phyllis, healthPotion1,
                   healthPotion2, blueLock, orangeLock, blueKey, orangeKey, brownLock, brownKey, lever1, lever2,
                   lever3, lever4, lever5, lever6
                  };

  /**
  *a map that links an identifier to a name and description
  */
  static std::map<int, std::pair<std::string, std::string> ObjectMap;

  /**
  *set the objectMap
  */
  static void setMap();

  /**
  *set the pairs of names and descriptions to be used by ObjectMap
  */
  static void setPairs();


  /**
  *constructor
  */
  Object(int a) :id{a}, description{ObjectMap[a]} {}

  /**
  *virtual destructor
  */
  virtual ~Object();

  /**
  * @return id as a string
  */
  std::string getID();

  /**
  *the Object Identifier
  */
  const int id;

  /**
  *the Object description
  */
  std::string description;
};

#endif // OBJECT_H
