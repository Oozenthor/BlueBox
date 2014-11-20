#ifndef SERIALDIALOG_H
#define SERIALDIALOG_H

#include <QDialog>
#include <QSettings>
#include <QtAlgorithms>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include "ui_serialdialog.h"

namespace Ui {
class SerialDialog;
}

class SerialDialog : public QDialog
{
  Q_OBJECT

public:
  struct SerialProfile { // Structure to hold a complete set of communication port parameters
    QString name;
    qint32 baudRate;
    QString stringBaudRate;
    QSerialPort::DataBits dataBits;
    QString stringDataBits;
    QSerialPort::Parity parity;
    QString stringParity;
    QSerialPort::StopBits stopBits;
    QString stringStopBits;
    QSerialPort::FlowControl flowControl;
    QString stringFlowControl;
  };

  explicit SerialDialog(QWidget *parent = 0);
  ~SerialDialog();

  SerialProfile profile() const;

private slots:
  void showPortInfo(int idx);
  void on_applyButton_clicked();

  void on_refreshButton_clicked();

private:
  void loadProfileFromDisk();
  void saveProfileToDisk();
  void fillPortsParameters();
  void fillPortsInfo();
  void updateProfile();

private:
  Ui::SerialDialog *ui;  
  SerialProfile currentProfile;
};

#endif // SERIALDIALOG_H
