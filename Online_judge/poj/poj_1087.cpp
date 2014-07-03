#include<iostream>
#include<string>
#include<cstring>
using namespace std;
struct A{
	string s1,s2;
}a[1000],b[1000];
 string s[1000];
bool mmap[1000][1000];
bool flag[1000];
bool mark[1000][1000],ip[1000][1000];
int pre[1000],l=0;
int n,m,k;
bool dfs(int i){ 
	int j;    
	for(j=1;j<=n;j++)      
		if(!flag[j]&&mmap[i][j])   {           
			flag[j]=true;         
			if(pre[j]==0||dfs(pre[j])){             
				pre[j]=i;                       
				return true;                
			}          
		}          
		return false;
}     
int match() {  
	int i,count=0;   
	memset(pre,0,sizeof(pre));     
	for(i=1;i<=m;i++)   {         
		memset(flag,false,sizeof(flag));      
		if(dfs(i))  count++;      
	}    
	return count;
} 
int search(string ch){
	for(int i=1;i<=n+l;i++)
		if(s[i]==ch)  return i;
	l++;
	s[n+l]=ch;
	return n+l;
}
void dfs(int x,int y){
	mark[x][y]=true;
	ip[x][y]=true;
	for(int i=1;i<=n+l;i++)
		if(mark[y][i]&&!ip[x][i])
			dfs(x,i);
		else
		if(mark[i][x]&&!ip[i][y])
		    dfs(i,y);
	
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	cin>>m;
	for(int i=1;i<=m;i++)
		cin>>a[i].s1>>a[i].s2;
	cin>>k;
	memset(mark,false,sizeof(mark));
    memset(ip,false,sizeof(ip));	
	for(int i=1;i<=k;i++){
		cin>>b[i].s1>>b[i].s2;
		mark[search(b[i].s2)][search(b[i].s1)]=true;
	} 
	for(int i=1;i<=n+l;i++)
	    for(int j=1;j<=n+l;j++)
	        if(mark[i][j]&&!ip[i][j])
	        dfs(i,j);	
	memset(mmap,false,sizeof(mmap));
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			if(a[i].s2==s[j]||mark[search(s[j])][search(a[i].s2)])
				mmap[i][j]=true;
	cout<<m-match()<<endl;
//	system("pause");
	return 0;
}
			




