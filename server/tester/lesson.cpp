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

void Lesson::selectThemesFromDataBase( const SQLMgr &sqlManager,
                                      const QStringList &themeIds,
                                      const qint64 questionsCount,
                                      const int answersCount )
{
    for( auto i = 0; i < themeIds.size(); i++ )
    {
        Theme topic = selectTheme( themeIds.at( i ), sqlManager, questionsCount, answersCount );
        pushTheme( topic );
    }
}

Theme Lesson::selectTheme( const QString &themeId,
                           const SQLMgr &sqlManager,
                           const qint64 questionsCount,
                           const int answersCount )const
{
    using namespace Tables::Themes;
    SqlWhere _where( Fields::THEME_ID + ((themeId == Fields::THEME_ID) ? ("= " + themeId) : (" = '" + themeId + "'")) );
    QStringList _fields( { Fields::LESSON_ID,
                           Fields::NAME,
                           Fields::TITLE,
                           Fields::DIFFICULTY } );

    QSqlQuery query = sqlManager.select( TABLE_NAME, _fields, _where );

    query.first();

    Theme theme( query.value( query.record().indexOf( Tables::Themes::Fields::NAME ) ).toString() );

    theme.setTitle( query.value( query.record().indexOf( Tables::Themes::Fields::TITLE ) ).toString() );
    theme.setDifficulty( query.value( query.record().indexOf( Fields::DIFFICULTY ) ).toInt() );
    theme.setId( themeId );

    theme.selectFromDatabase( sqlManager, questionsCount, answersCount );

    return theme;
}

IdTitleMap Lesson::getLessonsList( const SQLMgr &sqlManager, const QString &profId )
{
    using namespace Tables::Lessons;

    QStringList _fields( { Fields::LESSON_ID, Fields::TITLE } );
    SqlWhere _where( Fields::PROFESSION_ID + ((profId == Fields::PROFESSION_ID) ?( "= " + profId) : ("= '" + profId + "'")) );
    IdTitleMap lessList;

    QSqlQuery query = sqlManager.select( TABLE_NAME, _fields, _where );

    while( query.next() )
    {
        QString id = query.value( query.record().indexOf( Fields::LESSON_ID ) ).toString(),
            title = query.value( query.record().indexOf( Fields::TITLE ) ).toString();

        lessList[id] = title;
    }

    return lessList;
}

void Lesson::print()const
{
    qDebug() << "Lesson(Title: " << _title << ")";

    for( auto i = 0; i < _themes.count(); i++ )
    {
        _themes.at( i ).print();
    }
}