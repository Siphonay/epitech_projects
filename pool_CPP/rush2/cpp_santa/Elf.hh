//
// Elf.hh for cpp_santa in /home/brossa_f/Piscine_C++/cpp_santa
// 
// Made by Fanny BROSSAIS
// Login   <brossa_f@epitech.net>
// 
// Started on  Sat Jan 14 15:37:44 2017 Fanny BROSSAIS
// Last update Sat Jan 14 22:33:43 2017 Fanny BROSSAIS
//

class IElf
{
protected:
  virtual void takeTable() = 0;
  virtual void takeConveyor() = 0;
  virtual void putTable() = 0;
  virtual void putConveyor() = 0;
  virtual void pressINButton() = 0;
  virtual void pressOUTButton() = 0;
  virtual void arrayOnTable() = 0;
};

class ElfOfPePeNoel : public IElf
{
private:
  ElfOfPePeNoel();
  ~ElfOfPePeNoel();

  TablePePeNoel *_table;
  ConveyorBeltPePeNoel *_conveyor;
  bool  _hand;
  std::string   _typeObject;
};
