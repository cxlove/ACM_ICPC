#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <ctime>
#include <cstdlib>
#define Hash1 (LL)11111
#define Hash2 (LL)13337
#define lson l,m,rt << 1
#define rson m + 1,r,rt << 1 | 1
#define eps 1e-8
#define ft first
#define sd second
#define LL long long
#define Test puts("END")
#define pi acos(-1.0)
#define clr(a,b) memset(a,b,sizeof(a));
#define zero(x) (((x)>0?(x):-(x))<eps)
#pragma comment(linker, "/STACK:32000000")
using namespace std;
const int MOD = 1000000007;
const int INF = 1000000000;
const int N = 1200000;
const int M = 1000;

char s[N];
int n,times[26] = {1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
char pos[26] = {'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','7','7','7','8','8','8','9','9','9','9'};

int main()
{
    // freopen("input.txt","r",stdin);
    while(gets(s)!=NULL){
        int len = strlen(s);
        bool input = false;//0 present pinyin,while 1 present number
        for(int i = 0;i < len;i ++){
            if(s[i] == ' '){
                if(input == false) putchar('0');
                else {
                    printf("#0");
                    input = false;
                }
            }
            else if(s[i] >= '0' && s[i] <= '9'){
                if(input == false){
                    input = true;
                    printf("#%c",s[i]);
                }
                else putchar(s[i]);
            }
            else if(s[i] >= 'a' && s[i] <= 'z'){
                if(input == true){
                    input = false;
                    putchar('#');
                }
                if(i && s[i - 1] >= 'a' && s[i - 1] <= 'z' && pos[s[i] - 'a'] == pos[s[i - 1] - 'a']) printf("ok");
                for(int j = 0;j < times[s[i] - 'a'];j ++)
                    putchar(pos[s[i] - 'a']);
            }
            else{
                if(input == true){
                    input = false;
                    putchar('#');
                }
                if(i && (s[i - 1] == ',' || s[i - 1] == '.' || s[i - 1] == '!'))
                    printf("ok");
                if(s[i] == ',') putchar('1');
                else if(s[i] == '.') printf("11");
                else printf("111");
            }
        }
        if(s[len-1]==' '||(s[len-1]>='0'&&s[len-1]<='9'));
        else printf("ok");
        puts("");
    }
    return 0;
}