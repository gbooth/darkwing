#include "Lever.h"
#include "Exceptions.h"

Lever::Lever(int ident, bool mode)
  : RoomObject{ident, mode} {
  if ((ident / 100) % 10 != 3 || ident < 2301 || ident > 2399)
    throw invalid_id("ERROR: ID does not define a lever");
}

Lever::~Lever() {}

void Lever::setLever(bool flip){
  state = flip;
}
