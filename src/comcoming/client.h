#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <thread>
#include <vector>
#include <opencv2/opencv.hpp>
#include "com/Socket.h"

class Client
{
public:
    Client(int _port, std::string _ip);
    void retrieve(cv::Mat &_img);
private:
    std::vector<unsigned char> mCompressImage;
    std::thread *mComThread;
    int mPort;
    void comCallBack();
    BOViL::comm::Socket *socket;
};

#endif // CLIENT_H
