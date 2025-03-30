#include "../Inc/SocketAddressFactory.hpp"
#include <cstdlib>
#include <cstring>
#include <sys/socket.h>
#include <netdb.h>

SocketAddressPtr SocketAddressFactory::CreateIPv4FromString(const std::string& inString)
{
    auto pos = inString.find_last_of(':');
    std::string host,service;
    if (pos != std::string::npos) {
        host = inString.substr(0, pos);
        service = inString.substr(pos + 1);
    } else {
        host = inString;
        service = "0";
    }
    addrinfo hints;
    std::memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    addrinfo* result = nullptr;
    int error = getaddrinfo(host.c_str(), service.c_str(), &hints, &result);

    if (error != 0 && result != nullptr) {
        freeaddrinfo(result);
        return nullptr;
    }

    while (!result->ai_addr && result->ai_next) {
        result = result->ai_next;
    }

    if (!result->ai_addr) {
        freeaddrinfo(result);
        return nullptr;
    }

    auto toRet = std::make_shared<SocketAddress>(*result->ai_addr);

    freeaddrinfo(result);

    return toRet;
}