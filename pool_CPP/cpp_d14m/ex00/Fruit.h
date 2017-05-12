//
// Fruit.h for ex00 in /home/sam/Rendu/Piscine_CPP/cpp_d14m
// 
// Made by Alexis Viguié
// Login   <sam@epitech.net>
// 
// Started on  Tue Jan 17 09:23:33 2017 Alexis Viguié
// Last update Tue Jan 17 10:15:50 2017 Alexis Viguié
//

#ifndef FRUIT_H_
# define FRUIT_H_

# include <string>

class Fruit
{
public:
  Fruit();
  Fruit(const int& vitamins, const std::string& name);
  ~Fruit();
  virtual int	getVitamins() = 0;
  std::string	getName();
protected:
  int		_vitamins;
  std::string	_name;
};

#endif /* !FRUIT_H_ */
