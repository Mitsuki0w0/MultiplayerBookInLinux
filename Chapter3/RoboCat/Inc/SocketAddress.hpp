#pragma once
#include <cstdint>
#include <cstring>
#include <memory>
#include <sys/socket.h>
#include <netinet/in.h>
class SocketAddress
{
public:
    SocketAddress(std::uint32_t inAddress, std::uint16_t inPort)
    {
        GetAsSockAddrIn()->sin_family = AF_INET;
        GetAsSockAddrIn()->sin_addr.s_addr = htonl(inAddress);
        GetAsSockAddrIn()->sin_port = htons(inPort);
    }
    SocketAddress(const sockaddr& inSockAddr)
    {
        std::memcpy(&mSockAddr, &inSockAddr, sizeof(mSockAddr));
    }

    std::uint32_t GetSize() const 
    {
        return sizeof(mSockAddr);
    }

private:
    friend class UDPSocket;
    friend class TCPSocket;

    sockaddr mSockAddr;
    sockaddr_in* GetAsSockAddrIn() { return reinterpret_cast<sockaddr_in*>(&mSockAddr); }

};
using SocketAddressPtr = std::shared_ptr<SocketAddress>;