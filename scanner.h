#ifndef SCANNER_H
#define SCANNER_H

#include "ui_scanner.h"
#include "scannernet.h"

class Scanner : public QWidget, private Ui::Scanner
{
    Q_OBJECT

public:
    explicit Scanner(QWidget *parent = nullptr);
private slots:
    void on_startButton_clicked();
    void on_clearButton_clicked();

private:
    ScannerNet* m_scan;
};

#endif // SCANNER_H
