//bug，一定要注意输入矩阵时，最后一列为空，记得打空格；
#define LOCAL
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
#ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    char m[5][5]; //二维数字表示拼图
    int key=1,t=0; //key表示第几个Puzzle;t用来判断第几行；
    while(cin.get(m[0][0])&&m[0][0]!='Z'){
        if (++t>1) cout<<endl; //先计算++，再计算比较运算符；用来控制输出中的空行，首行前和最后一行后无空行，输出用空行隔开
        int c=0,d=0; //用来标记空白的位置；
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                if (!i&&!j) continue;
                cin.get(m[i][j]);
                if (m[i][j]==' ')
                {
                    c=i;
                    d=j;
                }
            }
            cin.get(); //读取行尾的回车符
        }
        int i=0;
        cout<<"Puzzle #"<<key++<<':'<<endl;
        int flag=0; //标记是否遇到非法命令
        char s;
        while (cin.get(s) && s!='0'){ //模拟空格的移动，注意命令可能不在同一行
            if (flag==1 || s=='\n') continue;
            switch (s){
                case 'A':
                    if (c-1<0) {flag=1; break;}
                    else
                    {
                        m[c][d]=m[c-1][d];
                        m[c-1][d]=' ';
                        c-=1;
                        break;
                    }
                case 'B':
                    if (c+1>4) {flag=1; break;}
                    else
                    {
                        m[c][d]=m[c+1][d];
                        m[c+1][d]=' ';
                        c+=1;
                        break;
                    }
                case 'L':
                    if (d-1<0) {flag=1; break;}
                    else
                    {
                        m[c][d]=m[c][d-1];
                        m[c][d-1]=' ';
                        d-=1;
                        break;
                    }
                case 'R':
                    if (d+1>4) {flag=1; break;}
                    else
                    {
                        m[c][d]=m[c][d+1];
                        m[c][d+1]=' ';
                        d+=1;
                        break;
                    }
                default:
                    flag=1; //遇到回车符或者指定命令外的字母也为非法命令；
                    break;
            }
        }
        cin.get(); //去掉零后面的回车符；
        if (flag)
            cout<<"This puzzle has no final configuration."<<endl;
        else
        {
            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 4; ++j) {
                    cout<<m[i][j]<<' ';
                }
                cout<<m[i][4]<<endl;
            }
        }
    }
    return 0;
}