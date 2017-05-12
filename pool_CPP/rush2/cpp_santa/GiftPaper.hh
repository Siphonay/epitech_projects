//
// Created by joa_b on 14/01/17.
//

#ifndef CPP_SANTA_GIFTPAPER_HH
#define CPP_SANTA_GIFTPAPER_HH

#include <string>
#include "Wrap.hh"

class GiftPaper :public Wrap{
public:
  GiftPaper(std::string const &title, std::string const &type);
  virtual ~GiftPaper();
};

#endif //CPP_SANTA_GIFTPAPER_HH
