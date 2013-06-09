//
//  ALTServerSocket.h
//  kqueueBasic
//
//  Created by Albert Tian on 13-3-26.
//  Copyright (c) 2013年 twk. All rights reserved.
//

#ifndef kqueueBasic_ALTServerSocket_h
#define kqueueBasic_ALTServerSocket_h

#include "ALTSocket.h"

namespace ALTPackage {
    
    class ALTServerSocket : public ALTSocket {
        
    public:
        
        virtual int createSocket() ;
                
        int bindIpPort(std::string &targetIP, int aPort);
        
        int listenWithMaxBacklog(int backlog);
        
        ALTSocket * acceptIncomingConnection();
        
    };
    
    
    
}


#endif
