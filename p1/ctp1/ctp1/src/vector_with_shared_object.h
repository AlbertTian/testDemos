//
//  vector_with_shared_object.h
//  kqueueBasic
//
//  Created by Albert Tian on 13-5-28.
//  Copyright (c) 2013年 twk. All rights reserved.
//

#ifndef kqueueBasic_vector_with_shared_object_h
#define kqueueBasic_vector_with_shared_object_h

#include <memory>
#include <vector>
#include <utility>

namespace alt {
    

template <class ObjType>
class vector_with_shared_object {
    
    
public:
    typedef ObjType  element_type;
    typedef typename std::shared_ptr<element_type>  element_ptr_type;
    typedef typename std::vector<element_ptr_type>  container_type;
private:
    container_type  vectorWithSharedObj_;
    
public:
    const container_type & const_vector() const;
    
    container_type & vector();
    
    element_ptr_type make_shared_ptr_from_object(element_type *object) const
    {
//        std::make_shared<element_type>();
        element_ptr_type sptr(object,
                              [](element_type *releasingObjectPtr){
                                  std::cout<< "going to release heap object at " << releasingObjectPtr << std::endl;
                                  delete releasingObjectPtr;
                                  releasingObjectPtr = nullptr;
                              });
        return sptr;
    }
    
    element_ptr_type make_shared_ptr_from_array(element_type *array) const
    {
        element_ptr_type sptr(array,
                              [](element_type *releasingArrayPtr){
                                  std::cout<< "going to release heap array object at " << releasingArrayPtr << std::endl;
                                  delete [] releasingArrayPtr;
                                  releasingArrayPtr = nullptr;
                              });
        return sptr;
    }
    

};


template <class ObjType>
const typename vector_with_shared_object<ObjType>::container_type &
vector_with_shared_object<ObjType>::const_vector() const
{
    vectorWithSharedObj_.pop_back();
    return vectorWithSharedObj_;
}

template <class ObjType>
typename vector_with_shared_object<ObjType>::container_type &
vector_with_shared_object<ObjType>::vector()
{
    return vectorWithSharedObj_;
}
    
}
#endif
