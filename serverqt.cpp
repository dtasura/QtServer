#include "serverqt.h"
#include "ui_serverqt.h"

ServerQt::ServerQt(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ServerQt)
{
    ui->setupUi(this);
    initServer();
    connect(ui->btnClose, &QAbstractButton::clicked, this, &QWidget::close);
    // si detecta que alguien manda una señal de coneccion, el servidor responde con el slot
    connect(serverSocket, &QTcpServer::newConnection, this, &ServerQt::sendRandonMessage);
}

ServerQt::~ServerQt()
{
    delete ui;
}

void ServerQt::sendRandonMessage()
{
    qDebug() << "sendRandonMessage ...";
    // defino un canal de comunicaciones
    QByteArray qByteArray;
    // configuro los stream que iran por el canal con permisos de escritura
    QDataStream aDataStream(&qByteArray, QIODevice::WriteOnly);
    // escoge y prepara un mensaje aleatorio
    QString atRandomMessage = randomMessage[QRandomGenerator::global()->bounded(randomMessage.size())];
    ui->sendMsg->setText(atRandomMessage);
    // write to stream
    aDataStream << atRandomMessage;

    //sent it
    QTcpSocket *clientSocket = serverSocket->nextPendingConnection();
    connect(clientSocket, &QAbstractSocket::disconnected, clientSocket, &QObject::deleteLater);
    clientSocket->write(qByteArray);
    clientSocket->disconnectFromHost();
}

void ServerQt::initServer()
{
    qDebug() << "init server ...";
    for ( int i = 1; i <= 50 ; i++ ) {
        randomMessage << "mesaje aleatorio " + QString::number(i);
    }

    serverSocket = new QTcpServer(this);
    if(!serverSocket->listen()){
        qDebug() << "Server Error " + serverSocket->errorString();
        return;
    }
    QString port = QString::number(serverSocket->serverPort());
    QString ipAddress;

    QList<QHostAddress> ipAddressList = QNetworkInterface::allAddresses();
    //qDebug() << ipAddressList;
    for (int i=0; i<ipAddressList.size(); i++) {
        if (ipAddressList.at(i) != QHostAddress::LocalHost && ipAddressList.at(i).toIPv4Address()) {
            ipAddress = ipAddressList.at(i).toString();
            break;
        }
    }
    ui->textHost->setText("ip: " + ipAddress + " port: " + port);
}

