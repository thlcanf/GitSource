// 试题描述
//    给定一个从0秒开始计时的秒数，请将其转换为xx:xx:xx的格式。这种格式一般成为标准时间格式。如1小时1分1秒应该表示的标准时间格式应该是01:01:01，而不是1:1:1。
//    请你完成这个任务，将一个秒数转换为标准时间格式。
// 输入
//    输入一个非负整数n，表示秒数。
// 输出
//    输出n对应的标准时间格式。
// 输入示例
//    71
// 输出示例
//    00:01:11
// 数据范围
//    输入为int范围的整数
#include<stdio.h>
int main()
{
    int a,b,c;
    int s,f,m;
    int r;
    scanf("%d:%d:%d",&a,&b,&c);
    scanf("%d:%d:%d",&s,&f,&m);
    if (a*3600+b*60+c>s*3600+f*60+m)
    {
        r=a*3600+b*60+c-s*3600-f*60-m;
        printf("%d",r);
    }
    else
    {
        return 0;
    }
    
    return 0;
}