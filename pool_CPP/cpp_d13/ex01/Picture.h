//
// Picture.h for ex00 in /home/sam/Rendu/Piscine_CPP/cpp_d13/ex00
// 
// Made by Alexis Viguié
// Login   <sam@epitech.net>
// 
// Started on  Mon Jan 16 16:55:38 2017 Alexis Viguié
// Last update Mon Jan 16 18:54:50 2017 Alexis Viguié
//

#ifndef PICTURE_H_
# define PICTURE_H_

# include <string>

class		Picture
{
public:
  std::string	data;
  bool		getPictureFromFile(const std::string& file);
  Picture();
  Picture(const std::string& file);
};

#endif /* !PICTURE_H_ */
