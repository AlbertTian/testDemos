//
//  ALTClientSocket.cpp
//  kqueueBasic
//
//  Created by Albert Tian on 13-3-26.
//  Copyright (c) 2013年 twk. All rights reserved.
//

#include <iostream>
#include "ALTClientSocket.h"




int ALTPackage::ALTClientSocket::createSocket() {
    int aFd = socket(PF_INET, SOCK_STREAM, 0);
    if (aFd == -1) {
        perror("while socket create.");
    } else {
        setFileDescriptor(aFd);
    }
    return aFd;
}

int ALTPackage::ALTClientSocket::connectTarget(std::string &targetIP, int aPort) {
    struct sockaddr_in addr; 
	addr.sin_family = AF_INET; 
	addr.sin_port = htons(aPort);
	addr.sin_addr.s_addr = inet_addr(targetIP.c_str());
    socklen_t len = sizeof(addr);
    int c = connect(getFileDescriptor(), (const struct sockaddr *)&addr, len);
    if (c == -1) {
        LogErrorMsg("while socket connect:%s,%d", targetIP.c_str(), aPort);
    }
    return c;
}

int ALTPackage::ALTClientSocket::sendMessage(std::string &aMsg) {
    ssize_t wsize = write(getFileDescriptor(), aMsg.c_str(), aMsg.size());
    if (wsize == -1) {
        LogErrorMsg("while socket sendMessage:%s", aMsg.c_str());
    }
    return wsize;
}

int ALTPackage::ALTClientSocket::receive(std::string &aStream) {
    uint8_t buffer[4098] = {};
    ssize_t n = read(getFileDescriptor(), buffer, sizeof(buffer));
    if (n == -1) {
        LogErrorMsg("while socket recieve -1");
    } else if (n == 0) {
        LogDebugMsg("while socket remote close");
    } else if (n > 0) {
        aStream.append((char *)buffer, n);
    }
    return n;
}




