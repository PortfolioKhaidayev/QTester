#pragma once
#include "qobject.h"
#include "tcpserver.h"
#include "db/sqlmgr.h"
#include "users/usercontrol.h"
#include "requestsmanager.h"

class NetworkManager :
    public QObject
{
    Q_OBJECT
private:
    TcpServer *_server;

    void connectSlots();
signals:
    void newClientConnected(QTcpSocket *client);
public slots:
    void newClient(QTcpSocket* client);
    void inputQuery( QString, QTcpSocket* );
public:
    NetworkManager( const int port );
    ~NetworkManager();
};

