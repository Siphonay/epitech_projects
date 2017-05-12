//
// Created by joa_b on 14/01/17.
//

#ifndef CPP_SANTA_BOX_HH
#define CPP_SANTA_BOX_HH

#include <string>
#include "Wrap.hh"
#include "GiftPaper.hh"

class Box : public Wrap{
public:
Box(std::string const &title, std::string const &type);
  virtual~Box();
  void  set_inbox(Object *);
  Object        *getInbox() const;
  bool	isOpen(void);
  bool	isWrap(void);
  virtual bool  isTaken() const;
  void  take();
  void  openMe();
  void closeMe();
  void setGiftPaper();
};

#endif //CPP_SANTA_BOX_HH
