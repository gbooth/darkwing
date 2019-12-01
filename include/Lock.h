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

class Lock : public RoomObject {
 public:
  /**
  *constructor
  *@param a the id of the lock
  */
  Lock(int a);

  /**
   *Default Destructor
   */
  virtual ~Lock();

  /**
   *This function will give the option to continue if the key identifier is the right one .
   * @param key to check if it will unlock the lock.
   */
  void unlock(Item key);

 private:
  int lockValue;
  /** This function verify if the player is using the right key.
  *@return true if the key and lock matches.
  */
  bool checkKey(Item key);
};
#endif
