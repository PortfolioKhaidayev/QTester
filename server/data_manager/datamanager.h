#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QString>
#include <QMap>

#include "users/user.h"

#include "tester/profession.h"
#include "tester/lesson.h"
#include "tester/theme.h"
#include "tester/question.h"
#include "tester/answer.h"

typedef QMap<QString, QString> IdTitleMap;

class DataManager
{
private:


public:
    DataManager();

    virtual bool authentification(const QString &login, const QString &password) = 0;
    virtual User getUser( const QString &login, const QString &password) = 0;
    virtual User getUser( const QString &id) = 0;

    // Get requests :

    virtual IdTitleMap getProfessionsList(const qint64 limit = 0 ) = 0;
    virtual IdTitleMap getLessonsList(    const QString &profession_id, const qint64 limit = 0) = 0;
    virtual IdTitleMap getThemesList(     const QString &lesson_id    , const qint64 limit = 0) = 0;
    virtual IdTitleMap getQuestionsList(  const QString &theme_id     , const qint64 limit = 0) = 0;
    virtual IdTitleMap getAnswersList(    const QString &question_id  , const qint64 limit = 0) = 0;

    virtual Profession getProfession( const QString &profession_id ) = 0;
    virtual Lesson     getLesson(     const QString &lesson_id )     = 0;
    virtual Theme      getTheme(      const QString &theme_id )      = 0;
    virtual Question   getQuestion(   const QString &question_id )   = 0;
    virtual Answer     getAnswer(     const QString &answer_id )     = 0;

    // Set requests :

    virtual bool addProfession(                              const Profession &profession) = 0;
    virtual bool addLesson(   const QString &profession_id , const Lesson     &lesson )    = 0;
    virtual bool addTheme(    const QString &lesson_id     , const Theme      &theme )     = 0;
    virtual bool addQuestion( const QString &theme_id      , const Question   &question )  = 0;
    virtual bool addAnswer(   const QString &question_id   , const Answer     &answer )    = 0;

    virtual bool addUser( const User &user ) = 0;
//    virtual bool addGroup( const Group &group, const Permission &permission ) = 0;


};

#endif // DATAMANAGER_H
