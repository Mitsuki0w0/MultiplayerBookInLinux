#include "../Inc/RoboCatShared.h"
// #include "../Inc/SocketAddress.hpp"
#include <sys/socket.h>

int UDPSocket::Bind( const SocketAddress& inBindAddress )
{
    int error = bind(mSocket, &inBindAddress.mSockAddr, inBindAddress.GetSize());
    if ( error != 0 )
    {
        SocketUtil::ReportError( L"UDPSocket::Bind" );
        return SocketUtil::GetLastError();
    }
    return NO_ERROR;
}
