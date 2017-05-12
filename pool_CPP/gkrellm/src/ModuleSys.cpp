//
// ModuleSys.cpp for  in /home/spare/julien/gkrellm/src
// 
// Made by sparepedago sparepedago
// Login   <spare@epitech.net>
// 
// Started on  Sat Jan 21 23:14:06 2017 sparepedago sparepedago
// Last update Sun Jan 22 01:55:33 2017 sparepedago sparepedago
//

#include "ModuleSys.hpp"

ModuleSys::ModuleSys(int id, Module::ModuleType type) : Module(id, type)
{
}

ModuleSys::ModuleSys(ModuleSys const &m) : Module(m.getId(), m.getType())
{
  setKernelVersion(m.getKernelVersion());
  setOs(m.getOs());
}

ModuleSys::~ModuleSys()
{
}

ModuleSys	*ModuleSys::createInstance(int id)
{
  if (sys == NULL)
    fetch();
  return (new ModuleSys(id, SYSTEM));
}

std::string    ModuleSys::getKernelVersion() const
{
  return (_KernelVersion);
}

std::string    ModuleSys::getOs() const
{
  return (_Os);
}

void        ModuleSys::setOs(std::string o)
{
  _Os = o;
}

void        ModuleSys::setKernelVersion(std::string o)
{
  _KernelVersion = o;
}

void       ModuleSys::fetch()
{
  std::ifstream t;
  std::stringstream     buff;
  std::string   data;
  std::size_t   i = 0;
  std::size_t	j = 0;
  std::size_t   space = 0;

  t.open("/proc/version");
  if (t.fail())
    {
      std::cerr <<  "Unable to find /proc/version... Nice try though." << std::endl;
      return;
    }
  buff << t.rdbuf();
  data = buff.str();
  while (space != 3)
    {
      if (data[i] == ' ')
        space++;
      i++;
    }
  _KernelVersion = data.substr(0, i);
  space = 0;
  i = data.find("SUSE");
  j = i;
  while (data[j] != ')')
    {
      j++;
      space++;
    }
  _Os = data.substr(i, space);
}

ModuleSys    &ModuleSys::operator=(ModuleSys const &m)
{
  setId(m.getId());
  setKernelVersion(m.getKernelVersion());
  setOs(m.getOs());
  setType(m.getType());
  return (*this);
}

void    ModuleSys::operator<<(ModuleSys const &m)
{
  std::cout << "Id: " << m.getId() << std::endl << "Os: " << m.getOs() << std::endl << "Kernel: " << m.getKernelVersion() << std::endl;
}
