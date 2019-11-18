/**
*@author Jorge Aceytuno
*@date  2019-11-05
*/

#ifndef LOCK_H
#define LOCK_H

#include "RoomObject.h"
#include<string>
#include"Item.h"
#include<iostream>

/**
*This class is implemented as a derived class of Room Objects and the purpouse is
* to give access to different objects to access during the game.
*/
class Lock : public RoomObject {
 public:
  /**
  * Default constructor
  */
  Lock(int);

  /**
   *Default Destructor
   */
  virtual ~Lock();

  /**
   *This function will give the option to continue if the key identifier is the right one .
   * @param key will take to the identifier ,which will access to continue.
   */
  void unlock(Item key);

 private:
  /**
   *This private variable gives the lock value to know if is the right key.
   *@param lockValue is the value for the key.
   */
  int lockValue;

  /** This function verify if the player is using the right key.
  *@return true is the key and lock matches.
  */
  bool checkKey(Item key);
};
#endif
