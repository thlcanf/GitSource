// 试题描述
//    小军，每天都要从家到学校去上学（好像大家都是这样）。很幸运的是，他家和学校在一条直线上（两点肯定在一条直线上……），现在告诉你小军家的一维坐标n和学校的一维坐标m，请你算出从小军家到学校的距离（注意：不要使用abs函数哟）。
// 输入
//    输入两个整数n和m，n和m之间用空格隔开。
// 输出
//    输出家和学校间的距离。
// 输入示例1
//    1 10
// 输出示例1
//    9
// 输入示例2
//    1 -1
// 输出示例2
//    2
// 数据范围
//    输入和输出均为int范围的整数
#include<stdio.h>
int main()
{
    int m,n,l;
    scanf("%d %d",&m,&n);
    if (m>n)
    {
        l=m-n;
    }
    else
    {
        l=n-m;
    }
    printf("%d",l);
    return 0;
}
