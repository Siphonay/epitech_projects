//
// Banana.h for ex00 in /home/sam/Rendu/Piscine_CPP/cpp_d14m
//
// Made by Alexis Viguié
// Login   <sam@epitech.net>
//
// Started on  Tue Jan 17 09:33:02 2017 Alexis Viguié
// Last update Tue Jan 17 10:16:35 2017 Alexis Viguié
//

#ifndef BANANA_H_
# define BANANA_H_

# include <string>
# include "Fruit.h"

class Banana: public Fruit
{
 public:
  Banana();
  ~Banana();
  int	getVitamins();
};

#endif /* !BANANA_H_ */
