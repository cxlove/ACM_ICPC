#include<iostream>
#include<cstdio>
#include<cstring>
#define N 1000005
#define LL long long 
using namespace std;
struct Node{
    int left,right,mid;
    int lsum,rsum;
    int dist(){
        return right-left+1;
    }
}L[N*5];
char s1[N],s2[N];
int n;
void Push_Up(int step){
    L[step].lsum=L[2*step].lsum+(L[2*step].lsum==L[2*step].dist()?L[2*step+1].lsum:0);
    L[step].rsum=L[2*step+1].rsum+(L[2*step+1].rsum==L[2*step+1].dist()?L[2*step].rsum:0);
}
void bulid(int step,int l,int r){
    L[step].left=l;
    L[step].right=r;
    L[step].mid=(l+r)>>1;
    if(l==r){
        L[step].lsum=L[step].rsum=(s1[l]==s2[l]);
        return;
    }
    bulid(step<<1,l,(l+r)>>1);
    bulid(step<<1|1,(l+r)/2+1,r);
    Push_Up(step);
}
void update(int step,int pos,int k){
    if(L[step].left==pos&&L[step].right==pos){
        L[step].rsum=L[step].lsum=k;
        return ;
    }
    if(pos<=L[step].mid)
        update(2*step,pos,k);
    else
        update(2*step+1,pos,k);
    Push_Up(step);
}
int query(int step,int pos){
    if(L[step].left==L[step].right)
        return L[step].rsum;
    if(L[step].rsum>=L[step].right-pos+1)
        return L[step].right-pos+1;
    if(pos>L[step].mid)
        return query(2*step+1,pos);
    if(L[2*step].rsum>=L[2*step].right-pos+1)
        return L[2*step].right-pos+1+L[2*step+1].lsum;
    return query(2*step,pos);
}
int main(){
    int t,cas=0;
    scanf("%d",&t);
    while(t--){
        scanf("%s%s",s1,s2);
        n=min(strlen(s1),strlen(s2))-1;
        bulid(1,0,n);
        int q;
        scanf("%d",&q);
        printf("Case %d:\n",++cas);
        while(q--){
            int kind,pos,idx;
            char ch;
            scanf("%d",&kind);
            if(kind==2){
                scanf("%d",&pos);
                printf("%d\n",query(1,pos));
            }
            else{
                scanf("%d%d %c",&idx,&pos,&ch);
                if(pos>=n)
                    continue;
                if(idx==1){
                    if(s1[pos]==s2[pos]&&s2[pos]==ch);
                    else if(s1[pos]!=s2[pos]&&s2[pos]!=ch)
                        s1[pos]=ch;
                    else{
                        s1[pos]=ch;
                        update(1,pos,s1[pos]==s2[pos]);
                    //    if(s1[pos]==s2[pos])
                    }
                }
                else{
                    if(s1[pos]==s2[pos]&&s1[pos]==ch);
                    else if(s1[pos]!=s2[pos]&&s1[pos]!=ch)
                        s2[pos]=ch;
                    else{
                        s2[pos]=ch;
                    //    bulid(1,0,n);
                        update(1,pos,s1[pos]==s2[pos]);
                    }
                }
            }
        }
    }
    return 0;
}