#pragma once
#ifndef LESSON_H
#define LESSON_H

#include <QString>
#include <QVector>
#include <QLocale>
#include "theme.h"

class Lesson
{
private:
    QString _id;
    QString _name;
    QString _title;
    QLocale::Language _lang;
    int course = 1;
    QVector<Theme> _themes;
    QVector<QString> _themesIds;

public:
    Lesson(){}
    Lesson(const QString &name);

    QString getId()const;
    QString getName()const;
    QString getTitle() const;
    QLocale::Language getLang() const;
    QVector<Theme> getThemes() const;

    void setId( const QString &id );
    void setName( const QString &name );
    void setTitle( const QString &title );
    void setLang( const QLocale::Language &lang );
    void pushTheme( const Theme &theme );
};

#endif
