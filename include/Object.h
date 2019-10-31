#ifndef OBJECT_H
#define OBJECT_H

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
                   healthPotion2, blueLock, orangeLock, blueKey, orangeKey, lever1, lever2,
                   lever3, lever4, lever5, lever6
                  };
  /**
  *constructor
  */
  Object(Identifier a = sword) :id{a}, description{ObjectMap[a]} {};

  /**
  *virtual destructor
  */
  virtual ~Object();

  /**
  *a map that links an identifier to a description
  */
  std::map<Identifier, std::string> ObjectMap;

  /**
  * @return description
  */
  std::string getDesc();

  /**
  *the Object Identifier
  */
  const Identifier id;


 protected:
  std::string description;

 private:
};

#endif // OBJECT_H
