#define LOCAL
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
#ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int n,t,tmp;
    cin>>t; //t为案例个数；
    while(t--){
        cin>>n;
        int ans[10]={0};//初始化，ans[10]保存的是0-9每个数字出现的次数；
        for (int i = 1; i <= n; ++i) {//统计从1到n，1-9数字出现次数；
            tmp=i;
            while(tmp){
                ans[tmp%10]++; //tmp个位数字次数+1；
                tmp/=10;//tmp除以10
            }
        }
        for (int j = 0; j <= 8; ++j) {//数字0-8中间用空格隔开；
            cout<<ans[j]<<' ';
        }
        cout<<ans[9]<<endl;
    }
    return 0;
}