#ifndef LEVER_H
#define LEVER_H

#include "RoomObject.h"


class Lever : public RoomObject {
 public:
  /**
  *constructor
  *@param ident the identifier of the lever
  *@param mode the state of the switch on/off
  */
  Lever(int ident, bool mode);

  /**
  *Destructor
  */
  virtual ~Lever();

  /**
  *sets the state of the lever
  *@param flip set the state of the RoomObject to flip
  */
  void setLever(bool flip);
};

#endif // LEVER_H
