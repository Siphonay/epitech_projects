//
// IMonitorDisplay.hpp for  in /home/spare/julien/gkrellm/step1
//
// Made by sparepedago sparepedago
// Login   <spare@epitech.net>
//
// Started on  Sat Jan 21 14:38:38 2017 sparepedago sparepedago
// Last update Sat Jan 21 18:24:25 2017 thibault derbre
//

#ifndef __IMonitorDisplay__
#define __IMonitorDisplay__

class	IMonitorDisplay
{
public:
  virtual	void refresh() = 0;
  virtual	~IMonitorDisplay();
};

#endif
