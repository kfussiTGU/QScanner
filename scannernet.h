#ifndef SCANNERNET_H
#define SCANNERNET_H

#include <QObject>
#include <QVector>

class ScannerNet : public QObject
{
    Q_OBJECT
public:
    explicit ScannerNet(QObject *parent = nullptr);
    static QVector<bool> doScan(const QString& hostname, const QVector<int>& ports);

signals:

public slots:
};

#endif // SCANNERNET_H
