#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <deque>
#include <list>
#include <string.h>

// 字符串反转
void ReverseString(char *chs)
{
    char temp;
    for (int i = 0, j = strlen(chs) - 1; i < strlen(chs) / 2; i++, j--)
    {
        temp = chs[i];
        chs[i] = chs[j];
        chs[j] = temp;
    }
}

void PrintChars(char *chs)
{
    for (int i = 0; i < strlen(chs); i++)
    {
        printf("%c", chs[i]);
    }
    printf("\n");
}

int main()
{
    char chs[] = {'d', 'a', 'r', 'w', 'i', 'n'};
    ReverseString(chs);
    PrintChars(chs);

    return 0;
}