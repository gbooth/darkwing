/**
 *@author Ben Hunt
 *@date 2019-11
 */
#ifndef OBJECT_H
#define OBJECT_H
#include<fstream>
#include<string>

/**
 *This class will give all the information regarding the objects the will show up during the game ,more important
 *the identifier and the complete description of them.
 */

class Object {
 public:
  /**
  *constructor
  *@throw invalid_id error if invalid id is passed in or if file is missing
  */
  Object(int);

  /**
  *virtual Destructor
  */
  virtual ~Object();

  /**
  * @return id means the identifier of the objects.
  */
  int getID();

  /**
  * @return description means the way the player will be inform about the objects.
  */
  std::string getDesc();

  /**
  * @return name of the objects.
  */
  std::string getName();

 protected:
  int id;
  std::string name;
  std::string description;
};

#endif // OBJECT_H
