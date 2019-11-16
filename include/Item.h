/**
 *@author Wesley Waldern
 * @date 2019-11
 */

#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED
#include <Object.h>

/**
 * This class will provide the item value using the Object class.
 */
class Item : public Object {
 public:
  Item(int);
  ~Item() {};
  int getItemValue();

  /**
   *@parameter itemValue will give the status of the value for the item
   */


 private:
  int itemValue;
};

#endif // ITEM_H_INCLUDED
