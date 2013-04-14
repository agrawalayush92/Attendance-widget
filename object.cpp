#include "object.h"
#include <QtGui>
#include <QWidget>

Object::Object(QObject *parent) :
    QObject(parent)
{
    gui();
}

void Object::replyFinished(QNetworkReply* net)
{
    QList<QNetworkCookie> cookie = manager->cookieJar()->cookiesForUrl(url);
    QVariant var;
    var.setValue(cookie);
    url = QUrl("http://websismit.manipal.edu/websis/control/StudentAcademicProfile");
    request.setUrl(url);
    request.setHeader(QNetworkRequest::CookieHeader,var);
    net = manager->get(request);
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(replyFinished2(QNetworkReply*)));
    //disconnect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(replyFinished2(QNetworkReply*)));

}
void Object::replyFinished2(QNetworkReply* net)

{
    disconnect(manager,SIGNAL(finished(QNetworkReply*)),0,0);
    QByteArray arr= net->readAll();
    QString str(arr);
    for(int j=1;j<=6;j++)
    {
        v[j]= new QVBoxLayout;
        nameLab[j]=new QLabel;
    }
    nameLab[1]->setText("Name");
    v[1]->addWidget(nameLab[1]);
    nameLab[2]->setText("Classes");
    v[2]->addWidget(nameLab[2]);
    nameLab[3]->setText("Attended");
    v[3]->addWidget(nameLab[3]);
    nameLab[4]->setText("Absent");
    v[4]->addWidget(nameLab[4]);
    nameLab[5]->setText("%");
    v[5]->addWidget(nameLab[5]);
    nameLab[6]->setText("last updated");
    v[6]->addWidget(nameLab[6]);
    hbox=new QHBoxLayout;
    wid2=new QWidget;
    while(1)
    {
        ba.setNum(countAttend);
        str1="<span id=\"cc_ListAttendanceSummary_productName_"+ba+"\""+"   class=\"tabletext\"";
        str2="<span id=\"cc_ListAttendanceSummary_attendanceTaken_"+ba+"\""+"   class=\"tabletext\"";
        str3="<span id=\"cc_ListAttendanceSummary_classesAttended_"+ba+"\""+"   class=\"tabletext\"";
        str4="<span id=\"cc_ListAttendanceSummary_classesAbsent_"+ba+"\""+"   class=\"tabletext\"";
        str5="<span id=\"cc_ListAttendanceSummary_attendancePercentage_"+ba+"\""+"   class=\"tabletext\"";
        lastUpdate="<span id=\"cc_ListAttendanceSummary_lastUpdatedStamp_"+ba+"\""+"   class=\"tabletext\"";
        int len=str1.length();
        int i=str.indexOf(str1);
        if(i==-1)
            break;
        count=1;

        i=len+i+4;
        while(str[i]!='<')
        {
            if(str[i]=='&')
                break;
            str6=str6+str.at(i);
            i++;
        }
        //1992-04-10
        lab[labCount]=new QLabel;
        lab[labCount]->setText(str6);
        v[count]->addWidget(lab[labCount]); //entering the label in the layout
        count++;              //count=2
        labCount++;
        //total no. of classes
        str6="";
        len=str2.length();
        i=str.indexOf(str2);
        i=len+i+4;
        while(str[i]!='<')
        {
            if(str[i]=='&')
                break;
            str6=str6+str.at(i);
            i++;
        }
        //qDebug()<<str6;
        lab[labCount]=new QLabel;
        lab[labCount]->setText(str6);

        v[count]->addWidget(lab[labCount]);  //entering the label in the layout
        labCount++;
        count++;            //count=3
        //classes attended
        str6="";
        len=str3.length();
        i=str.indexOf(str3);
        i=len+i+4;
        while(str[i]!='<')
        {
            if(str[i]=='&')
                break;
            str6=str6+str.at(i);
            i++;
        }
        //qDebug()<<str6;
        lab[labCount]=new QLabel;
        lab[labCount]->setText(str6);

        v[count]->addWidget(lab[labCount]);  //entering the label in the layout
        labCount++;
        count++;              //count=4
        //classes absent
        str6="";
        len=str4.length();
        i=str.indexOf(str4);
        i=len+i+4;
        while(str[i]!='<')
        {
            if(str[i]=='&')
                break;
            str6=str6+str.at(i);
            i++;
        }
        //qDebug()<<str6;
        lab[labCount]=new QLabel;
        lab[labCount]->setText(str6);

        v[count]->addWidget(lab[labCount]);  //entering the label in the layout
        labCount++;
        count++;             //count=5
        //percentage
        str6="";
        len=str5.length();
        i=str.indexOf(str5);
        i=len+i+4;
        while(str[i]!='<')
        {
            if(str[i]=='&')
                break;
            str6=str6+str.at(i);
            i++;
        }
        //qDebug()<<str6;
        lab[labCount]=new QLabel;
        lab[labCount]->setText(str6);
        v[count]->addWidget(lab[labCount]);  //entering the label in the layout
        labCount++;
        count++;             //count=6
        //last updated
        str6="";
        len=lastUpdate.length();
        i=str.indexOf(lastUpdate);
        i=len+i+4;
        while(str[i]!='<')
        {
            if(str[i]=='&')
                break;
            str6=str6+str.at(i);
            i++;
        }
        //qDebug()<<str6;
        lab[labCount]=new QLabel;
        lab[labCount]->setText(str6);
        v[count]->addWidget(lab[labCount]);  //entering the label in the layout
        labCount++;
        str6="";
        countAttend++;

    }//while loop closes
    //entering the vertical layouts in vertical layout
    for(int j=1;j<=6;j++) //segmentation fault
        {
        hbox->addLayout(v[j]);
        }
    wid2->setLayout(hbox);
    wid2->show();
}

void Object::gui()
{
    wid = new QWidget;
    e1=new QLineEdit;
    e2=new QLineEdit;
    l1=new QLabel("username");
    l2=new QLabel("Date of Birth");
    lay1=new QHBoxLayout;
    lay2=new QHBoxLayout;
    lay3=new QHBoxLayout;
    vlay=new QVBoxLayout;
    but1=new QPushButton("OK");
    but2=new QPushButton("CANCEL");
    lay1->addWidget(l1);
    lay1->addWidget(l2);
    lay2->addWidget(e1);
    lay2->addWidget(e2);
    lay3->addWidget(but1);
    lay3->addWidget(but2);
    vlay->addLayout(lay1);
    vlay->addLayout(lay2);
    vlay->addLayout(lay3);
    wid->setLayout(vlay);
    wid->show();
    QObject::connect(but1,SIGNAL(clicked()),this,SLOT(clicked()));
    QObject::connect(but2,SIGNAL(clicked()),wid,SLOT(close()));
}

void Object::clicked()
{
    QByteArray postData;
    //QNetworkCookieJar jar;
    manager = new QNetworkAccessManager(this);

    url =  QUrl("http://websismit.manipal.edu/websis/control/createAnonSession");
    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    manager->setCookieJar(new QNetworkCookieJar(this));
    user=e1->text();
    dob=e2->text();
    postData.append("idValue="+user+"&birthDate_i18n="+dob+"&birthDate="+dob);
    QNetworkReply* reply=manager->post(request, postData);
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(replyFinished(QNetworkReply*)));
}

/*void Object::authenticationRequired(QNetworkReply *reply, QAuthenticator *authenticator)
{
    qDebug()<<"autherntication required";
}*/
