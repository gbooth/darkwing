#ifndef OBJECT_H
#define OBJECT_H

#include<fstream>
#include<string>


class Object {
 public:
  /**
  *constructor
  *@throws invalid_id error if invalid id is passed in or if file is missing
  */
  Object(int);

  /**
  *virtual destructor
  */
  virtual ~Object();

  /**
  * @return id
  */
  int getID();

  /**
  * @return description
  */
  std::string getDesc();

  /**
  * @return name
  */
  std::string getName();

 protected:
  int id;
  std::string name;
  std::string description;
};

#endif // OBJECT_H
