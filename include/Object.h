#ifndef OBJECT_H
#define OBJECT_H

#include<fstream>
#include<map>
#include<string>


class Object {
 public:
  /**
  *a map that links an identifier to a name and description
  */
  static std::map<int, std::pair<std::string, std::string> ObjectMap;

  /**
  *set the objectMap
  */
  static void setMap();

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
