#include <Item.h>
#include <fstream>
#include <string>
#include <Exceptions.h>

Item::Item(int id): Object{id} {
  if (id/1000 == 4) {
    if (id/100 %10 == 3) {
      switch (id) {
      case 4301:
        itemValue = -1;
        break;
      case 4302:
        itemValue = -2;
        break;
      case 4303:
        itemValue = -3;
        break;
      default:
        itemValue = -4;
      }
    }
    if (id/100%10 == 2) {
      switch (id) {
      case 4201:
        itemValue = 4;
        break;
      case 4202:
        itemValue = 8;
        break;
      case 4203:
        itemValue = 3;
        break;
      case 4204:
        itemValue = 7;
        break;
      default:
        itemValue = 2;
      }
    }
    if (id/100%10 == 1) {
      switch (id) {
      case 4101:
        itemValue = 5;
        break;
      case 4102:
        itemValue = 3;
        break;
      default:
        itemValue = 1;
      }
    }
  }

  else {
    throw invalid_id("This is not a key, potion or weapon");
  }
}


int Item::getItemValue() {
  return itemValue;
}

