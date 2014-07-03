#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <climits>
#include <vector>
#define LL long long 
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
using namespace std;
char str[105][105];
char word[111111];
void init(){
    for(int i=0;i<17;i++){
        for(int j=0;j<33;j++){
            if(i%2==0){
                if(j%4==0) str[i][j]='+';
                else str[i][j]='-';
            }
            else{
                if(j%4==0) str[i][j]='|';
                else{
                    int x=i/2,y=j/4;
                    if((x+y)%2==0) str[i][j]='.';
                    else str[i][j]=':';
                }
            }
        }
    }
}
void gao(int i,int j,char ch){
    str[15-i*2][j*4+2]=ch;
}
void fuck(int p=0){
    scanf("%s",word);
    word[strlen(word)+1]='\0';word[strlen(word)]=',';
    string s="";
    for(int i=0;i<strlen(word);i++){
        if(word[i]==','){
            if(s.size()==2){
                if(!p) gao(s[1]-'1',s[0]-'a','P');
                else gao(s[1]-'1',s[0]-'a','p');
            }
            else{
                gao(s[2]-'1',s[1]-'a',s[0]+p);
            }
            s="";
        }
        else s+=(char)word[i];
    }
}
int main(){
    //freopen("output.txt","w",stdout);
    init();
    scanf("%s",word);
    if(word[0]=='W') fuck();
    else fuck('a'-'A');
    scanf("%s",word);
    if(word[0]=='W') fuck();
    else fuck('a'-'A');
    for(int i=0;i<17;i++){
        for(int j=0;j<33;j++)
            printf("%c",str[i][j]);
        puts("");
    }
    return 0;
}