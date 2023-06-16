#ifndef SERVERQT_H
#define SERVERQT_H
/**
* importaciones de los modulos a utilizar
*/
#include <QWidget>
#include <QDebug>
#include <QTcpServer>       // utilizado para implementar el servidor
#include <QtNetwork>        // utilizado para la conexión(comunicación)

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
    /**
    * aqui van las definiciones de los slots
    * alt + enter: muestra opciones para implementar la definición.
    */
    void sendRandonMessage();

private:
    /**
    *   aqui se declaran las variables de la Clase
    */
    Ui::ServerQt *ui;
    QTcpServer *serverSocket = nullptr;
    QVector<QString> randomMessage;
    void initServer();
};
#endif // SERVERQT_H
