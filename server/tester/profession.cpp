#include "profession.h"

Profession::Profession()
{
}

Profession::Profession( const QString &name )
{
    _name = name;
}

void Profession::setId( const QString &id )
{
    _id = id;
}

void Profession::setName( const QString &name )
{
    _name = name;
}

void Profession::setTitle( const QString &title )
{
    _title = title;
}

void Profession::pushLesson( const Lesson &lesson )
{
    _lessons.push_back( lesson );
}

QString Profession::getId()const
{
    return _id;
}

QString Profession::getName()const
{
    return _name;
}

QString Profession::getTitle()const
{
    return _title;
}

QVector<Lesson> Profession::getLessons()const
{
    return _lessons;
}
