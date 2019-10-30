#ifndef OBJECT_H
#define OBJECT_H

#include<map>
#include<string>

class Object
{
  public:
     /**
    *an enum holding all of our identifiers
    */
    enum Identifier{chest, sword, spear, axe, Fred};

    /**
    *constructor
    */
    Object(Identifier a = sword) :id{a}, description{ObjectMap[a]} {};

    /**
    *destructor
    */
    virtual ~Object();


    /**
    *a map that links an identifier to a description
    */
    std::map<Identifier, std::string> ObjectMap;

    /**
    *sets will set ObjectMap to map to a description
    */
    void setMap();

    /**
    *get Object Identifier
    */
    Identifier getID();

    /**
    *get Object Description
    */
    std::string getDesc();

  protected:
    std::string description;
    Identifier id;

  private:
};

#endif // OBJECT_H
