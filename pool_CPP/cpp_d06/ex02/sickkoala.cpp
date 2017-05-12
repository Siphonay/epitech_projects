//
// sickkoala.cpp for SickKoala in /home/sam/Rendu/Piscine_CPP/cpp_d06/ex02
// 
// Made by Alexis Viguié
// Login   <sam@epitech.net>
// 
// Started on  Mon Jan  9 17:10:32 2017 Alexis Viguié
// Last update Mon Jan  9 18:51:29 2017 Alexis Viguié
//

#include <iostream>
#include <string>
#include <locale>
#include "sickkoala.h"

SickKoala::SickKoala(std::string name)
{
  this->name = name;
}

SickKoala::~SickKoala(void)
{
  std::cout <<
    "Mr. " << this->name << ": Kreooogg!! Je suis gueriiii!" << std::endl;
}

void	SickKoala::poke(void)
{
  std::cout <<
    "Mr." << this->name << "Gooeeeeerk!! :'(" << std::endl;
}

bool		SickKoala::takeDrug(std::string drug)
{
  bool		ret_drug;
  std::string	downcase_drug;
  
  for (std::string::size_type counter = 0; counter < drug.length(); ++counter)
    downcase_drug += std::tolower(drug[counter], std::locale("en_US.utf8"));
  if ((ret_drug  =! downcase_drug.compare("mars")))
    std::cout << "Mr. " << this->name << ": Mars, et ca kreog!" << std::endl;
  else if ((ret_drug =! drug.compare("Buronzand")))
    std::cout << "Mr. " << this->name <<
      ": Et la fatique a fait son temps!" << std::endl;
  return (ret_drug);
}

void		SickKoala::overDrive(std::string msg)
{
  std::cout <<
    msg.replace(msg.find("Kreog"), std::string("Kreog").length(), "1337") <<
    std::endl;
}
