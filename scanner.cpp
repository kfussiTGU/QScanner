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
    QVector<bool> results;

    QString host = hostnameEntry->text();
    QVector<int> ports;
    for(QString p : portStr)
    {
        ports.push_back(p.toInt());
    }


    results = ScannerNet::doScan(host, ports);

    for(int i = 0; i < ports.size(); i++)
    {
        QString output = QString("Port: ") + QString::number(ports[i]) + ": ";
        if(results[i])
        {
            resultWindow->setTextColor("lime");
            output += "connection succeeded!";
        }
        else
        {
            resultWindow->setTextColor("red");
            output += "conntection timed out!";
        }

        resultWindow->append(output);
    }

    //qDebug() << results;
}

void Scanner::on_clearButton_clicked()
{
    resultWindow->clear();
}
