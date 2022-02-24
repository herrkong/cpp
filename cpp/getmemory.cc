#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <deque>
#include <list>
#include <string.h>

// getmemory malloc

void GetMemory(char *p, int nlen)
{
    p = (char *)malloc(nlen);
}

void GetMemory2(char ** pp,int nlen){
    *pp = (char *)malloc(nlen);
}

int main()
{

    char *str = NULL;

    GetMemory2(&str, 11);

    strcpy(str, "hello world");

    printf("%s\n",str);

    return 0;
}
