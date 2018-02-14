/* 安迪的第一个字典：UVa10815
 * 输入一个文本，找出所有不同的单词（连续的字母序列），按字典序从小到大输出。单词不区分大小写。
 * 样例输入：
 * Adventures in Disneyland
 * Two blondes were going to Disneyland when they came to a fork in the road. The sign read:"Disneyland left."
 * So they went home.
 * 样例输出（为了节约篇幅只保留前5行）：
 * a
 * adventures
 * blondes
 * came
 * disneyland
 */
/*set就是数学上的集合——每个元素最多只出现一次。由于string已经定义了"小于"运算符，直接使用set保存单词集合即可。
 * 注意：输入时把所有非字母的字符变成空格，然后利用stringstream得到各个单词
 * */
#define LOCAL //重定向
#include <iostream>
#include <string>
#include <set>   //使用容器set所要包含的库
#include <sstream> //用到stringstream要包含的库
using namespace std;

set<string> dict; //string集合，定义字典集合，元素都是字符串；

int main() {
#ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    string s,buf;
    while (cin>>s) {
        for (int i = 0; i < s.length(); ++i) {
            if (isalpha(s[i])) //判断是否是字符；
                s[i] = tolower(s[i]); //如果是字符，把字符变成小写。
            else
                s[i] = ' ';
        }
        stringstream ss(s);//获取到各个单词，把s赋值给ss
        while (ss >> buf) dict.insert(buf);
    }
    for (set<string>::iterator it = dict.begin();it != dict.end(); ++ it)
        cout << *it << "\n";

    return 0;
}