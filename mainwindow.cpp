#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , _serialPort(nullptr)
{
    ui->setupUi(this);
    loadPorts();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnPortsInfo_clicked()
{


}

void MainWindow::loadPorts()
{
    foreach (auto  &port, QSerialPortInfo::availablePorts())
    {
        ui->cmbPorts->addItem(port.portName());
    }
}

void MainWindow::on_btnOpen_clicked()
{
    if (_serialPort != nullptr)
    {
        _serialPort->close();
        delete _serialPort;
    }
    _serialPort = new QSerialPort(this);
    _serialPort->setPortName(ui->cmbPorts->currentText());
    _serialPort->setBaudRate(QSerialPort::Baud115200);
    _serialPort->setDataBits(QSerialPort::Data8);
    _serialPort->setParity(QSerialPort::NoParity);
    _serialPort->setStopBits(QSerialPort::OneStop);
    if (_serialPort->open(QIODevice::ReadWrite))
    {
        QMessageBox::information(this, "Result", "Port Open Success");
        connect(_serialPort, &QSerialPort::readyRead, this, &MainWindow::readData);
    }
    else
    {
        QMessageBox::critical(this, "Port Error", "Unable to open specified Port");
    }
}


void MainWindow::on_btnSend_clicked()
{
    if(!_serialPort->isOpen())
    {
        QMessageBox::critical(this, "Port Error", "Port is not open");
        return;
    }
    _serialPort->write(ui->lnMessage->text().toUtf8());
    ui->lstMessage->addItem(ui->lnMessage->text());
}

void MainWindow::readData()
{
    if (!_serialPort->isOpen())
    {
        QMessageBox::critical(this, "Port Error", "Port is not open");
        return;
    }
    auto data = _serialPort->readAll();
    ui->lstMessage->addItem(QString(data));
}
