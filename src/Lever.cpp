/**
 *@author Ben Hunt
 * @date 2019-11
 */


#include "Lever.h"
#include "Exceptions.h"
#include <utility>
#include <vector>

Lever::Lever(int ident, bool mode)
  : RoomObject{ident, mode} {
  if ((ident / 100) % 10 != 3 || ident < 2301 || ident > 2399)
    throw invalid_id("ERROR: ID does not define a lever");
}

Lever::~Lever() {}

void Lever::setDepLever(std::pair<Lever*, bool> l) {
  depLever.push_back(l);
}

std::vector<std::pair<Lever*, bool>> Lever::getDepLever() {
  return depLever;
}
