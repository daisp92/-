/* 团体队列 Team Queue,UVa 540
 * 有t个团队的人正在排一个长队。每次新来一个人，如果他有队友在排队，那么这个新人会插队到最后一个队友的身后。如果没有任何一个队友排队，则他
 * 会排到长队的队尾。
 * 输入每个团队中所有成员的编号，要求支持如下三种指令（前两种指令可以穿插进行）。
 * ENQUEUE x:编号为x的人进入长队。
 * DEQUEUE: 长队的队首出队
 * STOP: 停止模拟
 * 对于每个DEQUEUE指令，输出出队的人的编号。
 * 样例输入：
 * 2
 * 3 101 102 103
 * 3 201 202 203
 * ENQUEUE 101
 * ENQUEUE 201
 * ENQUEUE 102
 * ENQUEUE 202
 * ENQUEUE 103
 * ENQUEUE 203
 * DEQUEUE
 * DEQUEUE
 * DEQUEUE
 * DEQUEUE
 * DEQUEUE
 * DEQUEUE
 * STOP
 * 2
 * 5 259001 259002 259003 259004 259005
 * 6 260001 260002 260003 260004 260005 260006
 * ENQUEUE 259001
 * ENQUEUE 260001
 * ENQUEUE 259002
 * ENQUEUE 259003
 * ENQUEUE 259004
 * ENQUEUE 259005
 * DEQUEUE
 * DEQUEUE
 * ENQUEUE 260002
 * ENQUEUE 260003
 * DEQUEUE
 * DEQUEUE
 * DEQUEUE
 * DEQUEUE
 * STOP
 * 0
 * 样例输出：
 * Scenario #1
 * 101
 * 102
 * 103
 * 201 202 203
 * Scenario #2
 * 259001
 * 259002
 * 259003
 * 259004
 * 259005
 * 260001
 * */
#define LOCAL
#include <cstdio>
#include <queue>
#include <map>
using namespace std;

const int maxt=1000+10;

int main() {
#ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int t,kcase=0; //t表示队列个数；kcase表示案例个数
    while(scanf("%d",&t)==1 && t){ //当t=0时，输入终止
        //记录所有人的团队编号
        map<int,int> team; //team[x]表示编号为x的人所在的团队编号
        for (int i = 0; i < t; ++i) {
            int n,x; //n表示队列有n个元素；x表示元素；
            scanf("%d",&n);
            while(n--) {scanf("%d",&x); team[x]=i;}
        }

        printf("Scenario #%d\n", ++kcase);

        //模拟
        queue<int> q, q2[maxt]; //q是团队的队列，里面是团队编号，q2[i]是团队i成员的队列
        for(;;){
            int x;
            char cmd[10];
            scanf("%s",cmd);
            if (cmd[0]=='S') break;
            else if (cmd[0]=='D'){
                    int t=q.front();
                    printf("%d\n",q2[t].front());
                    q2[t].pop();
                    if(q2[t].empty()) q.pop(); //团队t全体成员出队列。
                }
            else if (cmd[0]=='E'){
                scanf("%d",&x);
                int t=team[x];
                if (q2[t].empty()) q.push(t); //团队t进入队列
                q2[t].push(x);
            }
        }
        printf("\n");
    }
    return 0;
}