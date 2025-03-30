#include <memory>
class TCPSocket;
using TCPSocketPtr = std::shared_ptr<TCPSocket>;


class TCPSocket
{
public:
    int connet(const int);

};