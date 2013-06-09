//
//  ALTClassHierahcyVir.h
//  kqueueBasic
//
//  Created by Albert Tian on 13-4-11.
//  Copyright (c) 2013年 twk. All rights reserved.
//

#ifndef kqueueBasic_ALTClassHierahcyVir_h
#define kqueueBasic_ALTClassHierahcyVir_h
#include "stdio.h"

#define LOG_FUNC(fmt, ...) printf("[%s] " fmt, __FUNCTION__, ##__VA_ARGS__)


class HyBaseConcrto {
    
    
public:
    void  conctroeFuncA() {
        LOG_FUNC(" from ALTBaseConcrto\n");
    }
    virtual ~HyBaseConcrto() {
        LOG_FUNC(" from HyBaseConcrto\n");
    }
};


class HyVirutalBase : public HyBaseConcrto{
    
    
public:
    virtual void conctroeFuncA() {
        LOG_FUNC(" from HyVirutalBase\n");
    }
    virtual ~HyVirutalBase() {
        LOG_FUNC(" from HyVirutalBase\n");
    }
    int base;
};

class HyConcretoDerivedX : public HyVirutalBase {
    
    
public:
    void conctroeFuncA() {
        LOG_FUNC(" from HyConcretoDerivedX\n");
    }
    ~HyConcretoDerivedX() {
        LOG_FUNC(" from HyConcretoDerivedX\n");
    }
    int base;
};

class HyVirutalDerivedY : public HyConcretoDerivedX {
    
    
public:
    void conctroeFuncA() {
        LOG_FUNC(" from HyVirutalDerivedY\n");
    }
    ~HyVirutalDerivedY() {
        LOG_FUNC(" from HyVirutalDerivedY\n");
    }
    int base;
};


#endif
