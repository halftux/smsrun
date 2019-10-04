#include "smsrun.h"
//#include <QDebug>
#include <QTextStream>
#include <QStringList>
#include <QDBusMessage>
#include <QDBusConnection>
#include <QDBusInterface>
#include <QDBusArgument>
#include <QVariantMap>
#include <QProcess>
#include <QFile>

SmsRun::SmsRun(QObject *parent) : QObject(parent)
{
    QDBusConnection::systemBus().connect("org.ofono", "/ril_0", "org.ofono.MessageManager", "IncomingMessage", this, SLOT(infoIncoming(QString,QVariantMap)));
    //qDebug () << "smsreceive waiting for actions:";
}


void SmsRun::infoIncoming(QString message, QVariantMap info)
{
    QString number;
    QString key="Sender";
    //qDebug () << "message: " << message;
    //qDebug () << "infomap: " << info;
    QMap<QString, QVariant>::iterator i = info.find(key);
    while ( i != info.end() && i.key() == key)
    {
        QVariant vvalue=i.value();
        number=vvalue.toString();
        ++i;
    }
    if (readWhitlist(number))
    {
        QString cmd=checkMessage(message);
        if (cmd!="")
        {
            QString prog = "sh";//shell
            QStringList arguments;
            arguments << "-c" << cmd;
            QProcess* process = new QProcess(this);
            process->start(prog, arguments);
            //process->waitForFinished();
        }
    }
}

bool SmsRun::readWhitlist(QString pnumber)
{
    QFile file("/home/nemo/.config/smsrun/whitelist.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        //qDebug() << "error" << file.errorString();
        return "";
    }
    QStringList whitenumbers;
    QTextStream in(&file);

    while(!in.atEnd())
    {
        QString line = in.readLine();
        whitenumbers.append(line);
    }
    file.close();
    if (whitenumbers.contains(pnumber)) return true;
    else return false;
}

QString SmsRun::checkMessage(QString message)
{
    QFile file("/home/nemo/.config/smsrun/cmdlist.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        //qDebug() << "error" << file.errorString();
        return "";
    }
    QStringList cmdlist;
    QStringList codelist;
    QStringList splitter;
    QString cmd="";
    QTextStream in(&file);

    while(!in.atEnd())
    {
        QString line = in.readLine();
        splitter = line.split("\t");
        if (splitter.count()==2)
        {
            codelist.append(splitter.at(0));
            cmdlist.append(splitter.at(1));
        }
    }
    file.close();
    int checkcode=codelist.indexOf(message);
    if (checkcode!=-1)
    {
        cmd=cmdlist.at(checkcode);
    }
    return cmd;
}
