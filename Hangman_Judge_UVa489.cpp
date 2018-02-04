/* 刽子手游戏，UVa489
 * 猜单词游戏， 游戏规则：计算机想一个单词让玩家猜，玩家每次可以猜一个字母。
 * 如果单词里有那个字母，单词中的所有该字母都算猜对；如果没有那个字母，则猜错一次，最多只能错6次。
 * 注意，猜一个已经猜过的字母也算错。输入给出正确单词和玩家的猜测，判断玩家赢、 输还是放弃。
 * 每组数据包含3行，第1行是游戏编号（-1为输入结束标记），第2行是计算机想的单词，第3行是玩家的猜测。 后两行保证只含小写字母。
 * 样例输入：
 * 1
 * cheese
 * chese
 * 2
 * cheese
 * abcdefg
 * 3
 * cheese
 * abceefghij
 * -1
 * 样例输出
 * Round 1
 * You win.
 * Round 2
 * You chickened out.
 * Round 3
 * You lose.
 */
#include <stdio.h>
#include <string.h>
#define maxn 100
int win,lose; //win=1表示赢，lose=1表示输
char s[maxn],s2[maxn];//答案是s字符串，猜的字符串是s2
int left,chance; //还需要猜left个位置，错chance次后会输
void guess(char ch) //函数在前，main函数在后；
{
    int err = 1;
    for(int i=0;i<strlen(s);i++)
        if(s[i]==ch) {left--; s[i]=' '; err=0;} //' '可以换为其他非字母字符
    if(err) --chance;
    if(!chance) lose=1;
    if(!left) win=1;
    /*调试每猜完一个字母后，打印出s、left、chance的值 */
    //printf("%s,%d,%d\n",s,left,chance);

}
int main() {
    int rnd; //第几个回合
    //while(scanf("%d%s%s",&rnd,s,s2)==3 && (rnd != -1))
    while(scanf("%d",&rnd)==1 && (rnd != -1))
    {
        scanf("%s%s",s,s2);
        printf("Round %d\n",rnd);
        win = lose = 0;
        left= strlen(s);
        chance = 7;
        for(int i=0;i<strlen(s2);i++)
        {
            guess(s2[i]); //猜一个字母
            if(win==1 || lose==1) //检查状态
                break;
        }
        //根据结果进行输出
        if (win==1) printf("You win.\n");
        else if (lose==1) printf("You lose.\n");
        else printf("You chickened out.\n");
    }
    return 0;
}
