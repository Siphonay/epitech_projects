//
// Created by joa_b on 14/01/17.
//

#include "GiftPaper.hh"
#include "error.h"
#include "Box.hh"

Box::Box(std::string const &title, std::string const &type): Wrap(title, type) {
this->_istaken = false;
  this->_isopen = false;
  this->_iswrap = false;
  this->_isempty = false;
  this->_ispaper = false;
}

Box::~Box() {

}

void Box::set_inbox(Object *o) {
if (this->_inbox != NULL)
    {
      EXCEPTION("The Box is full");
      return;
    }
  this->_isempty = false;
  this->_istaken = false;
  this->_inbox = o;
}

Object *Box::getInbox() const {
    return (this->_inbox);
}

bool Box::isOpen(void) {
    return (this->_isopen);
}

bool Box::isWrap(void) {
    return (this->_iswrap);
}

bool Box::isTaken() const {
    return (this->_istaken);
}

void Box::take() {
if (this->_iswrap == true || this->_isopen == false)
    {
      EXCEPTION("The box is closed, so you cannot take it");
      return;
    }
  this->_istaken = true;
  this->_isempty = true;
  this->_iswrap = false;
  this->_isopen = true;
  this->_inbox = NULL;
  std::cout << "whistles while working" << std::endl;
}

void Box::openMe() {
if (this->_iswrap == true || this->_isopen == false)
    {
      EXCEPTION("The box is closed, so you cannot take it");
      return;
    }
  this->_istaken = true;
  this->_isempty = true;
  this->_iswrap = false;
  this->_isopen = true;
  this->_inbox = NULL;
  std::cout << "whistles while working" << std::endl;
}

void Box::closeMe() {
    this->_isopen = false;
}

void Box::setGiftPaper() {
this->_ispaper = true;
}
