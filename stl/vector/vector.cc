#include <map>
#include <iterator>
#include <iostream>
#include <vector>

using namespace std;

void printvec(vector<int>& v){
    for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++){
        std::cout << *iter << "," << &(*iter) <<std::endl;
    }
}

int main(){
    vector<int> v ;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    printvec(v);

    //避免迭代器失效 erase 返回指向被删除元素的下一个元素的迭代器
    for (vector<int>::iterator iter = v.begin(); iter != v.end();){
        if (*iter == 2) {
            iter = v.erase(iter);
        }else{
            iter++;
        }
    }

    //printvec(v);

    return 0;
}

