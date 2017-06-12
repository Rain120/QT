#include "calendar.h"
#include <QCalendarWidget>
#include <QGridLayout>
#include <QGroupBox>

Calendar::Calendar(QWidget *parent) :
    QWidget(parent)
{
    createPreviewGroupBox();

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(m_previewGroupBox);
    layout->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(layout);
}


void Calendar::createPreviewGroupBox() {
    m_calendar = new QCalendarWidget;
    m_calendar->setGridVisible(true);  // 是否显示日历框中的线格

    m_previewGroupBox = new QGroupBox(tr("日历查阅"));
    m_previewLayout = new QGridLayout;
    m_previewLayout->addWidget(m_calendar, 0, 0, Qt::AlignCenter);
    m_previewGroupBox->setLayout(m_previewLayout);
}
