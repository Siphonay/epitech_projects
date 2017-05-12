//
// Module.hpp for  in /home/spare/julien/gkrellm/src
//
// Made by sparepedago sparepedago
// Login   <spare@epitech.net>
//
// Started on  Sat Jan 21 14:42:38 2017 sparepedago sparepedago
// Last update Sun Jan 22 01:55:37 2017 sparepedago sparepedago
//

#ifndef __MODULE_SYS__
#define __MODULE_SYS__

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Module.hpp"

class	ModuleSys : public Module
{
public:
  ModuleSys(ModuleSys const &);
  virtual ~ModuleSys();

  virtual void	fetch();
  std::string	getOs() const;
  std::string	getKernelVersion() const;
  void		setOs(std::string);
  void		setKernelVersion(std::string);
  static ModuleSys *createInstance(int);
  ModuleSys &operator=(ModuleSys const &);
  virtual void	operator<<(ModuleSys const &);
private:
  std::string	_Os;
  std::string	_KernelVersion;
  ModuleSys(int, Module::ModuleType);
  static ModuleSys	*sys;
};

#endif
