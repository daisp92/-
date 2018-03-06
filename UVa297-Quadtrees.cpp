#define LOCAL
#include <iostream>
#include <cstring>
using namespace std;

const int maxn=32;//矩阵有maxn*maxn个单元；边长有32；
int mat[maxn][maxn];
int sum;//求黑色的面积
char quad;//输入字符

//一边建四分树，一边统计黑色单元的面积；
void build(char q,int r,int c,int w){//q为读取指令中的字符；r为行起点，c为列起点；w为边长
    cin>>q;
    if (q=='p'){//如果q是父节点的话
        build(q,r,c+w/2,w/2);//子树是从右上逆时针计算序号；
        build(q,r,c,w/2);
        build(q,r+w/2,c,w/2);
        build(q,r+w/2,c+w/2,w/2);
    }
    else
        if (q=='f'){
            for (int i = r; i < r+w; ++i) //从r到r+w，小正方形的边长；
                for (int j = c; j < c+w; ++j)
                    if (mat[i][j]==0){
                        mat[i][j]=1;
                        sum++;
                    }
        }
}

int main() {
#ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int kcase;
    cin>>kcase;
    while (kcase--){
        sum=0;
        memset(mat,0, sizeof(mat));
        build(quad,0,0,maxn);
        build(quad,0,0,maxn);
        cout<<"There are "<<sum<<" black pixels.\n";
    }
    return 0;
}