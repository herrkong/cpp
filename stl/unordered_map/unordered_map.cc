#include <map>
#include <iterator>
#include <iostream>
#include <unordered_map>

using namespace std;

void printmap(unordered_map<int,int>& m){
    for (unordered_map<int,int>::iterator iter = m.begin(); iter != m.end(); iter++){
        std::cout << iter->first << "," << iter->second << "," << &(*iter) << std::endl;
    }
}

int main(){
    unordered_map<int,int> m ;
    m[1] = 1;
    m[2] = 2;
    m[3] = 3;
    m[5] = 1;
    m[4] = 2;

    //避免迭代器失效 erase 返回指向被删除元素的下一个元素的迭代器
    for (unordered_map<int,int>::iterator iter = m.begin(); iter != m.end();){
        if (iter->second == 2) {
            iter = m.erase(iter);
        }else{
            iter ++;
        }
    }

    printmap(m);

    return 0;
}

