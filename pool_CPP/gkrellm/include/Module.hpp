//
// Module.hpp for  in /home/spare/julien/gkrellm/src
// 
// Made by sparepedago sparepedago
// Login   <spare@epitech.net>
// 
// Started on  Sat Jan 21 14:42:38 2017 sparepedago sparepedago
// Last update Sat Jan 21 21:21:29 2017 sparepedago sparepedago
//

#ifndef __MODULE__
#define __MODULE__

#include <string>
#include <fstream>
#include <iostream>
#include "IMonitorModule.hpp"

class	Module : public IMonitorModule
{
public:
  typedef	enum	e_type
    {
      CORE,
      NAME,
      SYSTEM,
      TIME
    }			ModuleType;
  Module(int, ModuleType);
  Module(Module const &);
  virtual ~Module();

  int	getId() const;
  ModuleType	getType() const;
  
  void	setId(int);
  void	setType(ModuleType);
  Module &operator=(Module const &);
  virtual void operator<<(Module const &);
private:
  int		_id;
  ModuleType  	_type;
};

#endif
