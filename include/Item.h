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
  ~Item() {}
  int getItemValue();
  /**
   *@param itemValue will give the status of the value for the item
   */
 private:
  /**
   *@param itemValue will give the status of the value for the item
   */
  int itemValue;
};

#endif // ITEM_H_INCLUDED
