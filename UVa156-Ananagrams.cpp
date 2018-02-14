/* 反片语Ananagrams,UVa156
 * 输入一些单词，找出所有满足如下条件的单词：该单词不能通过字母重排，得到输入文本中的另外一个单词。在判断是否满足条件时，字母部分大小写，
 * 但在输出时应保留输入中的大小写，按字典序进行排列（所有大写字母在所有小写字母的前面）
 * 样例输入：
 * ladder came tape soon leader acme RIDE lone Dreis peat
 *  ScAlE orb  eye  Rides dealer  NotE derail LaCeS  drIed
 * noel dire Disk mace Rob dries
 * #
 * 样例输出：
 * Disk
 * NotE
 * derail
 * drIed
 * eye
 * ladder
 * soon
 */
/*解题思路：把每个单词"标准化"，即全部转化为小写字母后进行排序，然后放到map中进行统计。*/
#define LOCAL
#include <iostream>
#include <string>
#include <cctype>  //字符映射，tolower();toupper();还有字符测试,判断是何字符；用的较多的是isalpha()判断字母字符。
#include <vector> //vector不定长数组，a.size()读取大小，a.resize()改变大小，a.push_back()向尾部添加元素，a.pop_back()删除最后一个元素
#include <map>  //map和set都支持insert,find,count和remove操作，并且可以按照从小到大的顺序循环遍历其中的元素。map也称为"关联数组"；
#include <algorithm>  //用到了sort算法
using namespace std;

map<string,int> cnt; //用于统计词频（单词排序之后的）；
vector<string> words; //用于输入字符串；

//将单词s标准化
string repr(const string& s){ //const修饰函数参数,引用参数在函数内为常量不可变；传递地址比一般按值传递更高效
    string ans=s;
    for (int i = 0; i < ans.length(); ++i)
        ans[i] = tolower(ans[i]);
    sort(ans.begin(),ans.end());
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    string s; //输入字符串
    while (cin>>s){
        if (s[0]=='#') break; //#表示输入结束
        words.push_back(s); //把单词加入到向量words中
        string r=repr(s); //标准化
        if (!cnt.count(r)) cnt[r]=0; //如果r没有出现过，初始化为0
        cnt[r]++;
    }
    vector<string> ans;
    for (int i = 0; i < words.size(); ++i)
        if (cnt[repr(words[i])]==1) ans.push_back(words[i]);
    sort(ans.begin(),ans.end());
    for (int j = 0; j < ans.size(); ++j)
        cout<<ans[j]<<"\n";
    return 0;
}