#define LOCAL
#include <iostream>
#include <cstring>
using namespace std;
const int maxn=200;
int sum[maxn];

//输入并统计一棵子树，p是树根的水平位置
void build(int p){
    int v;
    cin>>v;
    if(v==-1) return; //子树是空的；
    sum[p]+=v;
    build(p-1);
    build(p+1);
}
//初始化，构建一棵完整的树，一边构造一边统计
bool init(){
    int v;
    cin>>v;
    if(v==-1) return false;

    memset(sum,0, sizeof(sum));
    int pos=maxn/2; //树根的水平位置
    sum[pos]=v;
    build(pos-1); //构建左子树
    build(pos+1); //构建右子树
    return true;
}

int main() {
#ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int kcase=0;
    while(init()){
        int p=0;
        while (sum[p]==0) p++; //找到最左边的叶子的水平位置;
        cout<<"Case "<<++kcase <<":\n"<<sum[p++];
        while (sum[p]!=0)
            cout<<" "<<sum[p++];
        cout<<"\n\n";
    }
    return 0;
}