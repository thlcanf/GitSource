// 试题描述
//    排序我们都做过，但是都是针对所有数值的大小，但是，如果我们把排序的条件改成以绝对值为排序的条件呢？
//    请你对给定的数据按照绝对值的大小进行从大到小的排序（输入数据已经保证没有绝对值相等的两个数）。请使用循环和数组实现。
// 输入
//    输入包含二行：
//    第一行包括一个正整数n（0 < n < 100）。
//    第二行有n个整数（范围不超过int），且两两之间用一个空格隔开。
// 输出
//    输出n行，每个整数占一行。
// 输入示例
//    3
//    3 -4 2
// 输出示例
//    -4
//    3
//    2
// 数据范围
//    对于100%的数据，0 < n < 100

#include <stdio.h>
int main()
{
    int s[100], n, r[100], j, t, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &s[i]);
        if (s[i] >= 0)
        {
            r[i] = s[i];
        }
        else
        {
            r[i] = -s[i];
        }
    }
    for (i = 0; i < n - 1; ++i)
    {
        for (j = 0; j < n - i - 1; ++j)
        {
            if (r[j] > r[j + 1])
            {
                t = r[j];
                r[j] = r[j + 1];
                r[j + 1] = t;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if ((r[i] == s[j]) || (r[i] == -s[j]))
            {
                r[i] = s[j];
            }
        }
    }
    for (j = n - 1; j < n; j--)
    {
        printf("%d\n", r[j]);
        if (j == 0)
        {
            break;
        }
    }
    return 0;
}