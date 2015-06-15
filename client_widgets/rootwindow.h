#ifndef ROOTWINDOW_H
#define ROOTWINDOW_H

#include <QMainWindow>
#include "networkquerymanager.h"
#include "jsonparser.h"
#include "button.h"

namespace Ui {
  class RootWindow;
}

namespace PageIndex{
namespace RootWindow {
     enum PageIndex{Config = 0, TestProcess = 1, Administr };
}

}


class RootWindow : public QMainWindow
{
  Q_OBJECT
private:
  Ui::RootWindow *ui;

  NetworkQueryManager *_netMan;
  JsonParser *_jParser;
  QVector<strQuestions> _questions;

  void questionSelected(int id);
public:
  explicit RootWindow(QWidget *parent = 0);
  ~RootWindow();



  void connectSignals();
public slots:

private slots:

 // void on_PButton_Start_BeginTest_clicked();
  void setProfs(IdTitleMap profList);
  void setLessonsList(IdTitleMap lessonsList);
  void setThemesList( IdTitleMap themeList );
  void setMaxQuestionsCount(qint64 maxCount);
  //void setCourses(IdTitleMap coursesList);

  void on_ComboBox_Config_Profession_currentIndexChanged(int index);
  void on_ComboBox_Config_Lessons_currentIndexChanged(int index);
  void on_ComboBox_Config_Theme_currentIndexChanged(int index);
  void on_PButton_Config_Begin_clicked();
  void setQuestions(QVector<strQuestions> questions);
};

#endif // ROOTWINDOW_H