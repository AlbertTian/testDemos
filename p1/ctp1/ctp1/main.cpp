//
//  main.cpp
//  ctp1
//
//  Created by Albert Tian on 13-6-9.
//  Copyright (c) 2013年 twk. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include "ALTClientSocket.h"
#include "ALTServerSocket.h"
#include "ALTMemberLayout.h"
#include "ALTClassHierahcyVir.h"
#include "ALTClassConstructors.h"
#include "ALTReferencePointer.h"
#include "function_operater_class_cluster.h"
#include "vector_implement_stack.h"
#include "vector_with_shared_object.h"
#include "basic_sort_implement.hpp"

void clientSendMessage(std::string aMsg);
void serverStart();
void testClassMemberLayout();
void testClassVirtualFuction();
void testClassHy();
void testClassContructor();
void testClassFunctor();
void testArchectureTypeSize();
void testSelfImplementStack();
void testVectorWithSharedPtr();
void testBasicSortImplement();

int main(int argc, const char * argv[])
{
    
    // insert code here...
    std::cout << "Hello, World!\n";
    
    std::string msg = "";
    bool isServerFlag = false;
    if (argc > 1) {
        printf("argv 1=%s\n", argv[1]);
        std::string serverFlag = argv[1];
        if (serverFlag == "--serverOn") {
            isServerFlag = true;
        } else {
            msg.append(argv[1]);
        }
    }
    
    testBasicSortImplement();
    
    testVectorWithSharedPtr();
    
    testSelfImplementStack();
    
    testArchectureTypeSize();
    
    testClassFunctor();
    
    testClassContructor();
    
    testClassVirtualFuction();
    
    testClassMemberLayout();
    
    testClassHy();
    
    
    if (isServerFlag) {
        serverStart();
    } else {
        clientSendMessage(msg);
    }
    
    
    return 0;
}

void testBasicSortImplement() {
#define T1_MAX_COUNT  20
    basic_sort<int, T1_MAX_COUNT> *aSorter = new shell_sort<int, T1_MAX_COUNT>();
    
    printf("begin sorting array:  size=%d \n", T1_MAX_COUNT);
    clock_t startTime = clock();
    aSorter->outputData();
    aSorter->sort();
    clock_t endTime = clock();
    printf("finish sorting array: size=%d \n", T1_MAX_COUNT);
    aSorter->outputData();
    std::cout << "time begin at " << startTime << ", end at " <<
    endTime << ", cost:" << endTime-startTime << std::endl;
    std::cout << "real time cost:" << ((double)(endTime-startTime))/CLOCKS_PER_SEC << std::endl;
    
}

void testVectorWithSharedPtr() {
    using namespace alt;
    using namespace std;
    vector_with_shared_object<int> lines;
    auto &realVector = lines.vector();
    {
        auto l1 = lines.make_shared_ptr_from_object(new int(88));
        auto l2 = lines.make_shared_ptr_from_array(new int[10]{11});
        
        realVector.push_back(l1);
        realVector.push_back(l2);
    }
    auto aSize = realVector.size();
    printf("v size=%lu, count=%lx\n", realVector.size(), aSize);
    lines.vector().pop_back();
    lines.vector().pop_back();
    
    vector_with_shared_object<string > sentences;
    weak_ptr<string> weakS1;
    auto spool = sentences.vector();
    {
        auto s1 = sentences.make_shared_ptr_from_object(new string("Having no breakfast"));
        auto s2 = sentences.make_shared_ptr_from_object(new string("I'm so hungry now."));
        auto s3 = std::make_shared<string>("But I still have to start working at half past 7.");
        spool.push_back(s1);
        spool.push_back(s2);
        spool.push_back(s3);
        weakS1 = s1;
    }
    
    for (auto it = spool.begin(); it != spool.end(); ++it) {
        auto &smartPtr = *it;
        string *sentencePtr = smartPtr.get();
        string &sentence = *sentencePtr;
        cout<< "smart ptr:" << smartPtr
        << ", object ptr:" << sentencePtr
        << ", object:" << sentence <<endl;
    }
    while (!spool.empty()) {
        spool.pop_back();
    }
    if (weakS1.expired()) {
        
        cout<< "weakS1 expired " << &weakS1 <<
        " releasd object use_count " << weakS1.use_count() << endl;
        auto strongS1Temp = weakS1.lock();
        if (strongS1Temp) {
            cout<< "storngS1Temp " << *strongS1Temp << endl;
        } else {
            cout<< "storngS1Temp is not deleted" << endl;
        }
    }
    cout<< "finished " << __FUNCTION__ << endl;
    
    
}

