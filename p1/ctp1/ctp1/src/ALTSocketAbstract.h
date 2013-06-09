//
//  ALTSocketAbstract.h
//  kqueueBasic
//
//  Created by Albert Tian on 13-4-2.
//  Copyright (c) 2013年 twk. All rights reserved.
//

#ifndef kqueueBasic_ALTSocketAbstract_h
#define kqueueBasic_ALTSocketAbstract_h

#include <string>

namespace ALTPackage {

    typedef int SomeKindOfLength;
    
    class ALTSocket;
    
#pragma pack(push)
#pragma pack(1)
    
    class RealEmptyClassA {
    public:
        virtual void func() {
            printf("calling noneVirtualFunc. ClassA \n");
        }
        char var_;
    };
    
    class DerivedClassB : public RealEmptyClassA {
    public:
        virtual void func() {
            printf("calling virtualFunc. ClassB \n");
        }
        virtual void bfunc() {
            printf("calling virtual bfunc. ClassB \n");
        }
    };
    class VirtualDerivedClassC : public RealEmptyClassA {
        
    };
    class VirtualDerivedClassD : public RealEmptyClassA {
        
    };
    
    class NoneVirtualClassX {
    public:
        int  igr_;
    };
    
    class VirtualDerivedClassE : public DerivedClassB, 
                                public NoneVirtualClassX 
    {
        public:

        void setLength(SomeKindOfLength aLen) {
            SomeKindOfLength fLen = aLen;
            fLen += 9.81;
            printf("fLen=%f\n", fLen);
        }
        
        typedef float SomeKindOfLength;

        void setLength(SomeKindOfLength aLen2) {
            SomeKindOfLength fLen2 = aLen2;
            fLen2 += 9.81;
            printf("fLen2=%f\n", fLen2);
        }
        
        virtual void mutilDerivedVFunc() {
            printf("mutilDerivedVFunc.\n");
        }
    };
    
#pragma pack(pop)
    
    class ALTSocketAbstract {
        
    public:
//        ALTSocketAbstract();
//        
//        virtual ~ALTSocketAbstract();
        
    public:
        
        virtual int createSocket() { return -1; }
        
        virtual int connectTarget(std::string &targetIP, int aPort)  {return -1; }
//        
//        virtual int bindIpPort(std::string &targetIP, int aPort);
        
//        virtual int listenWithMaxBacklog(int backlog);
        
//        virtual ALTSocket * acceptIncomingConnection();
        
//        virtual int sendMessage(std::string &aMsg);
//        
//        virtual int receive(std::string &aStream);
        
    };

}

#endif
