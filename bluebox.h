#ifndef BLUEBOX_H
#define BLUEBOX_H

//#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QPainter>
#include <QTimer>
#include "ui_bluebox.h"
#include "serialdialog.h"
#include "zlamp.h"
#include "bits.h"

namespace Ui {
class BlueBox;
}
class SerialDialog;

class BlueBox : public QMainWindow
{
  Q_OBJECT

public:
  explicit BlueBox(QWidget *parent = 0);
  ~BlueBox();

private slots:
  void openSerialPort();
  void closeSerialPort();
  void AdamCommand(const QByteArray &data);
  void readData();
  void signalAdamToReadInputs();
  void handleError(QSerialPort::SerialPortError error);

  //Menu bar actions
  void on_actionExit_triggered();
  void on_actionConnect_triggered();
  void on_actionDisconnect_triggered();
  void on_actionConfigure_triggered();

  void on_UVOnButton_clicked();
  void on_LEDOnButton_clicked();
  void on_UVOffButton_clicked();
  void on_LEDOffButton_clicked();


protected:
    void paintEvent(QPaintEvent *event);

private:
  Ui::BlueBox *ui;
  SerialDialog *serialDialog;
  QSerialPort *serial;
  QTimer *timer;

  bool door;
  bool lamp;
  bool uvOn;
};

#endif // BLUEBOX_H
