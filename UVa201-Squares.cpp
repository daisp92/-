#include <iostream>
using namespace std;
#define maxn 10
int H[maxn][maxn],V[maxn][maxn]; //H数组表示横边，V数组表示竖边。

int main() {
    int n,m,x,y,kcase = 0; //n表示n行n列的dots，m表示m条边；当输入字符H时，x为横坐标，y为纵坐标；字符V时，y为横坐标，x为纵坐标。
    //kcase表示第kcase个问题。
    char c; //输入字符
    while (~scanf("%d%d",&n,&m)) //~是按位取反，scanf的返回值是输入值的个数，没有输入会返回-1，-1按位取反是0，所以本句意思是当没有
        //输入的时候退出循环
    {
        getchar(); //在按回车键之前输入了不只一个字符，其他字符会保留在键盘缓冲区中，等待后续getchar()调用读取。
        /*初始化*/
        for (int i = 1; i <= n ; ++i)
            for (int j = 1; j <=n ; ++j)
                V[i][j]=H[i][j]=0;
        /*输入边的数组*/
        for (int i = 1; i <= m ; ++i) {
            scanf("%c%d%d",&c,&x,&y); //c读取字符，H表示横边，V表示纵边
            getchar();
            if (c=='H')
                H[x][y]=1;
            else
                V[y][x]=1; //认真审题，此处就不出错
        }
        if(kcase++) printf("\n**********************************\n\n");
        printf("Problem #%d\n\n",kcase);
        int sum=0; //sum=0表示没有正方形；
        for (int r = 1; r <= n ; ++r) {//r表示正方形边长，从1到n；
            int count=0,flag=0; //flag这里也可以不赋值，count统计边长为r的正方形个数；flag=1表示存在边长为r的正方形；
            /*判断边长为r的正方形是否存在，并统计个数*/
            for (int i = 1; i+r <=n ; ++i) //行从1到n-r
                for (int j = 1; j+r <=n ; ++j) { //列从1到n-r
                    flag=1; //假设正方形存在
                    for (int h = j; h <j+r ; ++h)  //当i行h列时，判断边长r的正方形的横边是否存在；此处限制条件是<，思考一下为什么；
                        if (!H[i][h] || !H[i+r][h]) flag=0;
                    for (int v = i; v <i+r ; ++v) //当v行j列时，判断边长r的正方形的纵边是否存在；此处限制条件是<，思考一下为什么；
                        if (!V[v][j] || !V[v][j+r]) flag=0;
                    count+=flag;
                }
            sum+=count;
            if(count) printf("%d square (s) of size %d\n",count,r);
        }
        if (!sum) printf("No completed squares can be found.\n");
    }
    return 0;
}


