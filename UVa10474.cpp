#include <iostream>
//#include <algorithm> //这个没用上
using namespace std;
const int maxn = 10000;

int main() {
    int n,q,x,a[maxn],kcase=0;
    while (scanf("%d%d",&n,&q)==2 && n)
    {
        //printf("CASE# %d:\n",++kcase);
        for (int i = 0; i < n; ++i) {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);  //对数组a进行排序，从小到大输出
        printf("CASE# %d:\n",++kcase); //这个位置也可以
        while (q--)
        {
            scanf("%d",&x);
            int p=lower_bound(a,a+n,x)-a;  //在已排序的数组a中寻找x.p是x相对于a[0]的位置，所以printf中需要+1输出
            if (a[p]==x) printf("%d found at %d\n",x,p+1);
            else printf("%d not found\n",x);
        }
    }
    return 0;
}