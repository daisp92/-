#define LOCAL
#include <iostream>
#include <cstring>
using namespace std;
const int maxn=80;

int main() {
#ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int T,p,flag;
    char s[maxn];
    cin>>T;
    while(T--){
        cin>>s;
        int l=strlen(s);
        for (p = 1; p < l+1; ++p) {//p是周期，从1到l，一个一个试，最先找到合适的p进行跳出；
            flag=1;
            for (int j = 0; j < l; ++j)//j遍历字符串s；
                if (s[j]!=s[(j+p)%l]) //找到周期p的话，if永远不成立；
                {
                    flag=0;
                    break;
                }
            if(flag){
                cout<<p<<endl;
                break;
            }
        }
        if (T) cout<<endl;
    }
    return 0;
}