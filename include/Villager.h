#ifndef VILLAGER_H
#define VILLAGER_H

#include "Person.h"


class Villager : public Person {
 public:
  /**
  * @param idnty the id of the villager
  * @throw invalid_id error if idnty is not villager type
  */
  Villager(int idnty);

  /**
  * destructor
  */
  virtual ~Villager();

  /**
  * does nothing; implemented in Hero and enemy
  */
  void attack(Person* npc);

  /**
  * the talking aspect of a villager
  */
  void response();

  /**
   *gives a riddle
   *
   */
  bool riddle();


};

#endif // VILLAGER_H
