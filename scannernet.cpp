#include "scannernet.h"
#include <QCoreApplication>
#include <QAbstractSocket>
#include <QTcpSocket>

ScannerNet::ScannerNet(QObject *parent) : QObject(parent)
{

}

QVector<bool> ScannerNet::doScan(const QString& hostname, const QVector<int>& ports)
{
    QVector<bool> result;

    QTcpSocket* socket = new QTcpSocket();

    for (int port : ports)
    {
        socket->connectToHost(hostname, port);

                if (!socket->waitForConnected(1000)) {
                    result.push_back(false);
                }
                else
                {
                    socket->disconnectFromHost();
                    result.push_back(true);
                }
            }

    return result;
}
