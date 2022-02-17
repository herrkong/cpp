#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <list>

class Father
{

public:
    virtual void Drink()
    {
        printf("father drink beer\n");
    }
};

class Son : public Father
{

public:
    //  void  Cry(){
    //      printf("son cry\n");
    //  }
    virtual void Drink()
    {
        printf("son drink cola\n");
    }
};

int main()
{
    //基类指针指向子类对象
    Father *p = new (Son);
    p->Drink();
    
    //基类指针无法调用子类的其他函数 因为Father中Cry()
    //p->Cry();

    //子类指针指向基类对象 Father对象无法初始化整个Son指针 
   // Son * p2 = new(Father);

   // 子类指针赋值给父类指针 可以 因为 子类对象也是一个基类对象
    //p = p2;

    // 父类指针赋值给子类指针 需要进行强制类型转换 以为父类不是一个子类对象
    // 基类不具有子类额外增加的部分 强制转换告诉编译器增加子类特有部分
    //Son* p3 = static_cast<Son*>(p);

    //p2->Drink();

    return 0;
}