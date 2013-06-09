//
//  ALTClientSocket.h
//  kqueueBasic
//
//  Created by Albert Tian on 13-3-26.
//  Copyright (c) 2013年 twk. All rights reserved.
//

#ifndef kqueueBasic_ALTClientSocket_h
#define kqueueBasic_ALTClientSocket_h

#include "ALTSocket.h"

namespace ALTPackage {
    
    class ALTClientSocket : public ALTSocket {        
    public:
        
        virtual int createSocket();
        
        virtual int connectTarget(std::string &targetIP, int aPort);
        
        virtual int sendMessage(std::string &aMsg);
        
        virtual int receive(std::string &aStream);
        
    };
    
    
    
}

#endif
