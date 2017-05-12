//
// graphModule.cpp for rush 3 in /home/sam/Rendu/Piscine_CPP/gkrellm/include
// 
// Made by Alexis Viguié
// Login   <sam@epitech.net>
// 
// Started on  Sun Jan 22 01:43:03 2017 Alexis Viguié
// Last update Sun Jan 22 04:43:56 2017 Alexis Viguié
//

#include <QString>
#include "ModuleName.hpp"
#include "graphModule.hpp"

GraphFrameModuleName::GraphFrameModuleName()
  : QFrame()
{
  this->setFrameStyle(QFrame::StyledPanel | QFrame::Plain);
  this->setFixedSize(100, 100);
  this->_LabelUserName->setText
    (QString::fromStdString((dynamic_cast<ModuleName *>(this))->getUserName()));
  this->_LabelHostName->setText
    (QString::fromStdString((dynamic_cast<ModuleName *>(this))->getHostName()));
  this->_LabelUserName->move(0, 0);
  this->_LabelUserName->move(0, 14);
}
