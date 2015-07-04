#pragma once

#include <QString>
#include <QStringList>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>

#include "tester/profession.h"

typedef QMap<QString, QString> IdTitleMap;

class JsonFormat
{
private:
    static QJsonArray  mapListTojArray( const IdTitleMap &map );
    static QJsonObject mapListItemtojObject( const QVariant &key, const QVariant &value );


public:
    static QJsonObject professionToJsonObj( const Profession &prof );
    static QJsonObject lessonToJsonObject( const Lesson &lesson );
    static QJsonObject themeToJsonObject( const Theme &theme );
    static QJsonObject questionToJsonObject( const Question &question );
    static QJsonObject answerToJsonObject( const Answer &answer );
};
