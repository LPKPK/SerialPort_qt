#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QMessageBox>

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
    void on_btnPortsInfo_clicked();

    void on_btnOpen_clicked();

    void on_btnSend_clicked();
    void readData();

private:
    Ui::MainWindow *ui;
    QSerialPort *_serialPort;
    void loadPorts();
};
#endif // MAINWINDOW_H
