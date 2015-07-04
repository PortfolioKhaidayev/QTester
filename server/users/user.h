#ifndef USER_H
#define USER_H

#include <QString>
#include <QCryptographicHash>

class User
{
private:
    QString _login;
    QString _fullName;
    QString _group;
    QString _apiVersion = "1.0";


public:
    User(){}

    QString getLogin() const;
    QString getApiVersion() const;
    QString getFullName() const;
    QString getGroup() const;

    void setLogin( const QString &name );
    void setApiVersion( const QString &version );
    void setFullName( const QString &fullName );
    void setGroup( const QString &group );
};

#endif
