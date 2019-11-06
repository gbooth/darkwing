/**
*@author Ben Hunt
*@date Nov. 2019
*/

#ifndef ROOMOBJECT_H
#define ROOMOBJECT_H

#include <Object.h>


class RoomObject : public Object
{
  public:
    /**
    *constructor
    *@throw invalid_id error if id is not on file
    */
    RoomObject(int id, bool state = false): Object{id}, state{state};

    virtual ~RoomObject();

    /**
    *@return the state of the room object
    */
    bool getState();

  protected:
    bool state;
  private:
};

#endif // ROOMOBJECT_H
