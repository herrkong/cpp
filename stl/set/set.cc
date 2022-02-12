#include <map>
#include <iterator>
#include <iostream>
#include <set>

using namespace std;

void printset(set<int>& s){
    for (set<int>::iterator iter = s.begin(); iter != s.end(); iter++){
        std::cout << *iter << "," << &(*iter) << std::endl;
    }
}

int main(){
    set<int> s ;
    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(3);
    s.insert(4);

    //避免迭代器失效 erase 返回指向被删除元素的下一个元素的迭代器
    for (set<int>::iterator iter = s.begin(); iter != s.end();){
        if (*iter == 3) {
            iter = s.erase(iter);
        }else{
            iter ++;
        }
    }

    printset(s);

    return 0;
}

