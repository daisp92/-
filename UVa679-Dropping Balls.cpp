//#define LOCAL
#include <iostream>
#include <cstdio>
//#include <cstring>
using namespace std;

int main() {
#ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int D,I; //D深度，I是小球个数；
    while(scanf("%d%d",&D,&I)==2){
        int k=1;//所有小球都从1号根节点开始
        for (int i = 1; i < D; ++i) //总共下落D-1层
            if(I%2) {k=2*k; I=(I+1)/2;} //每下落一层，判断小球是往左走，还是往右走；I%2=1时为奇数，向左走，k=k*2表示下落到左子树节点;
            else {k=2*k+1; I/=2;} //I为奇数时，I是第(I+1)/2个经过左子树的小球；I为偶数时，是第I/2个经过右子树的小球。
        cout<<k<<endl;
    }
    return 0;
}