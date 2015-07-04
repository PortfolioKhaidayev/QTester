#ifndef REQUESTSMANAGER_H
#define REQUESTSMANAGER_H

#include "jsonformat.h"
#include "users/usercontrol.h"
#include "tester/profession.h"
#include "api/api.h"
#include "api/apifactory.h"

#include <QUrlQuery>


namespace userGroups
{
    enum UserGroups
    {
        Admin = 0, Prepod, Student
    };
}


class RequestsManager
{
private:
    static QJsonDocument report(const int code, const QString &request, const QJsonObject &response);

public:
    static QJsonDocument request(const QUrl &url);
};


#endif
