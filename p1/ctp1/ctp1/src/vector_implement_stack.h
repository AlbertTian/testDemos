//
//  vector_implement_stack.h
//  kqueueBasic
//
//  Created by Albert Tian on 13-5-10.
//  Copyright (c) 2013年 twk. All rights reserved.
//

#ifndef kqueueBasic_vector_implement_stack_h
#define kqueueBasic_vector_implement_stack_h

#include <vector>
namespace alt {
    
    
    template<class T>
    class Stack {
    private:
        std::vector<T>  stack_;
    public:
        typedef typename std::vector<T>::size_type size_type;
    public:
        
        bool pop();
        
        void push(const T &value) {
            stack_.push_back(value);
        }
        
        void push(T &value) {
            stack_.push_back(value);
        }
        
        bool isEmpty() {
            return stack_.empty();
        }
        
        size_type size()
        {
            return stack_.size();
        }
        
        /**
         *	@brief	get stack top value
         *
         *	@return	top value ptr, otherwise NULL when stack is empty
         */
        int * getTop() {
            if (!stack_.empty()) {
                return &(stack_[stack_.size()-1]);
            }
            return nullptr;
        }
        bool getTop(T &topValue);
        bool getTop(const T &topValue);

    };
    
    
    template<class T>
    bool
    Stack<T>::pop() {
        if (!stack_.empty()) {
            stack_.pop_back();
            return true;
        }
        return false;
    }
    template <class T>
    bool
    Stack<T>::getTop(T &topValue)
    {
        if (!stack_.empty()) {
            topValue = stack_.at(stack_.size() - 1);
            return true;
        }
        return false;
    }
    
    template <class T>
    bool
    Stack<T>::getTop(const T &topValue)
    {
        if (!stack_.empty()) {
            topValue = stack_.at(stack_.size() - 1);
            return true;
        }
        return false;
    }
    

//
//    void Stack::push(int &value)
//    {
//        stack_.push_back(value);
//    }
    
};

//using namespace alt;




#endif
