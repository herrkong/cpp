
#include <iostream>
using std::cout;
using std::endl;

template <typename Type, int qcapacity = 10>
class Queue
{
public:
    Queue()
        : _pQueue(new Type[qcapacity]()), _head(0), _tail(0)
    {
        cout << "Queue()" << endl;
    }

    ~Queue()
    {
        if (_pQueue)
            delete[] _pQueue;
        cout << "~Queue()" << endl;
    }

    void enQueue(const Type &element);
    void deQueue();
    Type front() const;
    Type back() const;
    bool empty() const;
    bool full() const;
    void print() const;

private:
    Type *_pQueue;
    Type _head;
    Type _tail;
};

template <typename Type, int qcapacity>
void Queue<Type, qcapacity>::enQueue(const Type &t)
{
    if (!full())
    {
        //队尾入队加1 % capacity
        _pQueue[_tail] = t;
        ++_tail;
        _tail %= qcapacity;
    }
    else
    {
        cout << "Queue is full" << endl;
    }
}

template <typename Type, int qcapacity>
void Queue<Type, qcapacity>::deQueue()
{
    if (!empty())
    {
        ++_head;
        _head %= qcapacity;
    }
    else
    {
        cout << "Queue is empty." << endl;
    }
}

template <typename Type, int qcapacity>
Type Queue<Type, qcapacity>::front() const
{
    return _pQueue[_head];
}

template <typename Type, int qcapacity>
Type Queue<Type, qcapacity>::back() const
{
    return _pQueue[_tail];
}

template <typename Type, int qcapacity>
bool Queue<Type, qcapacity>::empty() const
{
    return _head == _tail;
}

template <typename Type, int qcapacity>
bool Queue<Type, qcapacity>::full() const
{
    return _head == (_tail + 1) % qcapacity;
}

template <typename Type, int qcapacity>
void Queue<Type, qcapacity>::print() const
{
    for (int idx = _head; idx < _tail; idx++)
    {
        cout << _pQueue[idx] << "," << endl;
    }
    cout << endl;
}

void test0()
{

    Queue<int> que;
    cout << "1,4,7,10,11依次进队" << endl;
    que.enQueue(1);
    que.enQueue(4);
    que.enQueue(7);
    que.enQueue(10);
    que.enQueue(11);
    que.print();
    cout << "队伍是否满了?";
    cout << que.full() << endl;
    cout << "排在队伍最前面的1出队" << endl;
    que.deQueue();
    cout << "队伍是否空了?";
    cout << que.empty() << endl;
    que.print();
}

void test1()
{
    Queue<char> que;
    cout << "H,K,D依次进队" << endl;
    que.enQueue('H');
    que.enQueue('K');
    que.enQueue('D');
    que.print();
    cout << "队伍是否满了?";
    cout << que.full() << endl;
    cout << "排在队伍最前面的H出队" << endl;
    que.deQueue();
    cout << "队伍是否空了?";
    cout << que.empty() << endl;
    que.print();
}

int main()
{
    // test0();
    test1();
    return 0;
}