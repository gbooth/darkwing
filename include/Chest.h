#ifndef CHEST_H_INCLUDED
#define CHEST_H_INCLUDED

#include <RoomObject.h>
#include <Item.h>

class Chest: public RoomObject {

 public:
  Chest(int);
  Item getContents();

 private:
  Item contents = 4101;

};

#endif // CHEST_H_INCLUDED
