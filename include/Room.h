#ifndef ROOM_H
#define ROOM_H

#include "Object.h"


class Room : public Object
{
  public:
    Room(int, int);
    virtual ~Room();
    bool getHasEnemy();
    enum Direction {north, south, east west};

  private:
    list<Identifier> npcInRoom;
    list<Identifier> objectsInRoom;
    map<Directions, pair<bool, pair<int,int>>>;
    bool hasEnemy;
    list<Identifier> changedObjects;
};

#endif // ROOM_H
