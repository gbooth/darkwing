#ifndef LEVER_H
#define LEVER_H

#include "RoomObject.h"


class Lever : public RoomObject {
 public:
  /**
  *constructor
  *@param ident the identifier of the lever
  *@param mode the state of the switch on/off
  *@throw if ident doesn't describe a lever
  */
  Lever(int ident, bool mode = false);

  /**
  *destructor
  */
  virtual ~Lever();

  /**
  *sets the state of the lever
  *@param flip set the state of the RoomObject to flip
  */
  void setLever(bool flip);
};

#endif // LEVER_H
