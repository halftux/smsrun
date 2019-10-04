#ifndef SMSRUN_H
#define SMSRUN_H

#include <QObject>
#include <QDBusVariant>

class ConsoleReader;
class SmsRun : public QObject
{
    Q_OBJECT
public:
    explicit SmsRun(QObject *parent = nullptr);

signals:
    void finished();

private:
    bool readWhitlist(QString pnumber);
    QString checkMessage(QString message);

private slots:
    void infoIncoming(QString message, QVariantMap info);

public slots:
};

#endif // SMSRUN_H
