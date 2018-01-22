/////////////////////////////////////////////////////////////////////////////////////////
//	BOVIL: core
//
//			Author:		Pablo Ramon Soria
//			Date:		2014-05-31
//
/////////////////////////////////////////////////////////////////////////////////////////

#include <simple_sockets_cpp/com/SocketTCP.h>
#include <simple_sockets_cpp/com/Socket.h>

namespace BOViL{
	namespace comm{
		//-----------------------------------------------------------------------------
		int SocketTCP::sendMsg(const unsigned char *_buffer, const unsigned _bufferSize) {
            int len = -1;
            try{
                len = send(mSocket, (char *)_buffer, _bufferSize, 0|MSG_NOSIGNAL);
            }catch(int e){
                closeSocket();
                return -1;
            }

            if (len == SOCKET_ERROR) {
				std::cout << "Socket Error" << std::endl;
				closeSocket();
				#if defined (_WIN32)
					std::cout << "Send failed with error: " << WSAGetLastError() << std::endl;
					WSACleanup();
				#endif
				return -1;
			}
            return len;
		}

		//-----------------------------------------------------------------------------
		int SocketTCP::receiveMsg(unsigned char *_buffer, const unsigned _bufferSize) {
			return recv(mSocket, (char *)_buffer, _bufferSize, 0);
		}
	}
}