void testSelfImplementStack() {
    using namespace alt;
    Stack<int>  aFILO;
    aFILO.push(99);
    aFILO.push(22);
    aFILO.push(1024);
    
    int *topValue = aFILO.getTop();
    if (topValue) {
        printf("%d\n", *topValue);
    }
    for (; !aFILO.isEmpty(); aFILO.pop()) {
        int constTopv = 0;
        if (aFILO.getTop(constTopv)) {
            printf("get value %d\n", constTopv);
        } else {
            printf("stack has no value\n");
        }
    }
}
void testArchectureTypeSize() {
    int  intv = 4;
    long  longv = 4;
    long long longlongv = 4;
    long long lllv =4;
    double doublev = 4;
    float floatv = 4;
    printf("%ld, %ld, %ld, %ld, %ld, %ld,\n",
           sizeof(intv),
           sizeof(longv),
           sizeof(longlongv),
           sizeof(lllv),
           sizeof(doublev),
           sizeof(floatv)
           );
}

void testClassFunctor() {
    CalculatorFunctionor f1;
    bool bv1 = f1(1,2);
    double fv1 = f1(3.2, 4.3);
    
    
    CalculatorFunctionor *pc = new CalculatorFunctionor;
    double fv2 = pc->operator()(99., 11.);
    
    MutilCalculator mutil1;
    FactorialCalculator factor1;
    CalculatorFunctionor def1;
    
    CalculatorFunctionor *fp = &mutil1;
    int result1 = (*fp)(40, 50);
    
    fp = &factor1;
    int result2 = (*fp)(40, 50);
    
    fp = &def1;
    int result3 = (*fp)(40, 50);
    
}

void
testClassContructor() {
    
    // simple alloc on stack
    ALTUseDefaultContructor d1;
    d1.logMembers();
    d1.ivar1 = 991;
    d1.fvar2 = 2.7;
    d1.bvar3 = true;
    d1.logMembers();
    
    // alloc on stack by assign
    ALTUseDefaultContructor d2 = d1;
    d2.logMembers();
    
    // alloc on stack by calling constructor
    ALTUseDefaultContructor d3 = ALTUseDefaultContructor();
    d3.logMembers();
    
    // alloc on stack by calling constructor with rhs
    ALTUseDefaultContructor d4 = ALTUseDefaultContructor(d1);
    d4.logMembers();
    
    // new simplely
    // result: llvm member not init
    ALTUseDefaultContructor *dp5 = new ALTUseDefaultContructor;
    dp5->logMembers();
    
    // new by calling constructor
    // result: llvm init all member default zero!
    ALTUseDefaultContructor *dp6 = new ALTUseDefaultContructor();
    dp6->logMembers();
    
    // new by calling constructor with rhs
    ALTUseDefaultContructor *dp7 = new ALTUseDefaultContructor(d1);
    dp7->logMembers();
    
    
    
    
    
    ALTUseUserDefineContructor u1;
    u1.logMembers();
    u1 = d1;
    u1.logMembers();
    
    ALTUseUserDefineContructor u2(d1); // = * new ALTUseUserDefineContructor( d1);
    u2.logMembers();
    
}

void
testClassHy() {
    HyBaseConcrto *ba = new HyBaseConcrto;
    ba->conctroeFuncA();
    
    HyVirutalBase *va = new HyVirutalBase();
    va->conctroeFuncA();
    
    //    HyBaseConcrto *vba = va;
    //    vba->conctroeFuncA();
    
    /*********
     *********/
    HyVirutalDerivedY vdyObj;
    HyVirutalDerivedY *vdy = new HyVirutalDerivedY();
    //    memset((void*)vdy, 0, sizeof(HyVirutalDerivedY));
    vdy->conctroeFuncA();
    
    HyConcretoDerivedX *cdx = vdy;
    cdx->conctroeFuncA();
    
    HyVirutalBase *vb1 = cdx;
    vb1->conctroeFuncA();
    
    HyVirutalBase *vb2 = vdy;
    vb2->conctroeFuncA();
    
    HyBaseConcrto *cb1 = vb2;
    cb1->conctroeFuncA();
    
    delete cb1;
}

