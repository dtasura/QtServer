#ifndef SERVERQT_H
#define SERVERQT_H

#include <QWidget>
#include <QDebug>
#include <QTcpServer>       // para implementar el servidor
#include <QtNetwork>        // para coneccion

QT_BEGIN_NAMESPACE
namespace Ui { class ServerQt; }
QT_END_NAMESPACE

class ServerQt : public QWidget
{
    Q_OBJECT

public:
    ServerQt(QWidget *parent = nullptr);
    ~ServerQt();

private slots:
    void sendRandonMessage(); //alt + enter: muestra opciones para implementar la definicion.

private:
    Ui::ServerQt *ui;
    QTcpServer *serverSocket = nullptr;
    QVector<QString> randomMessage;
    void initServer();
};
#endif // SERVERQT_H
