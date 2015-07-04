#include "lesson.h"

Lesson::Lesson(const QString &name)
{
    _name = name;
}

QString Lesson::getId()const
{
    return _id;
}

QString Lesson::getName()const
{
    return _name;
}

QString Lesson::getTitle() const
{
    return _title;
}

QLocale::Language Lesson::getLang() const
{
    return _lang;
}

QVector<Theme> Lesson::getThemes() const
{
    return _themes;
}

void Lesson::setId( const QString &id )
{
    _id = id;
}

void Lesson::setName( const QString &name )
{
    _name = name;
}

void Lesson::setTitle(const QString &title)
{
    _title = title;
}

void Lesson::setLang(const QLocale::Language &lang)
{
    _lang = lang;
}

void Lesson::pushTheme(const Theme &theme)
{
    _themes.push_back(theme);
}
