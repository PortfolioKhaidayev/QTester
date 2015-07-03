#include "fakedatamanager.h"

bool FakeDataManager::authentification(const QString &login, const QString &password)
{
    if(    login    == "test"
        && password == "test"){
        return true;
    }
    return false;
}

User FakeDataManager::getUser(const QString &id)
{
    User user;
    user.setApiVersion( "1.0" );
    user.setLogin( "Tester" );
    user.setFullName( "Tester Full Name" );
    user.setGroup( "11po_1" );

    return user;
}

User FakeDataManager::getUser(const QString &login, const QString &password)
{
    User user;
    user.setApiVersion( "1.0" );
    user.setLogin( "Tester" );
    user.setFullName( "Tester Full Name" );
    user.setGroup( "11po_1" );

    return user;
}

IdTitleMap FakeDataManager::getProfessionsList(const qint64 limit)
{
    qint64 _limit;
    if( limit <= 0 )
        _limit = 10;

    IdTitleMap professionsList;
    for (int i = 0; i < _limit; ++i) {
        QString id = QString::number( i );
        professionsList[ id ] = "Profession title " + id;
    }

    return professionsList;
}

IdTitleMap FakeDataManager::getLessonsList(const QString &profession_id, const qint64 limit)
{
    qint64 _limit;
    if( limit <= 0 )
        _limit = 10;

    IdTitleMap lessonsList;
    for (int i = 0; i < _limit; ++i) {
        QString id = QString::number( i );
        lessonsList[ id ] = "Lesson title " + id;
    }

    return lessonsList;
}

IdTitleMap FakeDataManager::getThemesList(const QString &lesson_id, const qint64 limit)
{
    qint64 _limit;
    if( limit <= 0 )
        _limit = 10;

    IdTitleMap themesList;
    for (int i = 0; i < _limit; ++i) {
        QString id = QString::number( i );
        themesList[ id ] = "Theme title " + id;
    }

    return themesList;
}

IdTitleMap FakeDataManager::getQuestionsList(const QString &theme_id, const qint64 limit)
{
    qint64 _limit;
    if( limit <= 0 )
        _limit = 10;

    IdTitleMap questionsList;
    for (int i = 0; i < _limit; ++i) {
        QString id = QString::number( i );
        questionsList[ id ] = "Question title " + id;
    }

    return questionsList;
}

IdTitleMap FakeDataManager::getAnswersList(const QString &question_id, const qint64 limit)
{
    qint64 _limit;
    if( limit <= 0 )
        _limit = 10;

    IdTitleMap answersList;
    for (int i = 0; i < _limit; ++i) {
        QString id = QString::number( i );
        answersList[ id ] = "Answer title " + id;
    }

    return answersList;
}

Profession FakeDataManager::getProfession(const QString &profession_id)
{
    Profession profession;
    profession.setId( profession_id );
    profession.setName("Test profession name");
    profession.setTitle( "Test profession title" );

    return profession;
}

Lesson FakeDataManager::getLesson(const QString &lesson_id)
{
    Lesson lesson;
    lesson.setId( lesson_id );
    lesson.setLang( QLocale::English );
    lesson.setName( "Test lesson name" );
    lesson.setTitle( "Test lesson title" );

    return lesson;
}

Theme FakeDataManager::getTheme(const QString &theme_id)
{
    Theme theme;
    theme.setDifficulty( 1 );
    theme.setId( theme_id );
    theme.setName( "Test theme name" );
    theme.setTitle( "Test theme title" );

    return theme;
}

Question FakeDataManager::getQuestion(const QString &question_id)
{
    Question question;
    question.setCaseSensitivity( false );
    question.setId( question_id );
    question.setMarkAsDontKnow( false );
    question.setMarkAsError( false );
    question.setStripSpaces( false );
    question.setText( "Test question text" );
    question.setTime( QTime(0, 2, 0) );
    question.setType( "RADIO" );

    return question;
}

Answer FakeDataManager::getAnswer(const QString &answer_id)
{
    Answer answer;
    answer.setId( answer_id );
    answer.setValid( false );
    answer.setValue( "Test answer value" );

    return answer;
}

bool FakeDataManager::addProfession(const Profession &profession)
{
    return true;
}

bool FakeDataManager::addLesson(const QString &profession_id, const Lesson &lesson)
{
    return true;
}

bool FakeDataManager::addTheme(const QString &lesson_id, const Theme &theme)
{
    return true;
}

bool FakeDataManager::addQuestion(const QString &theme_id, const Question &question)
{
    return true;
}

bool FakeDataManager::addAnswer(const QString &question_id, const Answer &answer)
{
    return true;
}

bool FakeDataManager::addUser(const User &user)
{
    return true;
}



