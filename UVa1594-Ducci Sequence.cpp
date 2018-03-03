/* 解题思路：Floyd判圈方法
 * 如果从同一个起点(即使这个起点不在某个环上)同时开始以不同速度前进的2个指针最终相遇，
 * 那么可以判定存在一个环，且可以求出2者相遇处所在的环的起点与长度。
 */
#define LOCAL
#include <iostream>
#include <cmath>  //绝对值函数abs()
using namespace std;

const int maxn=100; //题目要求 3<=n<=15,设置数组最大为100；
int t,n,a[maxn],b[maxn],c[maxn]={0};//t是案例个数；n是输入的字串包含的数字个数；c为全0数组；

void neq(int a[]){ //函数用来求出下一个序列；
    a[n+1]=a[1];
    for (int i = 1; i <= n; ++i)
        a[i]=abs(a[i]-a[i+1]);
}
bool equal(int a[],int b[]){ //判断两个序列是否相等；
    for (int i = 1; i <= n; ++i)
        if (a[i]!=b[i]) return false;
    return true;
}

int main() {
#ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    cin>>t;
    while(t--){
        cin>>n;
        //输入序列；
        for (int i = 1; i <= n; ++i) {
            cin>>a[i];
            b[i]=a[i];
        }
        //a[n+1]=b[n+1]=a[1];
        bool loop=true;
        for (int j = 0; j < 1010; ++j) {
            neq(a); //a序列每走一次，b序列走两次，如果a和b相等，说明有环，即循环；
            neq(b);
            neq(b);
            if (equal(a,c)) {loop= false; break;}
            if (equal(a,b)) {loop= true; break;}
            if (equal(b,c)) {loop= false; break;}
        }
        if (loop) cout<<"LOOP"<<endl;
        else cout<<"ZERO"<<endl;
    }
    return 0;
}