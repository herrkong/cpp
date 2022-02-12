#include <iostream>
#include <vector>
#include <list>
#include <set>

using namespace std;

// c++ queue
// enQueue
// outQueue
// lenQueue

class AQueue{
public:
    AQueue(){
        m_queue.clear();
        cout << "AQueue()" <<endl;
    }
    ~AQueue(){
        cout << "~AQueue()" <<endl;
    }

public:
    void enQueue(string newWaiter){
        m_queue.push_back(newWaiter);
        cout << m_queue.back() << " enter queue" << endl;
    }

    void outQueue(){
        if (m_queue.size() == 0){
            cout << "queue empty" <<endl;
        }
        cout << m_queue.front() << " out queue" << endl;
        m_queue.pop_front();
    }

    int lenQueue(){
        return m_queue.size();
    }

    string FrontQueue(){
        return m_queue.front();
    }

    string EndQueue(){
        return m_queue.back();
    }

private:
    std::list<string> m_queue;
};



int main(){
    AQueue * q = new AQueue;
    q->enQueue("darwin");
    q->enQueue("serein");
    q->outQueue();
    q->enQueue("deyu");
    q->enQueue("jiangwen");
    delete q;
    return 0;
}