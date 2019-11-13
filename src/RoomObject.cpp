#include "RoomObject.h"
#include "Exceptions.h"

RoomObject::RoomObject(int id, bool st): Object{id}, state{st} {
  if (id / 1000 != 2 || id < 2101 || id > 2399) {
    throw invalid_id("ERROR: invalid ID for room object");
  }
}

RoomObject::~RoomObject() {}

bool RoomObject::getState() {
  return state;
}

void RoomObject::setState(bool s) {
  state = s;
}
