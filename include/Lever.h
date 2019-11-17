/**
 *@author Ben Hunt
 *@date 2019-11
 */

#ifndef LEVER_H
#define LEVER_H
#include "RoomObject.h"
#include <vector>

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

  void setDepLever(std::pair<Lever*, bool>);
  std::vector<std::pair<Lever*, bool>> getDepLever();
 private:
  std::vector<std::pair<Lever*, bool>> depLever;
};

#endif // LEVER_H
