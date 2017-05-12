#include <QApplication>
#include <QProgressBar>
#include <QPushButton>
#include <string>
#include <iostream>
#include "test_window.hpp"

int main(int argc, char **argv)
{
 QApplication	app(argc, argv);
 TestWindow	win;

 if (argc >= 2 && !std::string(argv[1]).compare("--graphical"))
   {
     win.show();
     return (app.exec());
   }
 else
   {
     std::cout << "You launched this program in CLI mode." << std::endl;
     return (EXIT_SUCCESS);
   }
}
