#ifndef CALENDAR_H
#define CALENDAR_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QCalendarWidget;
class QGridLayout;
class QGroupBox;

QT_END_NAMESPACE

class Calendar : public QWidget
{
    Q_OBJECT
public:
    explicit Calendar(QWidget *parent = 0);

private:
    void createPreviewGroupBox();

    QGroupBox *m_previewGroupBox;
    QGridLayout *m_previewLayout;
    QCalendarWidget *m_calendar;


};

#endif // CALENDAR_H
