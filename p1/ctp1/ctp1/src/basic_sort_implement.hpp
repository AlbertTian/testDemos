//
//  basic_sort_implement.hpp
//  kqueueBasic
//
//  Created by Albert Tian on 13-6-6.
//
//

#ifndef kqueueBasic_basic_sort_implement_hpp
#define kqueueBasic_basic_sort_implement_hpp

template <typename T1, int MAX_COUNT>
class basic_sort {
protected:
    T1  container_[MAX_COUNT];
public:
    basic_sort() {
        for (int i=0; i<MAX_COUNT; i++) {
            container_[i] = rand()%4048;
        }
    }
    virtual void sort() = 0;
    virtual void outputData() {
        for (int idx=0; idx < MAX_COUNT; ++idx) {
            T1 value = container_[idx];
            std::cout<< value << ", ";
        }
    }
};


template <typename T1, int MAX_COUNT>
class insert_sort : public basic_sort<T1, MAX_COUNT> {
public:
    virtual void sort();
private:
    
    /**
     *	@brief	when A < B return true then sort as (A,B)
     *
     *	@param 	array
     *	@param 	startIndex 	[startIndex, count-1]
     *	@param 	endIndex 	[0, endIndex]
     */
    void insert_sort_implement(T1 array[], int startIndex, int endIndex) {
        for (int i = startIndex + 1; i <= endIndex; ++i) {
            T1 temp = array[i];
            int j=i-1;
            for (; j >= startIndex; --j) {
                if (array[j] > temp) {
                    array[j+1] = array[j];
                } else {
                    break;
                }
            }
            array[j+1] = temp;

        }
    }
};

template <typename T1, int MAX_COUNT>
void
insert_sort<T1, MAX_COUNT>::sort() {
//    insert_sort_implement(basic_sort<T1, MAX_COUNT>::container_, 0, MAX_COUNT-1);
    insert_sort_implement(this->container_, 0, MAX_COUNT-1);

}

template <typename T1, int MAX_COUNT>
class shell_sort : public basic_sort<T1, MAX_COUNT> {

private:
    
    /**
     *	@brief	when A < B return true then sort as (A,B)
     *
     *	@param 	array
     *	@param 	startIndex 	[startIndex, count-1]
     *	@param 	endIndex 	[0, endIndex]
     */
    void shell_sort_implement(T1 array[], int startIndex, int endIndex) {
        for (int gap = (endIndex-startIndex)/2; gap > 0 ; gap/=2) {
            for(int i = gap; i<=endIndex; ++i) {
                T1 temp = array[i];
                int j = 0;
                for(j = i-gap; j>=0 && array[j]>temp; j-=gap) {
                    array[j+gap] = array[j];
                }
                array[j+gap] = temp;
            }
        }
    }
public:
    virtual void sort() {
        shell_sort_implement(this->container_, 0, MAX_COUNT-1);
    }

};


template <typename T1, int MAX_COUNT>
class bubble_sort : public basic_sort<T1, MAX_COUNT> {
    
private:
    
    /**
     *	@brief	when A < B return true then sort as (A,B)
     *
     *	@param 	array
     *	@param 	startIndex 	[startIndex, count-1]
     *	@param 	endIndex 	[0, endIndex]
     */
    void bubble_sort_implement(T1 array[], int startIndex, int endIndex) {
        for (int i=endIndex; i>=startIndex; --i) {
            for (int j=startIndex; j<i; ++j) {
                if (array[j] > array[j+1]) {
                    std::swap(array[j], array[j+1]);
                }
            }
        }
    }
    
public:
    virtual void sort() {
        bubble_sort_implement(this->container_, 0, MAX_COUNT-1);
    }
};

template <typename T1, int MAX_COUNT>
class quick_sort : public basic_sort<T1, MAX_COUNT> {

private:
    
    int partition(T1 array[], int first, int last) {
        int pivotIdx = (first+last)/2;
        int pivot = array[pivotIdx];
        std::swap(array[pivotIdx], array[last]);
        pivotIdx = first;
        for (int idx=first; idx<last; ++idx) {
            if (array[idx] < pivot) {
                std::swap(array[idx], array[pivotIdx]);
                ++pivotIdx;
            }
        }
        std::swap(array[pivotIdx], array[last]);
        return pivotIdx;
    }
    
    /**
     *	@brief	when A < B return true then sort as (A,B)
     *
     *	@param 	array
     *	@param 	startIndex 	[startIndex, count-1]
     *	@param 	endIndex 	[0, endIndex]
     */
    void quick_sort_implement(T1 array[], int startIndex, int endIndex) {
        if (startIndex >= endIndex) {
            return;
        }
        int partitionPos = partition(array, startIndex, endIndex);
        quick_sort_implement(array, startIndex, partitionPos-1);
        quick_sort_implement(array, partitionPos+1, endIndex);
    }
    
public:
    virtual void sort() {
        quick_sort_implement(this->container_, 0, MAX_COUNT-1);
    }
};

#endif
