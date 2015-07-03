#ifndef API_1_0_H
#define API_1_0_H

#include "api.h"

#include "users/usercontrol.h"
#include "jsonformat.h"

#include "data_manager/datamanager.h"
#include "data_manager/fakedatamanager.h"
#include "data_manager/databasedatamanager.h"

namespace ApiRequests {
    const QString AUTHORISATION        = "/auth";
    const QString LOGOUT               = "/logout";
    const QString GET_PROFESSIONS_LIST = "/get_professions_list";
    const QString GET_LESSONS_LIST     = "/get_lessons_list";
    const QString GET_THEMES_LIST      = "/get_themes_list";
    const QString GET_THEME            = "/get_theme";

    namespace Params {
        const QString LOGIN    = "login";
        const QString PASSWORD = "password";
        const QString TOKEN    = "token";


        const QString PROFESSION_ID = "profession_id";
        const QString LESSON_ID     = "lesson_id";
        const QString THEME_ID      = "theme_id";

        const QString QUESTIONS_COUNT = "questions_count";
        const QString ANSWERS_COUNT = "answers_count";
    }
}

namespace ResponseParams{
    const QString TOKEN          = "token";
    const QString FULL_USER_NAME = "full_user_name";
    const QString USER_GROUP     = "user_group";

    const QString PROFESSIONS_LIST = "professions_list";
    const QString LESSONS_LIST     = "lessons_list";
    const QString THEMES_LIST      = "themes_list";

    const QString THEME = "theme";

    const QString ID = "id";
    const QString TITLE = "title";
}

class Api_1_0 : public Api
{
private:
    DataManager *_data;

    QJsonObject invalidRequest(int &code) const;
    QJsonObject lostRequiredParameter(int &code) const;
    QJsonObject authentificationFailed(int &code) const;
    QJsonObject serverError(int &code) const;

    QJsonObject authorisation(const QUrlQuery &query, int &code) const;
    QJsonObject logout(const QUrlQuery &query, int &code) const;

    QJsonObject getProfessionsList(const QUrlQuery &query, int &code) const;
    QJsonObject getLessonsList(const QUrlQuery &query, int &code) const;
    QJsonObject getThemesList(const QUrlQuery &query, int &code) const;
    QJsonObject getTheme( const QUrlQuery &query, int &code ) const;

    ~Api_1_0(){}
public:
    Api_1_0();
    QJsonObject responseRequest(const QUrl &url, int &code) override;
};

#endif // API_1_0_H
