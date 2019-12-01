/**
 *@author Wesley Waldern
 * @date 2019-11
 */

#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED
#include <Object.h>

class Item : public Object {
 public:
  /**
   *constructor
   *@param a the id to assign to the item
   */
  Item(int a);

  /**
   * destructor
   */
  ~Item() {}

  /**
   *@return itemValue
   */
  int getItemValue();

 private:
  int itemValue;
};

#endif // ITEM_H_INCLUDED
