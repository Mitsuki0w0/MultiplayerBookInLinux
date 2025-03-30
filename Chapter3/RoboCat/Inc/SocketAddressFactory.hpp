
// #include "SocketAddress.hpp"
#include "SocketAddress.hpp"
class SocketAddressFactory
{
public:
    static SocketAddressPtr CreateIPv4FromString(const std::string& inString);
};