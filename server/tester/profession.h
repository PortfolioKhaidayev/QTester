#pragma once
#ifndef PROFESSTION_H
#define PROFESSTION_H

#include <QString>
#include <QVector>
#include "lesson.h"
#include "db/sqlmgr.h"

typedef QMap<QString, QStringList> idThemeIdsMap;

class Profession
{
private:
    QString _id;
    QString _name;
    QString _title;
    QVector<Lesson> _lessons;

public:
    Profession();
    Profession( const QString &name );

    void setId( const QString &id );
    void setName( const QString &name );
    void setTitle( const QString &title );
    void pushLesson( const Lesson &lesson );

    QString getId() const;
    QString getName() const;
    QString getTitle() const;
    QVector<Lesson> getLessons() const;
};

#endif
