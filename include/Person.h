/** 
*@author Jorge Aceytuno id 001003732
*@date 2019-10-31
*/
#ifndef PERSON_H
#define PERSON_H
/**

#include <Object.h>
#include <utility>
/**
*This class is the declaration for Persons that will be included in the game  in the
*game CastleScape.
*/

class Person : public Object
{
  public:
/** enum that is holding the identifiers related with Persons,Villager and Enemy, participating in the game
*/
   enum person {HeroName,Duck,Wizard};
   enum villager{villager1,villager2,villager3,villager4,villager5,villager6,villager7,villager8,villager9};
   enum enemy{Enemy1,Enemy2,Enemy3,Enemy4,Enemyx};
/**The Persons,Villagers and the Enemies will be describe when the whole rooms are defined.
*also the decision if the Villagers and Enemies will be identified in the classes Vil*age*r and Enemy or create one specific class for Identifiers.
*/

/** The constructor behavior is to create a Person ,in this case because the class is abstract, we can not intanciate a Person object.g
 *@parameters for identification and position of the Person .
*/
   Person(enum  duck),pair<int,int>pos (0,0),const int hp=10,int damageVal): identifier(duck),position(pos),health (hp),damageValue(damageVal){};

/**
 *  Attack is a pure virtual method to be used for the Enemies and the Hero.
 */

virtual int Attack ()=0;

/**
*default Destructor
*/
virtual ~Person();

  protected:
pair<int,int>position;
int health;
int damageValue;
enum identifier;

  private:
};

#endif // PERSON_H
