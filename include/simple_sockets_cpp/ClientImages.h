#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <thread>
#include <vector>
#include <opencv2/opencv.hpp>
#include <simple_sockets_cpp/com/Socket.h>

class ClientImages {
public:
    ClientImages(int _port, std::string _ip);
    void retrieve(cv::Mat &_img);
private:
    std::vector<unsigned char> mCompressImage;
    std::thread *mComThread;
    int mPort;
    void comCallBack();
    BOViL::comm::Socket *socket;
};

#endif // CLIENT_H
