/*
** LittlePony.hh for cpp_santa
**
** Made by	Alexandre Gaubert
** Login	alexandre2.gaubert@epitech.eu
**
** Started on	Sat Jan 14 11:42:07 2017 Alexandre Gaubert
** Last update	Sat Jan 14 12:56:29 2017 Alexandre Gaubert
*/

#include "Toy.hh"

class LittlePony : public Toy {
private:
  /* data */
public:
  LittlePony (const std::string & title, const std::string & type = "littlepony");
  virtual ~LittlePony ();
  LittlePony(const LittlePony &obj);
  LittlePony  &operator=(const LittlePony &obj);
  virtual void isTaken();
};
