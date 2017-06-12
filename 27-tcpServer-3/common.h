#ifndef COMMON_H
#define COMMON_H

#include "server.h"

class Common
{
public:
    Common();
    static Server* getServerInstance(void);

private:
    static Server* _server;
};

#endif // COMMON_H
