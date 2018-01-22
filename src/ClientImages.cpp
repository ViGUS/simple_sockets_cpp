#include <simple_sockets_cpp/ClientImages.h>
#include <simple_sockets_cpp/com/Socket.h>

ClientImages::ClientImages(int _port, std::string _ip)
{
    mPort=_port;
    std::cout << "Trying connection to server "<< _ip << " in port " <<_port  << std::endl;
    socket=BOViL::comm::Socket::createSocket(BOViL::comm::eSocketType::clientTCP,std::to_string(_port).c_str(),_ip.c_str());
    std::cout << "Client socket created" << std::endl;
    ///mComThread = new std::thread (&Server::comCallBack,this);
}

void ClientImages::retrieve(cv::Mat &_img)
{
    unsigned char buffer[1024];
    int sizePicture;
    mCompressImage.clear();
    std::string sinc = "takePicture";
    // std::cout << "Sending petition to take a picture" << std::endl;
    socket->sendMsg((unsigned char*)sinc.c_str(),sinc.size());

    socket->receiveMsg((unsigned char*)&sizePicture,sizeof(int));
    //std::cout << sizePicture << std::endl;

    std::string sinc2 = "sizePicture";
    // std::cout << "Size buffer received, sending confirmation" << std::endl;
    socket->sendMsg((unsigned char*)sinc2.c_str(),sinc2.size());
    int len=0;
    do{
        len = socket->receiveMsg(buffer,1024);
        for (int i=0;i<len;i++){
            mCompressImage.push_back(buffer[i]);
        }
        if(len==-1){
            break;
        }
    }while(mCompressImage.size()!=sizePicture);

    /* decodificar imagen*/
    // std::cout << mCompressImage.size() << std::endl;
    try {
        _img = cv::imdecode(mCompressImage,1);
    }
    catch (cv::Exception e){
        std::cout << "error descomprimiendo imagen" << std::endl;
    }
}
