//调bug：stack<int> s;还有A=B=1要放在第二个while循环里。
#define LOCAL
#include <iostream>
//#include <cstdio>
#include <stack>   //在中转站C中，车厢符合后进先出的原则，因此是一个栈。
using namespace std;
const int maxn=1000+10;

int n,target[maxn];

int main() {
#ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    while(scanf("%d",&n)==1 && n){   //输入n节车厢，当n=0时，停止输入，程序终止。
        //stack<int> s;
        while(scanf("%d",&target[1])==1 && target[1]) {   //while用来输入目标序列。当target[1]=0时，表示目标序列输入停止。
            for (int i = 2; i <= n; ++i)
                scanf("%d", &target[i]);
            int ok = 1,A=1,B=1;
            stack<int> s;
            //判断逻辑
            while (B <= n) {  //B用来计数，遍历target数组。
                if (A == target[B]) {
                    A++;
                    B++;
                }
                else if (!s.empty() && s.top() == target[B]) {
                    s.pop();
                    B++;
                }
                else if (A <= n) s.push(A++);   //A<=n时，把A加入栈，
                else {
                    ok = 0;
                    break;
                }
            }
            printf("%s\n", ok ? "Yes" : "No");
        }
        cout<<endl;
    }
    return 0;
}