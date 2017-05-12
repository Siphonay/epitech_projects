//
// graphModule.hpp for rush 3  in /home/sam/Rendu/Piscine_CPP/gkrellm/include
// 
// Made by Alexis Viguié
// Login   <sam@epitech.net>
// 
// Started on  Sun Jan 22 01:18:47 2017 Alexis Viguié
// Last update Sun Jan 22 02:25:40 2017 Alexis Viguié
//

#ifndef GRAPHMODULE_H_
# define GRAPHMODULE_H_

# include <QApplication>
# include <QFrame>
# include <QLabel>
# include "ModuleSys.hpp"

class	 GraphFrameModuleName : public QFrame, public IMonitorModule
{
  Q_OBJECT

public:
  GraphFrameModuleName();
private:
  QLabel	*_LabelUserName;
  QLabel	*_LabelHostName;
  };

class	GraphFrameModuleSys : public QFrame, public IMonitorModule
{
  Q_OBJECT

public:
  GraphFrameModuleSys(int id, Module::ModuleType type);
  GraphFrameModuleSys(ModuleSys const module);
  };

#endif /* !GRAPHMODULE_H_ */
