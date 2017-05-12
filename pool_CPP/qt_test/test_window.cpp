#include "test_window.hpp"
#include <QApplication>
#include <QPushButton>
#include <QProgressBar>
#include <QTimer>
#include <cstdio>
#include <cstring>

void	TestWindow::progressIncrement()
{
  if (this->_progress_bar->value() < this->_progress_bar->maximum())
    this->_progress_bar->setValue(this->_progress_bar->value() + 1);
}

void	TestWindow::progressDecrement()
{
  if (this->_progress_bar->value() > this->_progress_bar->minimum())
    this->_progress_bar->setValue(this->_progress_bar->value() - 1);;
}

void	TestWindow::setMemory()
{
  FILE	*awkFile;
  char	*awkOutput;

  awkFile = popen("free | grep Mem | awk '{print int($3/$2 * 100)}'", "r");
  awkOutput = new char[3];
  fgets(awkOutput, 3, awkFile);
  this->_progress_bar->setValue(atoi(awkOutput));
  pclose(awkFile);
  delete awkOutput;
}

TestWindow::TestWindow() : QWidget()
{
  QTimer	*timer = new QTimer(this);
  
  _plus_button = new QPushButton("+", this);
  _minus_button = new QPushButton("-", this);
  _progress_bar = new QProgressBar(this);
  _plus_button->move(10, 10);
  _minus_button->move(10, 75);
  _progress_bar->move(100, 10);
  _progress_bar->setValue(50);
  _progress_bar->setOrientation(Qt::Vertical);
  QObject::connect(_plus_button, SIGNAL(released()),
		   this, SLOT(progressIncrement()));
  QObject::connect(_minus_button, SIGNAL(released()),
		   this, SLOT(progressDecrement()));
  QObject::connect(timer, SIGNAL(timeout()),
    this, SLOT(setMemory()));
  timer->start(17);
}
