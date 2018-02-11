/*输入输出框架*/
/* 题目：数据统计
 * 输入一些整数，求出它们的最小值、最大值和平均值（保留3位小数）。输入保证这些数都是不超过1000的整数。
 * 样例输入：
 * 2 8 3 5 1 7 3 6
 * 样例输出：
 * 1 8 4.375
 */
/*数据统计（重定向版）*/
//遇到bug1，mac的文本文件生成的是rtf文件，导致程序运行不了;在item下可以运行，结果正确；Clion不行，输出结果是错的。
// 找到原因，因为没有设置workdirectory
/*
#define LOCAL
#include <stdio.h>
#define INF 10000 //变量在未赋值前的值不确定。在这里设置一个输入极限值。
int main() {
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
    int x,n=0,min=INF,max=-INF;
    double s=0;
    while(scanf("%d",&x)==1) //scanf返回的事成功输入的变量个数，当输入结束时，scanf函数无法再次读取x，将返回0；
        //windows下，先按Enter，再按Ctrl+Z键，最后再按Enter键结束输入；
        //Linux下，输入完毕后按Ctrl+D结束输入。
        //Mac下，Ctrl+D相当于发送EOF；解决办法之一：我用的是Alt+D+Enter;解决办法之二：Help->Find Action->Registry...->
        //勾选掉run.process.with.pty
    {
        s+=x;
        n++;
        if (x<min) min=x;
        if (x>max) max=x;
        //输出中间结果，提交代码时可以注释掉
        //printf("x=%d,min=%d,max=%d\n",x,min,max);

    }
    printf("%d %d %.3f\n",min,max,s/n);
    return 0;
}*/
/*数据统计（fopen版）*/
#include <stdio.h>
#define INF 10000
int main()
{
    FILE *fin,*fout;
    fin = fopen("data.in","rb"); //rb表示以读方式打开一个二进制文件，只允许读数据
    fout= fopen("data.out","wb"); //wb表示以写方式打开一个二进制文件，只允许写数据
    int x,n=0,min=INF,max=-INF;
    double s=0;
    while(fscanf(fin,"%d",&x)==1)
    {
        s+=x;
        if(x<min) min=x;
        if(x>max) max=x;
        n++;
    }
    fprintf(fout,"%d %d %.3f\n",min,max,s/n);
    fclose(fin);
    fclose(fout);
    return 0;
}