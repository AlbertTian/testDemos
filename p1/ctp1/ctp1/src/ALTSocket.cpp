//
//  ALTSocket.cpp
//  kqueueBasic
//
//  Created by Albert Tian on 13-3-26.
//  Copyright (c) 2013年 twk. All rights reserved.
//


#include "ALTSocket.h"

ALTPackage::ALTSocket::ALTSocket() {
    fd_ = -1;
}

ALTPackage::ALTSocket::~ALTSocket() {
    if (fd_ > 0) {
        close(fd_);
    }
}

int ALTPackage::ALTSocket::getFileDescriptor() {
    return this->fd_;
}

void ALTPackage::ALTSocket::setFileDescriptor(int aFd) {
    this->fd_ = aFd;
}

//int ALTPackage::ALTSocket::createSocket() {
//    return -1;
//}

int ALTPackage::ALTSocket::connectTarget(std::string &targetIP, int aPort) {
    return -1;
}

int ALTPackage::ALTSocket::bindIpPort(std::string &targetIP, int aPort) {
    return -1;
}

int ALTPackage::ALTSocket::listenWithMaxBacklog(int backlog) {
    return -1;
}

ALTPackage::ALTSocket * ALTPackage::ALTSocket::acceptIncomingConnection() {
    return NULL;
}

int ALTPackage::ALTSocket::sendMessage(std::string &aMsg) {
    return -1;
}

int ALTPackage::ALTSocket::receive(std::string &aStream) {
    return -1;
}


