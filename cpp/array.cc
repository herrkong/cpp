#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <unordered_map>
#include <iterator>
#include <thread>
#include <unistd.h>
#include <algorithm>

using namespace std;

class Array {
public:
    Array(int size) : size_(size) {
        data_ = new int[size_];
    }
     
    // 深拷贝构造
    Array(const Array& temp_array) {
        size_ = temp_array.size_;
        data_ = new int[size_];
        for (int i = 0; i < size_; i ++) {
            data_[i] = temp_array.data_[i];
        }
    }
     
    // 深拷贝赋值
    Array& operator=(const Array& temp_array) {
        delete[] data_;
 
        size_ = temp_array.size_;
        data_ = new int[size_];
        for (int i = 0; i < size_; i ++) {
            data_[i] = temp_array.data_[i];
        }
    }
 
    ~Array() {
        delete[] data_;
    }
 
public:
    int *data_;
    int size_;
};