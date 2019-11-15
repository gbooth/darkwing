/**
*@author Jorge Aceytuno  id: 001003732
*@date  2019-11-05
*/

#ifndef LOCK_H
#define LOCK_H

#include "RoomObject.h"
#include<string>
#include"Item.h"
#include<iostream>

/** This class is implemented as a derived class of Room Objects and the purpouse is
* to give access to different objects to access during the game.
*/


class Lock : public RoomObject {
 public:
  /** the constructor verify the key identifier.
  *@Parameter Identifier id. which send us to the Identifier list verification.
  *@Parameter State stat which give us the state of the lock.
  *@Parameter lockValue which give the verification for the lock.
  */
  Lock (int);

  /**
   *Default Destructor
   */
  virtual ~Lock();

  /**
   *This function will give the option to continue if the key identifier is the right one .
   * @parameter key will take to the identifier ,which will access to continue.
   */
  void unlock(Item key);

 private:
  /** This private variable is the key to have the right value for the player to open the specific object.
   */
  int lockValue;

  /** This function verify if the player is using the right key.
  *@return true is the key and lock matches.
  */
  bool checkKey(Item key);
};
#endif
