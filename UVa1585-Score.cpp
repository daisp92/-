#define LOCAL
#include <iostream>
#include <string>
#include <cstdio>
//#include <string>
using namespace std;//没有这个，就无法使用cin等；

const int maxn=80;

int main() {
#ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int n;
    char str[maxn];
    cin>>n;
    while(n--){
        //char str[maxn];
        cin>>str;
        int c=0,sum=0,len;//c表示str[i]的分数，sum表示分数和；
        len=strlen(str); //字符串s的长度；
        //m=str.length(); /*length()需要声明str是string格式的*/
        for (int i = 0; i < len; ++i) {
            if (str[i]=='O')
            {
                c++;
                sum+=c;
            }
            else
                c=0;
        }
        cout<<sum<<endl;
    }
    return 0;
}