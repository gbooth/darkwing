#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <Object.h>

class Item : public Object {
 public:
  Item(int);
  virtual ~Item() {};
  int getItemValue();

 private:
  int itemValue;
};

#endif // ITEM_H_INCLUDED
