/* 分析：
 * 本题的关键是解析表达式。本题的表达式比较简单，可以用一个栈来完成；遇到字母入栈，遇到右括号出栈并计算，然后结果入栈。因为
 * 输入保证合法，括号无需入栈。
 */
#define LOCAL
#include <iostream>
#include <cstdio>
#include <stack>
#include <string>
using namespace std;
//结构体，定义矩阵a*b；
struct Matrix {
    int a,b;
    Matrix(int a=0,int b=0):a(a),b(b) {}
} m[26];//m[26]其中26表示A-Z；

stack<Matrix> s;

int main() {
#ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int n; //n个矩阵
    cin>>n;
    //输入n个矩阵
    for (int i = 0; i < n; ++i) {
        string name;//矩阵名字
        cin>>name;
        int k=name[0]-'A';
        cin>>m[k].a>>m[k].b;
    }
    string expr;
    while(cin>>expr){
        int len=expr.length();//表达式长度；
        bool error=false;
        int ans=0; //乘法次数的答案初始化；
        for (int i = 0; i < len; ++i) {
            if (isalpha(expr[i])) s.push(m[expr[i]-'A']);
            else if (expr[i]==')'){
                Matrix m2=s.top(); s.pop();
                Matrix m1=s.top(); s.pop();
                if (m1.b != m2.a) {error=true; break;}
                ans += m1.a* m1.b * m2.b;
                s.push(Matrix(m1.a,m2.b));
            }
        }
        if (error) cout<<"error"<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}