#ifndef TEST_WINDOW_H_
# define TEST_WINDOW_H_

# include <QApplication>
# include <QWidget>
# include <QPushButton>
# include <QProgressBar>

class			TestWindow : public QWidget
{
  Q_OBJECT
  
public:
  TestWindow();

private:
  QPushButton		*_plus_button;
  QPushButton		*_minus_button;
  QProgressBar		*_progress_bar;

public slots:
  void			progressIncrement();
  void			progressDecrement();
  void			setMemory();
};

#endif /* !TEST_WINDOW_H_ */
