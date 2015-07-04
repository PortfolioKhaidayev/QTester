#ifndef THEM_H
#define THEM_H

#include <QString>
#include <QVector>
#include "question.h"

class Theme
{
private:
    QString _id;
    QString _name;
    QString _title;
    int 	_difficulty = 0;
    QVector <Question> _questions;

public:
    Theme(){}
    Theme( const QString &Name );

    QString getId() const;
    QString getName() const;
    QString getTitle() const;
    int     getDifficulty() const;
    QVector <Question> getQuestions() const;

    void setId( const QString &id );
    void setName( const QString &name );
    void setTitle( const QString &title );
    void setDifficulty( const int &difficulty );
    void pushQuestion( const Question &question );
    void pushQuestion( const QString &text,
                       const QString &type );
    void pushQuestion( const QString &text,
                       const QString &type,
                       const QVector <Answer> &answers );
};

#endif

