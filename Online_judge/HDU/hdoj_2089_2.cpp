#include<iostream>
#include<cstring>
using namespace std;
int main()
{
 int n,m;
 bool bs[1000010];
 memset(bs,0,sizeof(bs));
 int temp;
 for(int i=1;i<=1000001;i++)
 {
  int sum=temp=i;
  while(temp>0)
  {
   if(temp % 10 == 4 || temp % 100 == 62)
    bs[sum]=1;
   temp=temp/10;
  }
 }
 while(cin>>n>>m && (n||m))
 {
  int count=m-n+1;
  for(int i=n;i<=m;i++)
  {
   if(bs[i]==1)
    count--;
  }
  cout<<count<<endl;
 }
 return 0;
}
