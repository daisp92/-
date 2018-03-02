#define LOCAL
#include <iostream>
using namespace std;

int main() {
#ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    char puzzle[12][12]={}; //puzzle矩阵；
    int r,c,kcase=0,id[12][12];//r是行，c是列；
    while(cin>>r && r){
        cin>>c;
        getchar();
        int count=1;
        //设置边界
        for (int i = 0; i <= r+1; ++i)
            puzzle[i][c+1]='\0';
        for (int j = 0; j < c+1; ++j)
            puzzle[r+1][j]='\0';
        //输入puzzle
        for (int i = 1; i <= r; ++i) {
            for (int j = 1; j <= c; ++j) {
                puzzle[i][j]=getchar();
                if (puzzle[i][j]!='*' && (!puzzle[i-1][j] || puzzle[i-1][j]=='*' || !puzzle[i][j-1] || puzzle[i][j-1]=='*'))
                    id[i][j]=count++;
            }
            getchar();
        }
        if (kcase) putchar('\n');
        printf("puzzle #%d:\n",++kcase);
        //Across
        puts("Across");
        for (int i = 1; i <= r; ++i) {
            for (int j = 1; j <= c; ++j) {
                if (puzzle[i][j]!='*' && (puzzle[i][j-1]=='*' || !puzzle[i][j-1]))
                {
                    printf("%3d.",id[i][j]);
                    for (int k = j;puzzle[i][k]!='*' && puzzle[i][k] ; ++k)
                        putchar(puzzle[i][k]);
                    putchar('\n');
                }
            }
        }
        //Down
        puts("Down");
        for (int i = 1; i <= r; ++i) {
            for (int j = 1; j <= c; ++j) {
                if (puzzle[i][j]!='*' && (puzzle[i-1][j]=='*' || !puzzle[i-1][j])) {
                    printf("%3d.", id[i][j]);
                    for (int k = i; puzzle[k][j] != '*' && puzzle[k][j]; ++k)
                        putchar(puzzle[k][j]);
                    putchar('\n');
                }
            }
        }
    }
    return 0;
}