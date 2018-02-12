/* 木块问题（The Blocks Problem,UVa101)
 * 从左到右n个木块，编号0~n-1，要求模拟以下4种操作（下面的a和b都是木块编号）。
 * move a onto b:把a和b上方的木块全部归位，然后把a放在b上面。
 * move a over b:把a上方的木块全部归位，然后把a放在b所在木块堆的顶部；
 * pile a onto b:把b上方的木块全部归位，然后把a及上面的木块整体放在b上面；
 * pile a over b:把a及上面的木块整体放在b所在木块堆的顶部。
 * 遇到quit时终止一组数据。a和b在同一堆的指令是非法指令，应当忽略。
 * 所有操作结束后，输出每个位置的木块列表，按照从底部到顶部的顺序排列。
 * 样例输入：
 * 10
 * move 9 onto 1
 * move 8 over 1
 * move 7 over 1
 * move 6 over 1
 * pile 8 over 6
 * pile 8 over 5
 * move 2 over 1
 * move 4 over 9
 * quit
 * 样例输出：
 * 0: 0
 * 1: 1 9 2 4
 * 2:
 * 3: 3
 * 4:
 * 5: 5 8 7 6
 * 6:
 * 7:
 * 8:
 * 9:
 */
#define LOCAL
#include <cstdio> //包含C语言的printf等函数的库
#include <string>
#include <vector>
#include <iostream>
using namespace std;

const int maxn=30; //题目中规定0<n<25；
int n;
vector<int> pile[maxn]; //每个pile[i]是一个vector，vector是不定长数组

//找木块a所在的pile和height，以引用的形式返回调用者
void find_block(int a,int& p,int& h){
    for(p=0;p<n;p++)
        for (h = 0; h < pile[p].size(); h++) {
            if (pile[p][h]==a) return;
        }
}
//把第p堆高度为h的木块上方的所有木块移回原位
void clear_above(int p,int h){
    for (int i = h+1; i < pile[p].size(); ++i) {
        int b= pile[p][i];
        pile[b].push_back(b); //把木块b放回原位
    }
    pile[p].resize(h+1); //pile只保留下表0~h的元素
}
//把第p堆高度为h及其上方的木块整体移动到p2堆的顶部
void pile_onto(int p,int h,int p2){
    for (int i = h; i < pile[p].size(); ++i)
        pile[p2].push_back(pile[p][i]);
    pile[p].resize(h);
}
void print() {
    for (int i = 0; i < n; ++i) {
        printf("%d:",i);
        for(int j=0;j<pile[i].size();j++)
            printf(" %d",pile[i][j]);
        printf("\n");
    }
}
int main() {
#ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int a,b;
    cin>>n;
    string s1,s2;
    for (int i = 0; i < n; ++i)  pile[i].push_back(i);
    while(cin>>s1>>a>>s2>>b){ //cin遇到空格就算一个变量了吗？
        int pa,pb,ha,hb; //pa表示a所在的堆；ha表示a所在的高度；
        find_block(a,pa,ha);
        find_block(b,pb,hb);
        if(pa==pb) continue; //a和b在同一堆的指令是非法指令，进行忽略
        if(s2=="onto") clear_above(pb,hb);
        if(s1=="move") clear_above(pa,ha);
        pile_onto(pa,ha,pb);
    }
    print();
    return 0;
}