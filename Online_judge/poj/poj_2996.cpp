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
vector<pair<char,int> >wk,wq,wr,wb,wn,wp,bk,bq,br,bb,bn,bp;
bool cmp1(pair<char,int> a,pair<char,int> b){
    return a.second!=b.second?a.second<b.second:a.first<b.first;
}
bool cmp2(pair<char,int> a,pair<char,int> b){
    return a.second!=b.second?a.second>b.second:a.first<b.first;
}
int main(){
    for(int i=0;i<17;i++)
        scanf("%s",str[i]);
    for(int i=1;i<8;i+=2)
        swap(str[i],str[16-i]);
    for(int i=1;i<17;i+=2){
        for(int j=2;j<33;j+=4){
            if(str[i][j]=='r')
                wr.pb(mp((char)j/4+'a',i/2+1));
            else if(str[i][j]=='b')
                wb.pb(mp((char)j/4+'a',i/2+1));
            else if(str[i][j]=='k')
                wk.pb(mp((char)j/4+'a',i/2+1));
            else if(str[i][j]=='q')
                wq.pb(mp((char)j/4+'a',i/2+1));
            else if(str[i][j]=='p')
                wp.pb(mp((char)j/4+'a',i/2+1));
            else if(str[i][j]=='n')
                wn.pb(mp((char)j/4+'a',i/2+1));
            else if(str[i][j]=='R')
                br.pb(mp((char)j/4+'a',i/2+1));
            else if(str[i][j]=='B')
                bb.pb(mp((char)j/4+'a',i/2+1));
            else if(str[i][j]=='K')
                bk.pb(mp((char)j/4+'a',i/2+1));
            else if(str[i][j]=='Q')
                bq.pb(mp((char)j/4+'a',i/2+1));
            else if(str[i][j]=='P')
                bp.pb(mp((char)j/4+'a',i/2+1));
            else if(str[i][j]=='N')
                bn.pb(mp((char)j/4+'a',i/2+1));
        }
    }
    printf("White:");
    int cnt=0;
    for(int i=0;i<bk.size();i++,cnt++)
        printf("%cK%c%d",cnt==0?' ':',',bk[i].first,bk[i].second);
    for(int i=0;i<bq.size();i++,cnt++)
        printf("%cQ%c%d",cnt==0?' ':',',bq[i].first,bq[i].second);
    for(int i=0;i<br.size();i++,cnt++)
        printf("%cR%c%d",cnt==0?' ':',',br[i].first,br[i].second);
    for(int i=0;i<bb.size();i++,cnt++)
        printf("%cB%c%d",cnt==0?' ':',',bb[i].first,bb[i].second);
    for(int i=0;i<bn.size();i++,cnt++)
        printf("%cN%c%d",cnt==0?' ':',',bn[i].first,bn[i].second);
    for(int i=0;i<bp.size();i++,cnt++)
        printf("%c%c%d",cnt==0?' ':',',bp[i].first,bp[i].second);
    printf("\nBlack:");
    cnt=0;
    sort(wk.begin(),wk.end(),cmp2);
    sort(wb.begin(),wb.end(),cmp2);
    sort(wn.begin(),wn.end(),cmp2);
    sort(wq.begin(),wq.end(),cmp2);
    sort(wp.begin(),wp.end(),cmp2);
    for(int i=0;i<wk.size();i++,cnt++)
        printf("%cK%c%d",cnt==0?' ':',',wk[i].first,wk[i].second);
    for(int i=0;i<wq.size();i++,cnt++)
        printf("%cQ%c%d",cnt==0?' ':',',wq[i].first,wq[i].second);
    for(int i=0;i<wr.size();i++,cnt++)
        printf("%cR%c%d",cnt==0?' ':',',wr[i].first,wr[i].second);
    for(int i=0;i<wb.size();i++,cnt++)
        printf("%cB%c%d",cnt==0?' ':',',wb[i].first,wb[i].second);
    for(int i=0;i<wn.size();i++,cnt++)
        printf("%cN%c%d",cnt==0?' ':',',wn[i].first,wn[i].second);
    for(int i=0;i<wp.size();i++,cnt++)
        printf("%c%c%d",cnt==0?' ':',',wp[i].first,wp[i].second);
    puts("");
    return 0;
}