//
// main.cpp for my_convert_temp in /home/sam/Rendu/Piscine_CPP/cpp_d06/ex01
// 
// Made by Alexis Viguié
// Login   <sam@epitech.net>
// 
// Started on  Mon Jan  9 15:03:40 2017 Alexis Viguié
// Last update Mon Jan  9 16:24:35 2017 Alexis Viguié
//

#include <iostream>
#include <iomanip>
#include <string>

int   		main(void)
{
  double   	temperature;
  std::string	unit;

  std::cin >> temperature;
  std::cin >> unit;
  if (!unit.compare("Celsius"))
    {
      temperature = temperature * 9 / 5 + 32;
      unit = " Fahrenheit";
    }
  else if (!unit.compare("Fahrenheit"))
    {
      temperature = (temperature - 32) * 5 / 9;
      unit = " Celsius";
    }
  std::cout <<
    std::setprecision(3) << std::fixed <<
    std::right << std::setw(16) <<
    temperature <<
    std::internal << std::setw(16) <<
    unit << std::endl;
  return (0);
}
