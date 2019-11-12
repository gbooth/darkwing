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
   *Default constructor ,that identify the objects inside the chest.
   * @param int that is the identifier of the  objects inside the chest.
   */
  Chest(int);

  /**
   * Default destructor.
   */
  virtual~Chest();

  /**
   *This function is in charge to access the identifier of the object.
   *@return the identifier of the objects inside the chest.
   */
   Item getContents();

   /**
    *This variable contains the object identifier.
    *The identifier 4101 ,is to have an at least one initial object at the beginning, means the chest is not empty.
    */


 private:
  Item contents = 4101;

};

#endif // CHEST_H_INCLUDED
