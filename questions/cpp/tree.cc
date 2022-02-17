#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <list>

// 求二叉树的树高
// 递归实现
struct root
{
    std::string value;
    root *left;
    root *right;
};

int GetTreeHigh(root *r)
{
}

// 非递归实现
int GetTreeHigh2(root * r)
{

}

root *InitTree()
{
    root *r1 = new root;
    r1->value = "a";
    r1->left = NULL;
    r1->right = NULL;

    root * r2 = new root;
    r2->value = "b";
    r2->left = NULL;
    r2->right = NULL;

    root * r3 = new root;
    r3->value = "c";
    r3->left = NULL;
    r3->right = NULL;

    r1->left = r2;
    r1->right = r3;

}

// 二叉树的层次遍历
// 借助队列queue

void PrintTree1(root * r){
    
}

// 二叉树的前序遍历
void PrintTree2(root * r){

}

// 二叉树的中序遍历
void PrintTree3(root * r){

}

// 二叉树的后序遍历



int main()
{

    return 0;
}