//
// elf.cpp for cpp_santa in /home/brossa_f/Piscine_C++/cpp_santa
// 
// Made by Fanny BROSSAIS
// Login   <brossa_f@epitech.net>
// 
// Started on  Sat Jan 14 15:32:51 2017 Fanny BROSSAIS
// Last update Sat Jan 14 21:57:17 2017 Fanny BROSSAIS
//

#include <string>
#include <iostream>
#include "TablePePeNoel.hh"
#include "ConveyorBeltPePeNoel.hh"

ElfOfPePeNoel::ElfOfPePeNoel(TablePePeNoel *table, ConveyorBeltPePeNoel *conveyor)
{
  this->_table = table;
  this->_conveyor = conveyor;
}

ElfOfPePeNoel::~ElfOfPePeNoel()
{

}

void	ElfOfPePeNoel::pressINButton()
{
  activateINButton();
}

void	ElfOfPePeNoel::pressOUTButton()
{
  activateOUTButton();
}

void	ElfOfPePeNoel::takeTable()
{
  std::string	*list = look();
  if (this->_hand == true)
    {
      this->_typeObject = takeObject(list[this->_table->_cObjs]);
      this->_hand = false;
      std::cout << "I took " << this->_typeObject << "." << std::endl;
      
    }
  else
    std::cout << "I can't take more gift." << std::endl;
}

void	 ElfOfPePeNoel::takeConveyor()
{
  if (look() == NULL)
    std::cout << "There is no object on conveyor." << std::endl;
  else if (this->_hand == true)
    {
      this->_typeObject = takeObject();
      std::cout << "I took " << this->_typeObject << "." << std::endl;
      this->_hand = false;
    }
  else
    std::cout << " I have " this->_typeObject << "in my hands." << std::endl;
}

void	 ElfOfPePeNoel::putTable()
{
  if (this->_hand == false)
    {
      putObject(this->_typeObject);
      std::cout << "I put " << this->_typeObject << " on the table." << std::endl;
      this->_hand = true;
    }
  else
    std::cout << "My hands are empties." << std::endl;
}

void	 ElfOfPePeNoel::putConveyor()
{
  if (this->_hand == false)
    {
      if (look() == NULL)
	{
	  putObject(this->_typeObject);
	  std::cout << "I put " << this->_typeObject << " on the conveyor." << std::endl;
	  this->_hand == true;
	}
      else
	std::cout << "The conveyor is full." << std::endl;
    }
  else
    std::cout << "My hands are empties." << std::endl;
}

void    ElfOfPePeNoel::arrayOnTable()
{
  std::string	*list = look();
  int		i = 0;

  while (i < this->_table->_cObjs)
    {
      std::cout << "List of gift on the table :" << std::endl;
      std::cout << list[i] << std::endl;
      i++;
    }
}
