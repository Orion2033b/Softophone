#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QSettings>
#include <QTextEdit>
#include <QCloseEvent>
#include "call_window.h"
#include "database.h"
#include "contact_window.h"
#include "sip_adapter.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Main_window; }
QT_END_NAMESPACE

class Main_window : public QMainWindow
{
    Q_OBJECT

private:
    Ui::Main_window *ui;
    Sip_adapter *adapter = Sip_adapter::get_instance();   //creating singleton pointer
    Call_window *new_call;                              //pointer for incoming call window

    Contact_window contacts;

    QSettings *settings;

    void closeEvent(QCloseEvent *event);

public:
    Main_window(QWidget *parent = nullptr);
    ~Main_window();

public slots:
    void login_slot();          //registration slot, called by pushing button
    void logout_slot();         //unregistration slot, called by pushing button

    void renew_status_slot(int status); //renew status slot (слот обновления статуса)

    void outcall_click_slot();
    void make_outcall_slot(std::string uri);        //making an outgoing call slot

    void incoming_slot(int call_id, int status);        //incoming call handling  slot

    void contact_list_slot();               //opening contact list

signals:
    void outcall_signal(std::string uri);
    void im_logout_signal();
};
#endif // MAIN_WINDOW_H
