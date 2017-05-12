#include <cstdio>
#include <iostream>
#include "Object.hh"
#include "Toy.hh"
#include "Teddy.hh"
#include "LittlePony.hh"
#include "Box.hh"
#include "Wrap.hh"

int main() {
  Object **objects = MyUnitTests();
  std::cout << objects[0]->getType() << '\n';
  std::cout << objects[1]->getType() << '\n';
  delete objects[0];
  delete objects[1];

    Object **tab = new Object*[4];

  MyUnitTests(tab);
  dynamic_cast<Box*>(tab[1])->openMe();
  dynamic_cast<Box*>(tab[1])->closeMe();
  dynamic_cast<Box*>(tab[1])->wrapMeThat(tab[0]);
  dynamic_cast<Box*>(tab[1])->setGiftPaper();
  dynamic_cast<Box*>(tab[1])->wrapMeThat(tab[0]);
  dynamic_cast<Box*>(tab[1])->openMe();
  dynamic_cast<Box*>(tab[1])->take();
  dynamic_cast<Box*>(tab[1])->wrapMeThat(tab[0]);
  dynamic_cast<Box*>(tab[1])->set_inbox(tab[0]);
  dynamic_cast<Box*>(tab[1])->closeMe();
  dynamic_cast<Box*>(tab[1])->wrapMeThat(tab[0]);
}
