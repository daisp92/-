#define LOCAL
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int maxn=500005;

struct que{
    int x;
    int y;
}tmp[maxn],rec[maxn];

bool cmp(const que &a, const que &b){
    if (a.x<b.x)
        return true;
    else if (a.x>b.x)
        return false;
    else if (a.y<b.y)
        return true;
    else
        return false;
}
int main() {
#ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int n;
    while(cin>>n && n){
        //初始化
        memset(tmp,0, sizeof(tmp));
        memset(rec,0, sizeof(rec));
        //输入
        for (int i = 0; i < n; ++i) {
            cin>>tmp[i].x>>tmp[i].y;
            rec[i].y=tmp[i].x;
            rec[i].x=tmp[i].y;
        }
        //排序
        sort(tmp,tmp+n,cmp);
        sort(rec,rec+n,cmp);
        //判断
        int flag=1;
        for (int i = 0; i < n; ++i) {
            if (tmp[i].x!=rec[i].x || tmp[i].y !=rec[i].y)
            {
                flag=0;
                break;
            }
        }
        printf("%s\n",flag? "Yes": "No");
    }
    return 0;
}