void
testClassVirtualFuction() {
    ALTPackage::ALTSocketAbstract absSock;
    int sizeOfAbsSock = sizeof(absSock);
    ALTPackage::RealEmptyClassA realEmptyA;
    int sizeOfRealEmptyA = sizeof(realEmptyA);
    ALTPackage::DerivedClassB db;
    int dbSize = sizeof(db);
    ALTPackage::VirtualDerivedClassC vdc;
    int vdcSize = sizeof(vdc);
    ALTPackage::VirtualDerivedClassD vdd;
    int vddSize = sizeof(vdd);
    ALTPackage::VirtualDerivedClassE vde;
    int vdeSize = sizeof(vde);
    short afLength = 9.812;
    vde.setLength(afLength);
    
    printf("absSize=%d, sizeOfRealEmptyA=%d, dbSize=%d, vdcSize=%d, vddSize=%d, vdeSize=%d \n",
           sizeOfAbsSock, sizeOfRealEmptyA, dbSize, vdcSize, vddSize, vdeSize);
    
    const char *dbTypeName = typeid(db).name();
    const std::type_info &aTypeInfo = typeid(db);
    printf("dbTypeName=%s\n", dbTypeName);
    
    typeof(db) anotherDB;
    anotherDB.func();
    
    realEmptyA.func();
    ALTPackage::RealEmptyClassA *ptr2A = &realEmptyA;
    ptr2A->func();
    
    db.func();
    ALTPackage::DerivedClassB *ptr2B = &db;
    ptr2B->func();
    
    ALTPackage::RealEmptyClassA *ptr2A_2 = &db;
    ptr2A_2->func();    // note: will calling RealEmptyClassA::func() !
    
    ALTPackage::DerivedClassB *ptr2B_2 = (ALTPackage::DerivedClassB *)&realEmptyA;
    //ptr2B_2->func();    // note: bad accss to vptr table, cause a crach.
    
}

void testClassMemberLayout() {
    int *lStackPtr = NULL;
    printf("now stack ptr addr=0x%lx \n", (long int)&lStackPtr);
    
    char *pStr = access_order_of_class_member(&ALTPoint3D::x_, &ALTPoint3D::y_);
    printf("member layout:%s\n", pStr);
    
    pStr = access_order_of_class_member(&ALTPoint3D::y_, &ALTPoint3D::y_);
    printf("member layout:%s\n", pStr);
    
    pStr = access_order_of_class_member(&ALTPoint3D::z_, &ALTPoint3D::y_);
    printf("member layout:%s\n", pStr);
    
    pStr = access_order_of_class_member(&ALTPoint3D::other_, &ALTPoint3D::y_);
    printf("member layout:%s\n", pStr);
    
    ALTPoint3D point;
    point.stMember_ = 9;
    
}

void serverStart() {
    ALTPackage::ALTSocket *pServer = new ALTPackage::ALTServerSocket();
    if (pServer) {
        ALTPackage::ALTSocket &rServer = *pServer;
        std::string ip = "127.0.0.1";
        int port = 19981;
        rServer.createSocket();
        
        rServer.bindIpPort(ip, port);
        
        rServer.listenWithMaxBacklog(256);
        
        while (1) {
            ALTPackage::ALTSocket *pIncoming = rServer.acceptIncomingConnection();
            if (pIncoming) {
                ALTPackage::ALTSocket &rIncoming = *pIncoming;
                std::string message;
                rIncoming.receive(message);
                
                std::cout << "received a message" << message << std::endl;
                message.append(". reply by server");
                
                rIncoming.sendMessage(message);
                
                delete pIncoming;
                pIncoming = NULL;
            }
            
            sleep(1);
        }
        
    }
    delete pServer;
}

void clientSendMessage(std::string aMsg) {
    ALTPackage::ALTSocket *pClient = new ALTPackage::ALTClientSocket();
    if (pClient) {
        ALTPackage::ALTSocket &rClient = *pClient;
        std::string ip = "127.0.0.1";
        int port = 19981;
        rClient.createSocket();
        
        rClient.connectTarget(ip, port);
        
        if (aMsg.length() > 1)  {
            rClient.sendMessage(aMsg);
        }
        
        std::string incoming;
        rClient.receive(incoming);
        std::cout << "receive:" << incoming << std::endl;
    }
    delete pClient;
}


