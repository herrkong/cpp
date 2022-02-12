
#include "Singleton.hpp"

int main(){
    Singleton * pSingleton = Singleton::GetSingleton();
    Singleton * pSingleton2 = Singleton::GetSingleton();
    return 0;
}