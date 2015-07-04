#include "user.h"

QString User::getLogin() const
{
    return _login;
}

QString User::getApiVersion() const
{
    return _apiVersion;
}

QString User::getFullName() const
{
    return _fullName;
}

QString User::getGroup() const
{
    return _group;
}

void User::setLogin( const QString &name )
{
    _login = name;
}

void User::setApiVersion( const QString &version )
{
    _apiVersion = version;
}

void User::setFullName(const QString &fullName)
{
    _fullName = fullName;
}

void User::setGroup(const QString &group)
{
    _group = group;
}
