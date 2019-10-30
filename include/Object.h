#ifndef OBJECT_H
#define OBJECT_H


class Object
{
  public:
    Object(Identifier i) :id{i};
    virtual ~Object();

  protected:
    string description;
    Identifier id;

  private:
};

#endif // OBJECT_H
