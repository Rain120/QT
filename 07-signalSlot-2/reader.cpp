#include "reader.h"

Reader::Reader(QString name, QObject *parent) :
    QObject(parent), _name(name)
{
}
