//
// koalanurse.cpp for KoalaNurse in /home/sam/Rendu/Piscine_CPP/cpp_d06/ex03
// 
// Made by Alexis Viguié
// Login   <sam@epitech.net>
// 
// Started on  Mon Jan  9 19:06:42 2017 Alexis Viguié
// Last update Mon Jan  9 19:38:41 2017 Alexis Viguié
//

#include <iostream>
#include <fstream>
#include <string>
#include "koalanurse.h"
#include "sickkoala.h"

KoalaNurse::KoalaNurse(unsigned int id)
{
  this->id = id;
}

KoalaNurse::~KoalaNurse(void)
{
  std::cout <<
    "Nurse " << this->id << ": Enfin un peu de repos!" << std::endl;
  this->id = 0;
}

void	KoalaNurse::giveDrug(std::string drug, SickKoala patient)
{
  patient.takeDrug(drug);
}

std::string	KoalaNurse::readReport(std::string file_name)
{
  std::ifstream	file_contents;
  std::string	drug_name;

  file_contents.open(file_name.c_str(), std::fstream::in);
  if (!file_contents)
    return ("");
  getline(file_contents, drug_name);
  std::cout <<
    "Nurse " << this->id << ": il faut donner un " << drug_name << " a Mr." <<
    file_name.substr(0, file_name.find('.')) << "!" << std::endl;
  return (drug_name);
}

void	KoalaNurse::timeCheck(void)
{
    
}
