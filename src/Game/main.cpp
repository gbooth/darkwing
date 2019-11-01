#include "Object.h"
#include <map>
#include <fstream>
#include <iostream>

std::map<Object::Identifier, std::string> Object::ObjectMap;

int main() {
  Object::setMap();
  Object a(Object::dagger);
  std::cout << "your id: " << a.getID() << std::endl;
  std::cout << "your description: " << a.description << std::endl;
  return 0;
}
