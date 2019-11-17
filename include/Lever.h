/**
 *@author Ben Hunt
 *@date 2019-11
 */

#ifndef LEVER_H
#define LEVER_H
#include "RoomObject.h"
#include <list>

/**
 *This class gives the identifier for the levers
 */


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
  ~Lever();

  void setDepLever(Lever*);
  std::list<Lever*> getDepLever();
 private:
  std::list<Lever*> depLever;
};

#endif // LEVER_H
