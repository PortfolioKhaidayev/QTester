#include "theme.h"


Theme::Theme( const QString &name )
{
    _name = name;
}

QString Theme::getId() const
{
    return _id;
}

QString Theme::getName()const
{
    return _name;
}

QString Theme::getTitle() const
{
    return _title;
}

int	Theme::getDifficulty() const
{
    return _difficulty;
}

QVector<Question> Theme::getQuestions() const
{
    return _questions;
}

void Theme::setId( const QString &id )
{
    _id = id;
}
void Theme::setName( const QString &name )
{
    _name = name;
}

void Theme::setTitle( const QString &title )
{
    _title = title;
}

void Theme::setDifficulty( const int &difficulty )
{
    _difficulty = difficulty;
}

void Theme::pushQuestion( const Question &question )
{
    _questions.push_back( question );
}

void Theme::pushQuestion( const QString &text, const QString &type )
{
    pushQuestion( Question( text, type ) );
}

void Theme::pushQuestion( const QString &text, const QString &type, const QVector<Answer> &answers )
{
    pushQuestion( Question( text, type, answers ) );
}
