//
// ModuleSys.cpp for  in /home/spare/julien/gkrellm/src
// 
// Made by sparepedago sparepedago
// Login   <spare@epitech.net>
// 
// Started on  Sat Jan 21 23:14:06 2017 sparepedago sparepedago
// Last update Sun Jan 22 02:07:40 2017 sparepedago sparepedago
//

#include "ModuleName.hpp"

ModuleName::ModuleName(int id, Module::ModuleType type) : Module(id, type)
{
  fetch();
}

ModuleName::ModuleName(ModuleName const &m) : Module(m.getId(), m.getType())
{
  setHostName(m.getHostName());
  setUserName(m.getUserName());
}

ModuleName::~ModuleName()
{
}

std::string    ModuleName::getHostName() const
{
  return (_HostName);
}

std::string    ModuleName::getUserName() const
{
  return (_UserName);
}

std::string	ModuleName::getEnvUser() const
{
  return (getenv("USER"));
}

std::string	ModuleName::getEnvHost() const
{
  return (getenv("HOSTNAME"));
}

void        ModuleName::setHostName(std::string o)
{
  _HostName = o;
}

void        ModuleName::setUserName(std::string o)
{
  _UserName = o;
}

void       ModuleName::fetch()
{
  setUserName(getEnvUser());
  setHostName(getEnvHost());
}

ModuleName    &ModuleName::operator=(ModuleName const &m)
{
  setId(m.getId());
  setUserName(m.getUserName());
  setHostName(m.getHostName());
  setType(m.getType());
  return (*this);
}

void    ModuleName::operator<<(ModuleName const &m)
{
< std::endl << "HostName: " << m.getHostName() << std::endl << "UserName: " << m.getUserName() << std::end
