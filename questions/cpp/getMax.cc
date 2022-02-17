#include <stdio.h>	
#include <vector>	
#include <set>	
#include <map>	
#include <unordered_map>	
#include <list>

// map 迭代器失效的问题
// 这里函数内部的std::map变量是栈变量还是堆变量  返回的map迭代器有没有失效

// 求vec中出现次数最高的元素和次数
std::map<int,int>::iterator GetMax(const std::vector<int> & vec){
    std::map<int,int> m;
    for (auto & v : vec){
        m[v] += 1;
    }
    auto itn = m.begin();
    for (std::map<int,int>::iterator itr = m.begin(); itr != m.end();itr++) {
        if (itr != m.end() && itr->second > itn->second){
            itn = itr;
        }
    }

    return itn;
}

int main() {
    std::vector<int>  vec = {5,5,3,2,1,5};
    auto iter = GetMax(vec);
    printf("iter->first=%d,iter->second=%d\n",iter->first,iter->second);
    return 0;
}