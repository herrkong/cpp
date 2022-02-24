#include <stdio.h>
#include <iostream>	
#include <vector>	
#include <set>	
#include <map>	
#include <unordered_map>	
#include <list>
#include <iterator>

struct  Node
{
   int Value;
   Node* pNext;
};



void PrintVecWithAddress(std::vector<int>& v){
    for (std::vector<int>::iterator iter = v.begin(); iter != v.end(); iter++){
        std::cout << *iter << "," << &(*iter) <<std::endl;
    }
}

void PrintVec(std::vector<int>& v){
    for (std::vector<int>::iterator iter = v.begin(); iter != v.end(); iter++){
        std::cout << *iter << "," ;
    }
    printf("\n");
    
}
