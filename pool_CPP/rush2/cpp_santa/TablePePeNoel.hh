/*
** TablePePeNoel.hh for cpp_santa
**
** Made by	Alexandre Gaubert
** Login	alexandre2.gaubert@epitech.eu
**
** Started on	Sat Jan 14 16:12:59 2017 Alexandre Gaubert
** Last update	Sat Jan 14 22:24:30 2017 Alexandre Gaubert
*/

#include "ITable.hh"
#include <vector>

#ifndef TABLEPEPENOEL_hh_
#define TABLEPEPENOEL_hh_

class TablePePeNoel : public ITable {
private:
  /* data */
public:
  TablePePeNoel ();
  virtual ~TablePePeNoel ();
  TablePePeNoel(const TablePePeNoel &obj);
  // TablePePeNoel  &operator=(const TablePePeNoel &obj);
  virtual int putObject(Object &obj);
  virtual std::string *look();
  virtual std::string takeObject();

};

#endif /* !TABLEPEPENOEL_hh_ */
