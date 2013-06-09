//
//  ALTClassConstructors.h
//  kqueueBasic
//
//  Created by Albert Tian on 13-4-18.
//  Copyright (c) 2013年 twk. All rights reserved.
//

#ifndef kqueueBasic_ALTClassConstructors_h
#define kqueueBasic_ALTClassConstructors_h

//#include <memory>

class ALTUseDefaultContructor {
    
    
public:
    int  ivar1;
    float  fvar2;
    bool  bvar3;
//    std::shared_ptr<int> p1;
    
    void logMembers() {
        std::cout << description() << std::endl;
    }
    std::string description() {
        char buffer[512] = {};
        snprintf(buffer,
                 sizeof(buffer),
                 "this=%p,members={ivar1=%d, fvar2=%f, bvar3=%d}",
                 this, ivar1, fvar2, bvar3);
        return std::string(buffer);
    }
};

class ALTUseUserDefineContructor {
    
    
public:
    int  ivar1;
    float  fvar2;
    bool  bvar3;
    
    ALTUseUserDefineContructor():ivar1(1),fvar2(2.1),bvar3(true) {
        printf("ALTUseUserDefineContructor() called\n");
    }
    
    ALTUseUserDefineContructor(ALTUseUserDefineContructor &rhs) {
        printf("ALTUseUserDefineContructor(ALTUseUserDefineContructor &) called\n");
        ivar1 = rhs.ivar1;
        fvar2 = rhs.fvar2;
        bvar3 = rhs.bvar3;
    }
    
    ALTUseUserDefineContructor(ALTUseDefaultContructor &rhs) {
        printf("ALTUseUserDefineContructor(ALTUseDefaultContructor &) called\n");
        ivar1 = rhs.ivar1;
        fvar2 = rhs.fvar2;
        bvar3 = rhs.bvar3;
    }
//    ALTUseUserDefineContructor & operator=(ALTUseDefaultContructor &rhs) {
//        printf("ALTUseUserDefineContructor:: ALTUseUserDefineContructor & operator=(ALTUseDefaultContructor rhs) called\n");
//        ivar1 = rhs.ivar1;
//        fvar2 = rhs.fvar2;
//        bvar3 = rhs.bvar3;
//        return *this;
//    }
    
    void logMembers() {
        std::cout << description() << std::endl;
    }
    std::string description() {
        char buffer[512] = {};
        snprintf(buffer,
                 sizeof(buffer),
                 "this=%p,members={ivar1=%d, fvar2=%f, bvar3=%d}",
                 this, ivar1, fvar2, bvar3);
        return std::string(buffer);
    }
};

#endif
