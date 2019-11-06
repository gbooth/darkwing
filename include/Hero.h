#ifndef HERO_H
#define HERO_H

#include <Person.h>
#include <string>
#include <Room.h>
#include <Direction.h>

class Hero : public Person
{
  public:
    Hero(int, std::pair<int,int>pos , int health, int damageValue);
    virtual ~Hero();
    std:: string inspect(Object);
    void mv(Direction);
  protected:

  private:
};

#endif // HERO_H
