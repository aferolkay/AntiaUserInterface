#include "server.h"



Server::Server(QObject *parent) //: QObject(parent)
{
     m_server = new QTcpServer();

    if(m_server->listen(QHostAddress::Any, 8080))
    {
       connect(this, &Server::newMessage, this, &Server::displayMessage);
       connect(m_server, &QTcpServer::newConnection, this, &Server::newConnection);
       qInfo("Server is listening...");
    }
    else
    {
       qInfo()<< QString("Unable to start the server: %1.").arg(m_server->errorString()) ;
        exit(EXIT_FAILURE);
    }

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(confirmConnection()));
    timer->start(4000);
}

Server::~Server()
{
    foreach (QTcpSocket* socket, connection_set)
    {
        socket->close();
        socket->deleteLater();
    }

    m_server->close();
    m_server->deleteLater();

    delete this;
}

void Server::newConnection()
{
    while (m_server->hasPendingConnections())
        appendToSocketList(m_server->nextPendingConnection());
}

void Server::appendToSocketList(QTcpSocket* socket)
{
    connection_set.insert(socket);
    connect(socket, &QTcpSocket::readyRead, this, &Server::readSocket);
    connect(socket, &QTcpSocket::disconnected, this, &Server::discardSocket);
    connect(socket, &QAbstractSocket::errorOccurred, this, &Server::displayError);
    qInfo()<<QString("INFO :: Client with sockd:%1 has just entered the room").arg(socket->socketDescriptor());
}

void Server::readSocket()
{
    QTcpSocket* socket = reinterpret_cast<QTcpSocket*>(sender());

    QByteArray data = socket->readAll();
    //qDebug() << "Received data from client:" << data;

    QString str = QString(data);

    QStringList strList = str.split( ":" );

    QStringList location = strList[1].split(",");

    last_x = location[0].toInt();

    last_y = location[1].toInt();

    emit newLocation();
    // placeBall(location[0].toInt(),location[1].toInt());


}

void Server::discardSocket()
{
    QTcpSocket* socket = reinterpret_cast<QTcpSocket*>(sender());
    QSet<QTcpSocket*>::iterator it = connection_set.find(socket);
    if (it != connection_set.end()){
        displayMessage(QString("INFO :: A client has just left the room").arg(socket->socketDescriptor()));
        connection_set.remove(*it);
    }    
    socket->deleteLater();
}

void Server::displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
        case QAbstractSocket::RemoteHostClosedError:
        break;
        case QAbstractSocket::HostNotFoundError:
            qInfo( "The host was not found. Please check the host name and port settings.");
        break;
        case QAbstractSocket::ConnectionRefusedError:
            qInfo( "The connection was refused by the peer. Make sure QTCPServer is running, and check that the host name and port settings are correct.");
        break;
        default:
            QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());
            qInfo()<< QString("The following error occurred: %1.").arg(socket->errorString());
        break;
    }
}



void Server::sendMessage(QTcpSocket* socket,QString message)
{
    if(socket)
    {
        if(socket->isOpen())
        {
            QDataStream socketStream(socket);
            socketStream.setVersion(QDataStream::Qt_5_15);

            QByteArray byteArray = message.toUtf8();
            
            socketStream << byteArray;
        }
        else
           qInfo("Socket doesn't seem to be opened");
    }
    else
        qInfo("Not connected");
}

void Server::broadcastMessage(QString message){
    foreach(QTcpSocket* socket , connection_set){
        sendMessage(socket,message);
    }
}

void Server::displayMessage(const QString& str)
{
    qInfo()<<str;
}

void Server::confirmConnection(){
    foreach(QTcpSocket* socket , connection_set){
        sendMessage(socket,QString("InterfaceON"));
    }
}
