/**
 *@author Ben Hunt
 *@date 2019-11
 */

#ifndef LEVER_H
#define LEVER_H
#include "RoomObject.h"
#include <vector>
#include <utility>

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

  /**
   * sets the depLever vector
   * @param l the pair of lever* and a bool
   */
  void setDepLever(std::pair<Lever*, bool> l);

  /**
   * @returns depLever
   */
  std::vector<std::pair<Lever*, bool>> getDepLever();

 private:
  std::vector<std::pair<Lever*, bool>> depLever;
};

#endif // LEVER_H
