//
// main.cpp for  in /home/spare/julien/gkrellm/src
//
// Made by sparepedago sparepedago
// Login   <spare@epitech.net>
//
// Started on  Sat Jan 21 21:08:31 2017 sparepedago sparepedago
// Last update Sun Jan 22 01:18:56 2017 sparepedago sparepedago
//

#include "ModuleSys.hpp"
#include <vector>

int	main()
{
  std::vector<IMonitorModule *>	m;

  m.push_back(new ModuleSys(1, Module::SYSTEM));

  for (std::vector<IMonitorModule *>::iterator it = m.begin(); it != m.end(); it++)
    {
      (dynamic_cast<ModuleSys *>(*it));
    }
}
