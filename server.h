
#ifndef SERVER_H
#define SERVER_H

#include <QtNetwork>
#include <QObject>
#include<QDebug>
#include "globalVariables.h"

class Server : public QObject
{
    Q_OBJECT

public:
    Server(QObject *parent);
    ~Server();
    int last_x;
    int last_y;
public slots:

    void newConnection();
    void appendToSocketList(QTcpSocket *socket);
    void readSocket();
    void discardSocket();
    void displayError(QAbstractSocket::SocketError socketError);
    void sendMessage(QTcpSocket *socket, QString message);
    void displayMessage(const QString &str);
    void broadcastMessage(QString message);
protected slots:

private slots:

signals:
    void newMessage(QString);
    void newLocation();
private:
    QTcpServer* m_server;
    QSet<QTcpSocket*> connection_set;

};

#endif // SERVER_H
