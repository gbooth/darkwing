#ifndef HERO_H
#define HERO_H

#include <Person.h>
#include <string>
//#include <Room.h>
#include <Item.h>
#include <map>
#include <Direction.h>

class Hero : public Person {
 public:
  Hero(int, std::pair<unsigned int, unsigned int>);
  virtual ~Hero();
  void attack(Person*);
  std:: string inspect(Object);
  Item getWeapon();
  void setWeapon(Item);
  void mv(Direction);
  void setPosition(std::pair<unsigned int, unsigned int>);
  std::pair<unsigned int, unsigned int> getPos();

 private:
  std::map<Item, int>  inventory;
  Item weaponOfChoice = 4205;
  std::pair<uint, uint>position;
};

#endif // HERO_H
