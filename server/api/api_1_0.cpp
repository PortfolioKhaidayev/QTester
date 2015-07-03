#include "api_1_0.h"

const QString API_VERSION = "1.0";

QJsonObject makeIdTitleObject(const QString &id, const QString &title){
    return QJsonObject{
      { ResponseParams::ID   , id    },
      { ResponseParams::TITLE, title }
    };
}

QJsonArray makeArrayFromIdTitleMap(const IdTitleMap &map){
    QJsonArray jsonList;
    for (auto it = map.begin(); it != map.end(); ++it) {
        QJsonObject obj = makeIdTitleObject( it.key(), it.value() );
        jsonList.append( obj );
    }

    return jsonList;
}

QJsonObject Api_1_0::invalidRequest(int &code) const
{
    code = ReplyCodes::InvalidRequest;
    return QJsonObject();
}

QJsonObject Api_1_0::lostRequiredParameter(int &code) const
{
    code = ReplyCodes::LostRequiredParameter;
    return QJsonObject();
}

QJsonObject Api_1_0::authentificationFailed(int &code) const
{
    code = ReplyCodes::AuthentificationFailed;
    return QJsonObject();
}

QJsonObject Api_1_0::serverError(int &code) const
{
    code = ReplyCodes::ServerError;
    return QJsonObject();
}

QJsonObject Api_1_0::authorisation(const QUrlQuery &query, int &code) const
{
    /// /auth?login=11po1_1&password=123456&api_version=1.0

    if ( ! query.hasQueryItem( ApiRequests::Params::LOGIN ) ){
        return lostRequiredParameter( code );
    }

    QString login    = query.queryItemValue( ApiRequests::Params::LOGIN );
    QString password = query.queryItemValue( ApiRequests::Params::PASSWORD );

    if ( ! _data->authentification( login, password ) ){
        return authentificationFailed( code );
    }

    User user = _data->getUser( login, password );
    user.setApiVersion( API_VERSION );

    UserControl &userControl = UserControl::instance();
    QString token = userControl.pushUser( user );

    code = ReplyCodes::OK;
    QJsonObject response{
        { ResponseParams::TOKEN          , token },
        { ResponseParams::FULL_USER_NAME , user.getFullName() },
        { ResponseParams::USER_GROUP     , user.getGroup() }
    };

    return response;
}

QJsonObject Api_1_0::logout(const QUrlQuery &query, int &code) const
{
    /// /logout?token=0

    if( ! query.hasQueryItem( ApiRequests::Params::TOKEN ) ){
        return lostRequiredParameter( code );
    }
    QString token = query.queryItemValue( ApiRequests::Params::TOKEN );

    UserControl &userControl = UserControl::instance();
    userControl.remove( token );

    code = ReplyCodes::OK;
    return QJsonObject();
}

QJsonObject Api_1_0::getProfessionsList(const QUrlQuery &/*query*/, int &code) const
{
    /// /get_professions_list


    IdTitleMap list = _data->getProfessionsList();

    QJsonArray jsonList = makeArrayFromIdTitleMap( list );

    code = ReplyCodes::OK;
    return QJsonObject{
        {ResponseParams::PROFESSIONS_LIST, jsonList}
    };
}

QJsonObject Api_1_0::getLessonsList(const QUrlQuery &query, int &code) const
{
    /// /get_lessons_list?profession_id=0

    QString profession_id = query.queryItemValue( ApiRequests::Params::PROFESSION_ID );
    if( profession_id.isEmpty() ){
        return lostRequiredParameter( code );
    }

    IdTitleMap list = _data->getLessonsList( profession_id );
    QJsonArray jsonArray = makeArrayFromIdTitleMap( list );

    code = ReplyCodes::OK;
    return QJsonObject{
        {ResponseParams::LESSONS_LIST, jsonArray}
    };
}

QJsonObject Api_1_0::getThemesList(const QUrlQuery &query, int &code) const
{
    /// /get_themes_list?lesson_id=0

    QString lesson_id = query.queryItemValue( ApiRequests::Params::LESSON_ID );

    if( lesson_id.isEmpty() ){
        return lostRequiredParameter( code );
    }


    IdTitleMap list = _data->getThemesList( lesson_id );
    QJsonArray jsonArray = makeArrayFromIdTitleMap( list );

    code = ReplyCodes::OK;
    return QJsonObject{
        {ResponseParams::THEMES_LIST, jsonArray}
    };
}

Api_1_0::Api_1_0()
{
//    _data = new FakeDataManager();
    _data = new DatabaseDataManager();
}

QJsonObject Api_1_0::getTheme(const QUrlQuery &query, int &code) const
{
    /// /get_theme?theme_id=0&questions_count=0&answers_count=0

    if(    ! query.hasQueryItem( ApiRequests::Params::THEME_ID )
        || ! query.hasQueryItem( ApiRequests::Params::QUESTIONS_COUNT ) ){
        return lostRequiredParameter( code );
    }

    qint64 questionsCount = 10;
    int    answersCount   = 4;

    {
        bool ok = false;
        qint64 _questionsCount = query.queryItemValue( ApiRequests::Params::QUESTIONS_COUNT ).toLongLong( & ok );

        if( ok ){
            questionsCount = _questionsCount;
        }

        if( query.hasQueryItem( ApiRequests::Params::ANSWERS_COUNT ) ){
            int _answersCount = query.queryItemValue( ApiRequests::Params::ANSWERS_COUNT ).toInt( & ok );
            if( ok ){
                answersCount  = _answersCount;
            }
        }
    }

    Theme theme;
    theme.setId( query.queryItemValue( ApiRequests::Params::THEME_ID ) );

    /// \todo select Theme
//    if( ! theme.selectFromDatabase( db, questionsCount, answersCount ) ){
//        return serverError( code );
//    }

    code = ReplyCodes::OK;
    return QJsonObject{
        { ResponseParams::THEME, JsonFormat::themeToJsonObject( theme ) }
    };
}

QJsonObject Api_1_0::responseRequest(const QUrl &url, int &code)
{
    QString request = url.path();
    QUrlQuery query( url );

    if( request == ApiRequests::AUTHORISATION )
        return authorisation(query, code);

    if( request == ApiRequests::GET_PROFESSIONS_LIST )
        return getProfessionsList(query, code);

    if( request == ApiRequests::GET_LESSONS_LIST )
        return getLessonsList(query, code);

    if( request == ApiRequests::GET_THEMES_LIST )
        return getThemesList(query, code);

    if( request == ApiRequests::GET_THEME )
        return getTheme(query, code);

    return invalidRequest(code);
}

