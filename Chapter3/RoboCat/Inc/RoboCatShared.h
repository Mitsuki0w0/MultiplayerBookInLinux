#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <netdb.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
//typedef void* receiveBufer_t;
using SOCKET = int;
constexpr int NO_ERROR = 0;
constexpr int INVALID_SOCKET = -1;
constexpr int WSAECONNRESET = ECONNRESET;
constexpr int WSAEWOULDBLOCK = EAGAIN;
constexpr int SOCKET_ERROR = -1;


#include <memory>

#include <vector>
#include <unordered_map>
#include <string>
#include <list>
#include <queue>
#include <deque>
#include <unordered_set>
#include <cassert>

class RoboCat;
class GameObject;

#include "StringUtils.h"
#include "SocketAddress.hpp"
#include "SocketAddressFactory.hpp"
#include "UDPSocket.hpp"
#include "TCPSocket.hpp"
#include "SocketUtil.hpp"
