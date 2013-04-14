#ifndef OBJECT_H
#define OBJECT_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QHttp>
#include <QtNetwork/QNetworkCookieJar>
#include <QDebug>
#include <QNetworkReply>
#include <iostream>
#include <QChar>
#include <QtGui>
using namespace std;

class Object : public QObject
{
    Q_OBJECT
public:
    explicit Object(QObject *parent = 0);
    void gui();
    
signals:
    
public slots:
    void replyFinished(QNetworkReply*);
    void replyFinished2(QNetworkReply* net);
    void clicked();
    //void authenticationRequired(QNetworkReply* reply, QAuthenticator* authenticator);
public:
    QNetworkRequest req;
    QNetworkAccessManager *manager;
    QUrl url;
    QNetworkRequest request;
    QString str1,str2,str3,str4,str5,str6,user,dob,lastUpdate;
    char a;
    int count=1,labCount=1,countAttend=1;
    QByteArray ba;
    QWidget *wid;
    QWidget *wid2;
    QLineEdit *e1;
    QLineEdit *e2;
    QLabel *l1;
    QLabel *l2;
    QHBoxLayout *lay1;
    QHBoxLayout *lay2;
    QHBoxLayout *lay3;
    QVBoxLayout *vlay;
    QVBoxLayout *v[10];
    QLabel *lab[100];
    QHBoxLayout *hbox;
    QPushButton *but1;
    QPushButton *but2;
    QLabel* nameLab[5];


    
};

#endif // OBJECT_H
