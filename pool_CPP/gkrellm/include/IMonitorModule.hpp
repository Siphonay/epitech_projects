//
// IMonitorModule.hpp for  in /home/spare/julien/gkrellm/step1
//
// Made by sparepedago sparepedago
// Login   <spare@epitech.net>
//
// Started on  Sat Jan 21 14:38:33 2017 sparepedago sparepedago

// Last update Sun Jan 22 01:18:13 2017 sparepedago sparepedago
//

#ifndef __IMonitorModule__
#define __IMonitorModule__

class	IMonitorModule
{
public:
  virtual	void fetch() = 0;
  virtual	~IMonitorModule() {};
};

#endif
