#pragma once

#include <QString>

class Answer
{
    QString _id;
    QString _value;
    bool    _valid = false;
public:
    Answer(){}
    Answer(const QString &value, const bool valid);
    Answer( const QString &text, const bool valid, const QString &type );

    QString getId()const;
    QString getValue()const;
    bool isValid()const;

    void setId(const QString &id);
    void setValue(const QString &value);
    void setValid(const bool valid);
};
