//
// main.cpp for my_cat in /home/sam/Rendu/Piscine_CPP/cpp_d06/ex00
// 
// Made by Alexis Viguié
// Login   <sam@epitech.net>
// 
// Started on  Mon Jan  9 14:50:18 2017 Alexis Viguié
// Last update Mon Jan  9 17:52:27 2017 Alexis Viguié
//

#include <iostream>
#include <fstream>
#include <string>

int		main(int ac, char **av)
{
  unsigned int	counter;
  std::ifstream	file;
  std::string	file_line; 
  char		eof_var = std::char_traits<char>::eof();

  
  if (ac < 2)
    {
      std::cerr << "my_cat: Usage: " << av[0] << " file [...]" << std::endl;
      return (84);
    }
  counter = 1;
  while (av[counter])
    {
      file.open(av[counter], std::fstream::in);
      if (!file)
	{
	  std::cerr << "my_cat: <" << av[counter] <<
	    ">: No such file or directory" << std::endl;
	  return (84);
	}
      getline(file, file_line, eof_var);
      std::cout << file_line;
      file.close();
      counter++;
    }
  return (0);
}
