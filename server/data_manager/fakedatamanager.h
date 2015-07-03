#ifndef FAKEDATAMANAGER_H
#define FAKEDATAMANAGER_H

#include "datamanager.h"

class FakeDataManager : public DataManager
{
public:

    bool authentification(const QString &login, const QString &password) override;
    User getUser( const QString &login, const QString &password) override;
    User getUser( const QString &id) override;

    IdTitleMap getProfessionsList(const qint64 limit = 0 ) override;
    IdTitleMap getLessonsList(    const QString &profession_id, const qint64 limit = 0) override;
    IdTitleMap getThemesList(     const QString &lesson_id    , const qint64 limit = 0) override;
    IdTitleMap getQuestionsList(  const QString &theme_id     , const qint64 limit = 0) override;
    IdTitleMap getAnswersList(    const QString &question_id  , const qint64 limit = 0) override;

    Profession getProfession( const QString &profession_id ) override;
    Lesson     getLesson(     const QString &lesson_id )     override;
    Theme      getTheme(      const QString &theme_id )      override;
    Question   getQuestion(   const QString &question_id )   override;
    Answer     getAnswer(     const QString &answer_id )     override;

    bool addProfession(                              const Profession &profession) override;
    bool addLesson(   const QString &profession_id , const Lesson     &lesson )    override;
    bool addTheme(    const QString &lesson_id     , const Theme      &theme )     override;
    bool addQuestion( const QString &theme_id      , const Question   &question )  override;
    bool addAnswer(   const QString &question_id   , const Answer     &answer )    override;

    bool addUser( const User &user ) override;
};

#endif // FAKEDATAMANAGER_H
