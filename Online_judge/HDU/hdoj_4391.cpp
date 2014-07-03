#include <stdio.h>
 #include <math.h>
 #include <string.h>
 #include <map>
 #define MAXN 100005
 int n,m,bsize,bnum,x[MAXN];
 struct hash_block{
      int cls,size;
      std::map<int,int> mp;
 }b[350];
 //下传标记,当这个块化整为零的时候需要下传标记并跟新所有元素
 void pushdown(int id){
     hash_block &hb=b[id];
     if(hb.cls!=-1){
         for(int i=id*bsize;i<id*bsize+hb.size;i++)x[i]=hb.cls;
         hb.mp.clear(),hb.mp[hb.cls]=hb.size;
         hb.cls=-1;
     }
 }
 //跟新,中间的部分打标记就可以了,两边的sqrt(n)暴力跟新
 void update(int l,int r,int c){
     int lb=l/bsize,rb=r/bsize,ans=0;
     for(int i=lb+1;i<rb;i++)b[i].cls=c;
     if(lb!=rb){
         pushdown(lb);pushdown(rb);
         for(int i=l;i<lb*bsize+b[lb].size;i++)
             b[lb].mp[x[i]]--,b[lb].mp[c]++,x[i]=c;
         for(int i=rb*bsize;i<=r;i++)
             b[rb].mp[x[i]]--,b[rb].mp[c]++,x[i]=c;
     }else{
     pushdown(lb);
     for(int i=l;i<=r;i++)
         b[lb].mp[x[i]]--,b[lb].mp[c]++,x[i]=c;
     }
 }
 //中间的部分根据标记或者hash表可以直接查询,两边的sqrt(n)暴力查询
 int query(int l,int r,int c){
     int lb=l/bsize,rb=r/bsize,ans=0;
     for(int i=lb+1;i<rb;i++){
         //一直错在这个地方了,如果有标记,直接判断标记是不是需要的颜色
         //如果没标记,要先判map中有没有这个元素然后在操作,否则会MLE!
         if(b[i].cls==c)ans+=b[i].size;
         else if(b[i].cls==-1&&b[i].mp.find(c)!=b[i].mp.end())ans+=b[i].mp[c];
     }
     if(lb!=rb){
         pushdown(lb);pushdown(rb);
         for(int i=l;i<lb*bsize+b[lb].size;i++)ans+=(x[i]==c);
         for(int i=rb*bsize;i<=r;i++)ans+=(x[i]==c);
     }else{
         pushdown(lb);
         for(int i=l;i<=r;i++)ans+=(x[i]==c);
     }
     return ans;
 }
 void initblock(){
     bsize=(int)sqrt(n+1e-8);
     bnum=(n-1)/bsize+1;
     for(int i=0;i<bnum;i++){
         b[i].mp.clear();
         b[i].cls=-1;
         b[i].size=std::min(i*bsize+bsize,n)-i*bsize;
     }
     for(int i=0;i<n;i++){
         scanf("%d",&x[i]);
         b[i/bsize].mp[x[i]]++;
     }
 }
 int q,l,r,z;
 int main(){
     //freopen("test.in","r",stdin);
     while(scanf("%d%d",&n,&m)!=EOF){
         initblock();
         while(m--){
             scanf("%d%d%d%d",&q,&l,&r,&z);
             if(q==1)update(l,r,z);
             else printf("%d\n",query(l,r,z));
         }
     }
     return 0;
 }