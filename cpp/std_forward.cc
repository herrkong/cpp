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
#include <functional>

using namespace std;

class Foo
{
public:
    std::string member;

    template<typename T>
    Foo(T&& member): member{std::forward<T>(member)} {}
};


int main()
{
  

    return 0;
}
