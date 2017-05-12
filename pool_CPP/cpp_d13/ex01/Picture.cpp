//
// Picture.cpp for ex00 in /home/sam
// 
// Made by Alexis Viguié
// Login   <sam@epitech.net>
// 
// Started on  Mon Jan 16 17:03:43 2017 Alexis Viguié
// Last update Mon Jan 16 18:51:00 2017 Alexis Viguié
//

#include <string>
#include <fstream>
#include <iostream>
#include <cstring>
#include "Picture.h"

Picture::Picture()
{
  this->data = std::string("");
}

Picture::Picture(const std::string& file)
{
  char		eof_c = std::char_traits<char>::eof();
  char		*file_name;
  std::ifstream	file_stream;

  file_name = new char [file.length() + 1];
  strcpy(file_name, file.c_str());
  file_stream.open(file_name, std::fstream::in);
  delete file_name;
  if (file_stream)
    {
      getline(file_stream, this->data, eof_c);
      file_stream.close();
    }
  else
    this->data = std::string("ERROR");
}

bool	Picture::getPictureFromFile(const std::string& file)
{
  char		eof_c = std::char_traits<char>::eof();
  char		*file_name;
  std::ifstream	file_stream;

  file_name = new char [file.length() + 1];
  strcpy(file_name, file.c_str());
  file_stream.open(file_name, std::fstream::in);
  delete file_name;
  if (file_stream)
    {
      getline(file_stream, this->data, eof_c);
      file_stream.close();
      return (true);
    }
  else
    {
      this->data = std::string("ERROR");
      return (false);
    }
}
