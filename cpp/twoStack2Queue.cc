#include <iostream>
#include <vector>
#include <list>
#include <set>

using namespace std;

// 2 stack 1 queue 
// stack 先进后出
// queue 先进先出

// a  b  c   
// c  b  a

// 思路

class TwoStackToQueue{
public:
    TwoStackToQueue(){
        m_fstack.clear();
        m_sstack.clear();
        cout << "TwoStackToQueue()" <<endl;
    }
    ~TwoStackToQueue(){
        cout << "~TwoStackToQueue()" <<endl;
    }

public:
   void EnQueue(string newWaiter){



   }

   void outQueue(){

   }

private:
    std::vector<string> m_fstack;
    std::vector<string> m_sstack;
};



int main(){
    TwoStackToQueue * t = new TwoStackToQueue;
    t->EnQueue("darwin");
    
    delete t;
    return 0;
}