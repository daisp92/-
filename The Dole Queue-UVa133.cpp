//一个长度为N的循环队列，一个人从1号开始逆时针开始数数，第K个出列，
// 一个人从第N个人开始顺时针数数，第M个出列，选到的两个人要同时出列（以不影响另一个人数数），选到同一个人就那个人出列。
#include <stdio.h>
#define maxn 25
int n,k,m,a[maxn];

int go(int p,int d,int t) //p是从哪个人开始数，d是步长，t是走多少步,go是逆时针数
{
    while(t--)
    {
        do { p=(p+d+n-1)%n+1; printf("%d ",p);} while(a[p]==0); //走到下一个非0数字.这是一个难点p=(p+d+n-1)%n+1
        //t--;
    }
    return p;
}

int main() {
    while(scanf("%d%d%d",&n,&k,&m)==3 && n)
    {
        //scanf("%d%d",&k,&m);
        for(int i=1;i<=n;i++) a[i]=i;
        int left=n;//还剩下的人数
        int p1=n,p2=1;   //这也是难点
        while(left)
        {
            p1=go(p1,1,k);
            p2=go(p2,-1,m);
            printf("%3d",p1);
            left--;
            if(p2!=p1) {printf("%3d",p2); left--;}
            a[p1]=0;
            a[p2]=0;
            if(left) printf(",");
        }
        printf("\n");

    }
    return 0;
}