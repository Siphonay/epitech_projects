//
// Module.hpp for  in /home/spare/julien/gkrellm/src
//
// Made by sparepedago sparepedago
// Login   <spare@epitech.net>
//
// Started on  Sat Jan 21 14:42:38 2017 sparepedago sparepedago
// Last update Sun Jan 22 01:19:16 2017 sparepedago sparepedago
//

#ifndef __MODULE_SYS__
#define __MODULE_SYS__

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include "Module.hpp"

class	ModuleName : public Module
{
public:
  ModuleName(int, Module::ModuleType);
  ModuleName(ModuleName const &);
  virtual ~ModuleName();

  virtual void	fetch();
  std::string	getUserName() const;
  std::string	getHostName() const;
  std::string	getEnvUser() const;
  std::string	getEnvHost() const;
  void		setUserName(std::string);
  void		setHostName(std::string);

  ModuleName &operator=(ModuleName const &);
  virtual void	operator<<(ModuleName const &);
private:
  std::string	_UserName;
  std::string	_HostName;
};

#endif
