#define LOCAL
#include <iostream>
#include <queue>  //使用队列queue，先进先出；
using namespace std;

int main() {
#ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int n,x;
    queue<int> q;
    while (cin>>n && n){
        //初始化，把牌按顺序整理好
        for (int i = 1; i <= n; ++i)
            q.push(i);
        cout<<"Discarded cards: ";
        while (q.size()>1){
            cout<<q.front();//打印第一张牌，并不删除；
            q.pop();  //取出第一张牌；
            x=q.front(); //把最上面的那张牌赋值给x
            q.pop(); //拿到最上面的牌；
            if(!q.empty()) cout<<", "; //如果队列不为空，即x表示的不是最后一张牌，打印','进行分隔；
            q.push(x); //把拿到的最上面的牌放到最下面。
        }
        cout<<endl<<"Remaining card: "<<q.front()<<endl;
        q.pop();//打印出剩余的最后一张牌后，记得清空队列。！！！这个别忘了。
    }
    return 0;
}