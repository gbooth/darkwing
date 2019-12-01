/**
 *@author Wesley Waldern / Gavin Booth
 *@date 2019-11
 */

#ifndef CHEST_H_INCLUDED
#define CHEST_H_INCLUDED

#include <RoomObject.h>
#include <Item.h>

/**
 *This class is used to access the contents inside the chest.
 */

class Chest: public RoomObject {
 public:
  /**
   * Default constructor that identifies the objects inside the chest.
   */
  Chest(int);

  /**
   * Default destructor to delete contents.
   */
  virtual~Chest();

  /**
   *Access the contents in the Chests.
   *@return the contents of the objects inside the chest.
   */
  Item* getContents();

 private:
  Item* contents;
};

#endif // CHEST_H_INCLUDED
