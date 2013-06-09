//
//  ALTSocket.h
//  kqueueBasic
//
//  Created by Albert Tian on 13-3-26.
//  Copyright (c) 2013年 twk. All rights reserved.
//

#ifndef kqueueBasic_ALTSocket_h
#define kqueueBasic_ALTSocket_h


#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/event.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>

#include "ALTSocketAbstract.h"

#ifndef LogErrorMsg

#define LogErrorMsg(fmt,...)  fprintf(stderr, "error! in [%s:%d] [%s] [error code=%d,msg=%s] " fmt "\n", \
__FILE__ , __LINE__, __FUNCTION__, errno, strerror(errno), ##__VA_ARGS__)

#define LogDebugMsg(fmt,...)  fprintf(stdout, "[%s] " fmt "\n", __FUNCTION__, ##__VA_ARGS__)

#endif


namespace ALTPackage {
    
    class ALTSocket {
        
    private:
        int  fd_;
        
    public:
        ALTSocket();
        
        virtual ~ALTSocket();
        
    public:
        
        int getFileDescriptor();
        void setFileDescriptor(int aFd);
        
        virtual int createSocket() = 0;
        
        virtual int connectTarget(std::string &targetIP, int aPort);
        
        virtual int bindIpPort(std::string &targetIP, int aPort);
        
        virtual int listenWithMaxBacklog(int backlog);
        
        virtual ALTSocket * acceptIncomingConnection();
        
        virtual int sendMessage(std::string &aMsg);
        
        virtual int receive(std::string &aStream);
        
    };
    
    
    
}



#endif
