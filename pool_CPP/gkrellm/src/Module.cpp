//
// module.cpp for  in /home/spare/julien/gkrellm/include
// 
// Made by sparepedago sparepedago
// Login   <spare@epitech.net>
// 
// Started on  Sat Jan 21 14:55:09 2017 sparepedago sparepedago
// Last update Sat Jan 21 21:28:19 2017 sparepedago sparepedago
//

#include "Module.hpp"

Module::Module(int id, Module::ModuleType type) : IMonitorModule()
{
  _id = id;
  _type = type;
}

Module::Module(Module const &m)
{
  setId(m.getId());
  setType(m.getType());
}


Module::~Module()
{
}

int	Module::getId() const
{
  return (_id);
}

Module::ModuleType	Module::getType() const
{
  return (_type);
}

void	Module::setId(int id)
{
  _id = id;
}

void	Module::setType(Module::ModuleType type)
{
  _type = type;
}

Module	&Module::operator=(Module const &m)
{
  setId(m.getId());
  setType(m.getType());
  return (*this);
}

void	Module::operator<<(Module const &m)
{
  std::cout << "Id:" << m.getId() << std::endl;
}
