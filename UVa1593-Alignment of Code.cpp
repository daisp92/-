#define LOCAL
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main() {
#ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    vector <vector<string>> txt; //txt存放所有的输入；
    map<int,int> column; //column表示每列最长单词的长度；
    string hang,word; //hang是一行的输入；word是单个单词的输入；
    int col=0,row=0; //row表示输入的行数

    //把所有的输入保存到txt，对于每一列，找出最长单词的长度
    while (getline(cin,hang)){  //getline获取一行的数据
        stringstream hangin(hang); //stringstream中，空格会作为内部的分隔符
        vector <string> temprow; //临时行
        int now=1; //标识当前读到的是该行第几个单词（处于第几列）
        while (hangin>>word){
            temprow.push_back(word);
            column[now]=max(column[now],(int)word.size());
            now++;
        }
        txt.push_back(temprow);
    }
    //输出答案
    for (int i = 0; i < txt.size(); ++i) {
        for (int j = 0; j < txt[i].size(); ++j) {
            cout<<txt[i][j];
            for (int k = column[j+1]-txt[i][j].size(); k >= 0; k--) { //打印空格；
                cout<<' ';
            }
            cout<<' ';
        }
        cout<<endl;
    }
    return 0;
}