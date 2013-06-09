//
//  ALTReferencePointer.h
//  kqueueBasic
//
//  Created by Albert Tian on 13-4-24.
//  Copyright (c) 2013年 twk. All rights reserved.
//

#ifndef kqueueBasic_ALTReferencePointer_h
#define kqueueBasic_ALTReferencePointer_h

#include <memory>

class ALTReferencePointerUsSharedPtr {
    
    
public:
    std::shared_ptr<int>  strong_p_;
    std::weak_ptr<int>  weak_p_;
    
    void createInteger() {
        int *aVar = new int;
        strong_p_ = std::shared_ptr<int>(aVar);
        weak_p_ = std::weak_ptr<int>(strong_p_);
        
        strong_p_.get();
        strong_p_.reset();
        
    }
};

#endif
