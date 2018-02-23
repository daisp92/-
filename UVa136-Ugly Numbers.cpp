/* 丑数 Ugly Numbers UVa 136
 * 丑数是指不能被2，3，5以外的其他素数整除的数。把丑数从小到大排列起来，结果如下：
 * 1，2，3，4，5，6，8，9，10，12，15,……
 * 求第1500个丑数。
 * */
/* 解题思路：
 * 从小到大生成各个丑数。最小的丑数是1，而对于任意丑数x,2x、3x、5x也都是丑数。这样就可以用一个优先队列保存所有已生成的丑数，每次取出
 * 最小的丑数，生成3个新的丑数。
 * 唯一需要注意的是，同一个丑数有多种生成方式，所以需要判断一个丑数是否已经生成过。
 */
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
typedef long long LL;
const int coeff[3]={2,3,5}; //系数数组；

int main() {
    priority_queue<LL, vector<LL>,greater<LL> > pq; //优先队列，越小的整数优先级越大；
    set<LL> s; //s为丑数集合；
    LL x;
    pq.push(1); //元素入队；
    s.insert(1); //集合插入元素；
    for (int i = 1; i <= 1500; ++i) {
        x=pq.top(); pq.pop();
        for (int j = 0; j < 3; ++j) {
            LL x2=x* coeff[j];
            if (!s.count(x2)) {s.insert(x2); pq.push(x2);} //s.count(x2)判断x2在s中是否出现；
        }
    }
    cout<<"The 1500'th ugly number is "<<x<<".\n";
    return 0;
}