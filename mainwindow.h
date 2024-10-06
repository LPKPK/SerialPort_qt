#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPortInfo>
#include <QDebug>
#include <QMessageBox>
#include <SerialPort.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnOpen_clicked();

    void on_btnSend_clicked();
    void readData(QByteArray data);

private:
    Ui::MainWindow *ui;
    void loadPorts();
    SerialPort _port;
};
#endif // MAINWINDOW_H
