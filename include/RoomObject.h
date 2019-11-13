/**
*@author Ben Hunt
*@date Nov. 2019
*/

#ifndef ROOMOBJECT_H
#define ROOMOBJECT_H

#include "Object.h"


class RoomObject : public Object {
 public:
  /**
  *constructor
  *@throw invalid_id error if id is not on file and id is not correct type
  */
  RoomObject(int id, bool state = false);

  virtual ~RoomObject();

  /**
  *@return the state of the room object
  */
  bool getState();

  void setState(bool);

 private:
  bool state;
};

#endif // ROOMOBJECT_H
