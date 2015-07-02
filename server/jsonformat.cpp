#include "jsonformat.h"


QJsonObject JsonFormat::professionToJsonObj( const Profession &prof )
{
    QJsonArray jLessons;
    for( auto i = 0; i < prof.getLessons().count(); i++ )
    {
        jLessons.append( lessonToJsonObject( prof.getLessons().at( i ) ) );
    }

    QJsonObject jProfession{
        { "id", prof.getId() },
        { "title", prof.getTitle() },
        { "lessons", jLessons }
    };

    return jProfession;
}

QJsonObject JsonFormat::lessonToJsonObject( const Lesson &lesson )
{
    QJsonArray jThemes;
    QVector<Theme> themes = lesson.getThemes();

    for( auto it = themes.begin(); it != themes.end(); ++it )
    {
        jThemes.push_back( themeToJsonObject( *it ) );
    }

    QJsonObject jLesson{
        { "id", lesson.getId() },
        { "title", lesson.getTitle() },
        { "themes", jThemes }
    };

    return jLesson;
}

QJsonObject JsonFormat::themeToJsonObject( const Theme &theme )
{
    QJsonArray jQuestions;

    QVector<Question> questions = theme.getQuestions();

    for( auto it = questions.begin(); it != questions.end(); ++it ) {
        jQuestions.push_back( questionToJsonObject( *it ) );
    }

    QJsonObject response{
        { "id", theme.getId() },
        { "title", theme.getTitle() },
        { "questions", jQuestions }
    };

    return response;
}

QJsonObject JsonFormat::questionToJsonObject( const Question &question )
{
    QJsonArray jAnswers;
    QVector<Answer> answers = question.getAnswers();

    for( auto it = answers.begin(); it != answers.end(); ++it )
    {
        jAnswers.push_back( answerToJsonObject( *it ) );
    }

    QJsonObject jQuestion{
        { "id", question.getId() },
        { "text", question.getText() },
        { "type", question.getType() },
        { "answers", jAnswers }
    };

    return jQuestion;
}

QJsonObject JsonFormat::answerToJsonObject( const Answer &answer )
{
    QJsonObject jAnswer{
        { "id", answer.getId() },
        { "text", answer.getValue() },
        { "valid", answer.isValid() }
    };

    return jAnswer;
}


QJsonObject JsonFormat::profListToJsonObj( const IdTitleMap &list )
{
//    qDebug() << "[JsonFormat::profListToJsonObj] "<< list;
    return idTitleMapToJsonObj( list, Codes::Prof, reqLists::profList );
}

QJsonObject JsonFormat::lessonsListToJsonObj( const IdTitleMap &list )
{
    return idTitleMapToJsonObj( list, Codes::Lessons, reqLists::lessonsList );
}

QJsonObject JsonFormat::themesListToJsonObj( const IdTitleMap &list )
{
    return idTitleMapToJsonObj( list, Codes::Themes, reqLists::themesList );
}

QJsonObject JsonFormat::idTitleMapToJsonObj( const IdTitleMap &list, int code, const QString &listName )
{
    QJsonArray jArray
        = mapListTojArray( list );
    QJsonObject response{
        { listName, jArray }
    };
    QJsonObject jList{
        { "code", code },
        { "response", response }
    };

    return jList;
}

QJsonArray JsonFormat::mapListTojArray( const IdTitleMap &map )
{
    QJsonArray jArray;
  //  QMapIterator<QString, QString> i( map );
    int j = 0;
   /* while( i.hasNext() )
    {*/
    for( auto it = map.begin(); it != map.end(); ++it )
    {
//        qDebug() << "[JsonFormat::mapListTojArray] #" << j << " key:" << it.key() << " value:" << it.value();
        jArray.append(
            mapListItemtojObject( it.key(), it.value() ) );
//        i.next();
        j++;
    }

    return jArray;
}
QJsonObject JsonFormat::mapListItemtojObject( const QVariant &key, const QVariant &value )
{
//  qDebug() << "[JsonFormat::mapListItemtojObject] > key: " << key << " value: " << value;
  QJsonObject obj
  {
    { "id", key.toInt() },
    { "title", value.toString() }
  };

    return obj;
}
