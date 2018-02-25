#define LOCAL
#include <iostream>
#include <string>
#include <cstdio>
#include <ctype.h>
#include <map>
using namespace std;
#define maxn 100

int main() {
#ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    char s[maxn]; //存放分子式；
    map<char,double> m; //映射，记录原子对应原子量；
    m['C']=12.01;
    m['H']=1.008;
    m['O']=16.00;
    m['N']=14.01;
    int T;//T为输入分子式的个数；
    cin>>T;
    while (T--){
        cin>>s; //输入分子式；
        double sum,a,b; //sum为分子量；a记录上一个原子对应的原子量；b记录原子的个数；
        a=b=sum=0.0; //初始化；
        int len=strlen(s); //分子式字符串长度；
        for (int i = 0; i < len; ++i) {
            if (isalpha(s[i])){ //判断是否字母；
                sum+=a*b; //碰到字母后，计算到该原子之前的分子量；
                b=1;  //如果下一个字符还是字母，则s[i]该原子仅有1个；
                a=m[s[i]];
            }
            else if(isdigit(s[i])){ //判断是否数字
                if(isdigit(s[i-1])) //如果前一位也是数字
                    b=b*10+s[i]-'0';
                else
                    b=s[i]-'0';
            }
        }
        printf("%.3f\n",sum=sum+a*b);
    }

    return 0;
}