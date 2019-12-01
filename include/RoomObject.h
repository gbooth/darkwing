/**
*@author Ben Hunt
*@date Nov. 2019
*/

#ifndef ROOMOBJECT_H
#define ROOMOBJECT_H

#include "Object.h"

/**
 *This function gives the Identification of the Objects in the room and the state of them.
 */

class RoomObject : public Object {
 public:
  /**
  *constructor
  *@param id the ID of the room object
  *@param state default to false.
  *@throw invalid_id error "ERROR: invalid ID for room object"
  */
  RoomObject(int id, bool state = false);

  /**
   * Destructor.
   */
  virtual ~RoomObject();

  /**
  *Gives the state of the objects in the room
  *@return state of the room object.
  */
  bool getState();

  /**
   *sets the state of the object in the room.
   * @param a bool value to set the state to
   * @return state. If the object exist or not in the room.
   */
  void setState(bool a);

 private:
  bool state;
};

#endif // ROOMOBJECT_H
