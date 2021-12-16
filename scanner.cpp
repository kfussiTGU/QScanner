#include "scanner.h"
#include "scannernet.h"
#include <QDebug>

Scanner::Scanner(QWidget *parent) :
    QWidget(parent)
{

    m_scan = new ScannerNet;
    setupUi(this);
}


void Scanner::on_startButton_clicked()
{
    //QString host = hostnameEntry->text();
    QStringList portStr = portEntry->text().split(',');

    QVector<int> ports;
    for(QString p : portStr)
    {
        ports.push_back(p.toInt());
    }

    qDebug() << "Hostname: " << hostnameEntry->text();
    qDebug() << "Ports: " << ports;

}
