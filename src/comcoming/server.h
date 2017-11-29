#ifndef SERVER_H
#define SERVER_H

#include <string>
#include <vector>
#include <opencv2/opencv.hpp>
#include "com/Socket.h"

class Server {
public:
    Server(int _Port);
    void send(cv::Mat _img, int _percent);
private:
    int mPort;
    BOViL::comm::Socket *socket;
};

#endif // SERVER_H
