//
//  ALTMemberLayout.h
//  kqueueBasic
//
//  Created by Albert Tian on 13-4-2.
//  Copyright (c) 2013年 twk. All rights reserved.
//

#ifndef kqueueBasic_ALTMemberLayout_h
#define kqueueBasic_ALTMemberLayout_h

class ALTPoint3D {
    
public:
    float  x_;
    float  y_;
    float  z_;
//    int  alignment_;
public:
    long int  other_;
    static long  stMember_;
};

long ALTPoint3D::stMember_ = 1;

template <class class_Type, class class_data1, class class_data2>
char *
access_order_of_class_member(class_data1 class_Type::*mem1, class_data2 class_Type::*mem2) {
    char *des = NULL;
    
    long int *pCastMem1 = (long int *)&mem1;
    long int castMem1 = *pCastMem1;

    long int *pCastMem2 = (long int *)&mem2;
    long int castMem2 = *pCastMem2;
    
    printf("member1 aligment at %ld, member2 aligment at %ld \n", castMem1, castMem2);
    
    if (castMem1 == castMem2) {
        des = (char *) "same";
    } else if (castMem1 < castMem2) {
        des = (char *) "member 1 occur first";
    } else {
        des = (char *) "member 2 occur first";
    }
    return des;
}

#endif
