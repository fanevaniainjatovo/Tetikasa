#ifndef ADDWINDOW_H
#define ADDWINDOW_H

#include <QMainWindow>
#include <QCheckBox>
#include <QSpinBox>
#include <string>
#include <QComboBox>

using namespace std;
namespace Ui {
class AddWindow;
}

class AddWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddWindow(QWidget *parent = nullptr);
    ~AddWindow();

private slots:
    void on_checkBox_stateChanged(int arg1);
    void on_checkBox_2_stateChanged(int arg1);
    void on_checkBox_3_stateChanged(int arg1);
    void on_checkBox_4_stateChanged(int arg1);
    void on_checkBox_5_stateChanged(int arg1);
    void on_valider_nport(int nport);
    void on_effacer_nport();
    void on_pushButton_clicked();

    void on_widget_5_customContextMenuRequested(const QPoint &pos);

private:
    Ui::AddWindow *ui;
    QSpinBox* nport;
    QSpinBox** spinport;
    QComboBox* prot;
    QCheckBox* checkport;
    QComboBox* iface;
    QLineEdit* mac;
    QLineEdit* ip;
    QComboBox* destIP;
    QComboBox* destPort;

    QString cmd;
    QString striface;
    QString strprot;
    QString* strport;QString optport;
    QString strmac;
    QString strip;QString optip;

    int biface;
    int bprot;
    int bnport;int bport;
    int bmac;
    int bip;
};

#endif // ADDWINDOW_H
