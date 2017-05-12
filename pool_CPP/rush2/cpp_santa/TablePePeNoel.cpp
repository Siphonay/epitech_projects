/*
** TablePePeNoel.cpp for cpp_santa
**
** Made by	Alexandre Gaubert
** Login	alexandre2.gaubert@epitech.eu
**
** Started on	Sat Jan 14 16:14:04 2017 Alexandre Gaubert
** Last update	Sat Jan 14 22:30:15 2017 Alexandre Gaubert
*/

#include "TablePePeNoel.hh"
#include "ITable.hh"
#include "LittlePony.hh"
#include "Teddy.hh"
#include "ConveyorBeltPePeNoel.hh"

TablePePeNoel::TablePePeNoel()
{
  this->_cObjs = 0;
}

TablePePeNoel::~TablePePeNoel()
{

}

TablePePeNoel::TablePePeNoel(const TablePePeNoel &obj)
{

}

std::string *TablePePeNoel::look()
{
  return this->objects;
}

int TablePePeNoel::putObject(Object &obj){
  unsigned int	i = -1;
  if (this->_cObjs == 11) {
    delete this;
    return 1;
  }
  while (++i < 10) {
    if (this->objects[i].empty() && i < 9) {
      (this->objects[i]) = obj.getTitle();
      this->_cObjs += 1;
      return 0;
    }
  }
}

std::string TablePePeNoel::takeObject() {
  if (this->_cObjs > 0) {
    std::string str = this->objects[this->_cObjs - 1];
    this->objects[this->_cObjs - 1].clear();
    this->_cObjs -= 1;

    return this->objects[this->_cObjs - 1];
  }
  return NULL;
}

int main() {
  Teddy ted("Ted");
  Teddy bro("Bro");
  LittlePony pony("pony");
  LittlePony unicorn("unicorn");

  TablePePeNoel table;
  ConveyorBeltPePeNoel conv;
  table.putObject(ted);
  table.putObject(bro);
  table.putObject(pony);
  table.putObject(unicorn);

  conv.put(unicorn);
  conv.put(unicorn);
  conv.take();
  conv.put(bro);
  std::cout << conv.get() << '\n';
  int i = 0;
  std::string *objs = table.look();
  while (i < 9) {
    std::cout << i << " ==> "<< objs[i] << '\n';
    i++;
  }
}
