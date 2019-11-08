#include <Hero.h>
#include <string>
#include <utility>
#include <Exceptions.h>

Hero::Hero(int id = 3101, int dmg =1,
std::pair<int, int> pos = std::make_pair(0, 0), int health = 10): Person{id,dmg,pos,health}{
  if (id/100%10 != 1)
    throw invalid_id("ERROR: THIS ISNT DUCK NORRIS");
}



Hero::~Hero() {
  //dtor
}

