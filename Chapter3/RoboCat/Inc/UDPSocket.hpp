#include "SocketAddress.hpp"

class UDPSocket
{
public:
    using SOCKET = int;
	~UDPSocket();

	int Bind( const SocketAddress& inToAddress );
	int SendTo( const void* inToSend, int inLength, const SocketAddress& inToAddress );
	int ReceiveFrom( void* inToReceive, int inMaxLength, SocketAddress& outFromAddress );

	/*
	int SendTo( const MemoryOutputStream& inMOS, const SocketAddress& inToAddress );
	int ReceiveFrom( MemoryInputStream& inMIS, SocketAddress& outFromAddress );
	*/

	int SetNonBlockingMode( bool inShouldBeNonBlocking );

private:
	friend class SocketUtil;
	UDPSocket(SOCKET inSocket) : mSocket( inSocket ) {}
	SOCKET mSocket;

};

using UDPSocketPtr = std::shared_ptr<UDPSocket>;