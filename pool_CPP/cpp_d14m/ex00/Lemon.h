//
// Lemon.h for ex00 in /home/sam/Rendu/Piscine_CPP/cpp_d14m
// 
// Made by Alexis Viguié
// Login   <sam@epitech.net>
// 
// Started on  Tue Jan 17 09:33:02 2017 Alexis Viguié
// Last update Tue Jan 17 10:14:47 2017 Alexis Viguié
//

#ifndef LEMON_H_
# define LEMON_H_

# include <string>
# include "Fruit.h"

class Lemon: public Fruit
{
public:
  Lemon();
  ~Lemon();
  int	getVitamins();
};

#endif /* !LEMON_H_ */
