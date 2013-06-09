//
//  ALTServerSocket.cpp
//  kqueueBasic
//
//  Created by Albert Tian on 13-3-26.
//  Copyright (c) 2013年 twk. All rights reserved.
//

#include "ALTServerSocket.h"
#include "ALTClientSocket.h"

int ALTPackage::ALTServerSocket::createSocket() {
    int aFd = socket(PF_INET, SOCK_STREAM, 0);
    if (aFd == -1) {
        LogErrorMsg("while socket create.");
    } else {
        setFileDescriptor(aFd);
    }
    return aFd;
}

int ALTPackage::ALTServerSocket::bindIpPort(std::string &targetIP, int aPort) {
    struct sockaddr_in addr = {}; 
    addr.sin_len = sizeof(addr);
	addr.sin_family = AF_INET; 
	addr.sin_port = htons(aPort);
    if (targetIP.length() > 0) {
        addr.sin_addr.s_addr = inet_addr(targetIP.c_str());
    } else {
        addr.sin_addr.s_addr = INADDR_ANY;
    }
    socklen_t len = sizeof(addr);
    int c = bind(getFileDescriptor(), (const struct sockaddr *)&addr, len);
    if (c == -1) {
        LogErrorMsg("while socket bind:%s,%d", targetIP.c_str(), aPort);
    }
    return c;
}

int 
ALTPackage::ALTServerSocket::listenWithMaxBacklog(int backlog) {
    int rv = listen(getFileDescriptor(), backlog);
    if (rv == -1) {
        LogErrorMsg("while socket listen.");
    }
    return rv;
}

ALTPackage::ALTSocket * 
ALTPackage::ALTServerSocket::acceptIncomingConnection() {
    ALTPackage::ALTSocket *incomingConnection = NULL;
    struct sockaddr_in remote_client = {};
    int addr_Len = sizeof(remote_client);
    int aNewConnectedFd = accept(getFileDescriptor(), (struct sockaddr *)&remote_client, (socklen_t *)&addr_Len);
    if (aNewConnectedFd == -1) {
        LogErrorMsg("while socket accept");
    } else {
        char *addressBuff = inet_ntoa(remote_client.sin_addr);
        std::string remoteIp = addressBuff;
        int remotePort = ntohs(remote_client.sin_port);
        LogDebugMsg("while socket accept incoming connection fd=%d, ip+port[%s:%d]", aNewConnectedFd, remoteIp.c_str(), remotePort);
        incomingConnection = new ALTPackage::ALTClientSocket();
        if (incomingConnection) {
            ALTPackage::ALTSocket &rClient = *incomingConnection;
            rClient.setFileDescriptor(aNewConnectedFd);
        }
    }
    return incomingConnection;
}




