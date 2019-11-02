#ifndef HERO_H
#define HERO_H

#include <Person.h>
#include <string>

class Hero : public Person
{
  public:
    Hero(Identifier dinkleBerg, std::pair<int,int>pos = std::make_pair(0,0) , int health = 10, int damageValue = 1);
    virtual ~Hero();
    std:: string inspect(Object);
  protected:

  private:
};

#endif // HERO_H
