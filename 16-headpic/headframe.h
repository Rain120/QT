#ifndef HEADFRAME_H
#define HEADFRAME_H

#include <QFrame>
#include <QLabel>

namespace Ui {
class HeadFrame;
}

class HeadFrame : public QFrame
{
    Q_OBJECT

public:
    explicit HeadFrame(QWidget *parent = 0);
    HeadFrame(QString picName, QString nickString, QWidget *parent = 0);
    ~HeadFrame();

    QString picName() const;
    void setPicName(const QString &picName);

    QString nickString() const;
    void setNickString(const QString &nickString);

private slots:
    void on_pushButton_clicked();

private:
    Ui::HeadFrame *ui;

    QString _picName;
    QString _nickString;

};

#endif // HEADFRAME_H
