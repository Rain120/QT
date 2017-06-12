#include "common.h"

Server* Common::_server = NULL;

Common::Common()
{
}

Server *Common::getServerInstance()
{
    if (_server == NULL)
    {
        _server = new Server;
    }
    return _server;
}

