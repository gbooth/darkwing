#ifndef OBJECT_H
#define OBJECT_H

#include<fstream>
#include<map>
#include<string>
using namespace std;


class Object {
 public:
  /**
  *an enum holding all of our identifiers
  */
  enum Identifier {goldenChest, Chest, goldenSword, sword, goldenDagger,
                   dagger, goblin1, goblin2, goblin3, goblin4, duckDragon,
                   jzargo, serana, lydia, greyBeard, jackSparrow, billTurner,
                   dinkleBerg, kingOrlando, phyllis, healthPotion1,
                   healthPotion2, blueLock, orangeLock, blueKey, orangeKey, lever1, lever2,
                   lever3, lever4, lever5, lever6
                  };

  /**
  *a map that links an identifier to a description
  */
  static map<Identifier, string> ObjectMap;

  /**
  *set the objectMap
  */
  static void setMap();

  /**
  *constructor
  */
  Object(Identifier a) :id{a}, description{ObjectMap[a]} {}

  /**
  *virtual destructor
  */
  virtual ~Object();

  /**
  * @return description
  */
  string getDesc();

  /**
  *the Object Identifier
  */
  const string id;

  /**
  *the Object description
  */
  string description = "";

 private:
};

#endif // OBJECT_H
