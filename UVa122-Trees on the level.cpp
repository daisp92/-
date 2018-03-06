#define LOCAL
#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
const int maxn=256;
char s[maxn];//保存读入节点
bool failed;

//节点类型
struct Node{
    bool  have_value; //是否被赋值过
    int v; //节点值
    Node *left,*right;
    Node():have_value(false),left(NULL),right(NULL){} //构造函数
};
Node* root;
//为新的Node用new运算符申请内存，并执行构造函数
Node* newnode(){return new Node();}
//添加节点
void addnode(int v,char* s){
    int n=strlen(s);
    Node* u=root; //从根节点开始往下走
    for (int i = 0; i < n; ++i) {
        if (s[i]=='L'){
            if (u->left==NULL) u->left=newnode();//节点不存在，建立新节点
            u=u->left;//往左走
        } else if (s[i]=='R'){
            if (u->right==NULL) u->right=newnode();
            u=u->right;
        }
    }//忽略其他情况，即最后那个多余的右括号；
    if (u->have_value) failed=true; //已经赋过值，表明输入错误
    u->v=v;
    u->have_value=true;//别忘了做标记；
}
//释放一棵二叉树的代码；
void remove_tree(Node * u) {
    if (u == NULL) return; //提前判断比较稳妥；
    remove_tree(u->left);
    remove_tree(u->right);
    delete u;
}

//输入部分
bool read_input(){
    failed=false;
    remove_tree(root);//释放上一棵树二叉树申请的内存空间；
    root=newnode();//创建根节点；
    for (; ;) {
        if (scanf("%s",s)!=1) return false; //遇到()前，输入结束
        if (!strcmp(s,"()")) break;//读到结束标志，退出循环
        int v;
        sscanf(&s[1],"%d",&v); //读入节点值；
        addnode(v,strchr(s,',')+1);//查找逗号，插入节点；
    }
    return true;
}

//BFS宽度优先遍历
bool bfs(vector<int>& ans){
    queue<Node*> q;
    ans.clear();
    q.push(root);
    while(!q.empty()){
        Node* u=q.front();q.pop();
        if(!u->have_value) return false; //有节点没有赋值过，表明输入错误；
        ans.push_back(u->v); //增加到输入序列尾部
        if (u->left != NULL) q.push(u->left); //把左子节点放入队列；
        if (u->right!=NULL) q.push(u->right);
    }
    return true;
}

int main() {
#ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    vector<int> ans;
    while (read_input()){
        if(!bfs(ans)) failed=1;
        if(failed) cout<<"-1"<<endl;
        else{
            for (int i = 0; i < ans.size(); ++i) {
                if (i!=0) cout<<" ";
                cout<<ans[i];
            }
            cout<<endl;
        }
    }
    return 0;
}