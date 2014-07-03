#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int n,m,path[500][500],i,j,num[501],r,k;
	memset(path,-1,sizeof(path));
	cin>>n>>m;
    for(i=0;i<n;i++)
		path[i][i]=0;
	for(i=0;i<m;i++){
		cin>>r;
		for(j=0;j<r;j++) 
			cin>>num[j]; 
		for(j=0;j<r;j++)  
			for(k=j+1;k<r;k++)  {
				path[num[j]][num[k]]=1;
				path[num[k]][num[j]]=1;   
			} 
	}
	for(i=1;i<=n;i++) 
		for(j=1;j<=n;j++)   
			for(k=1;k<=n;k++)   	    				   
				if(path[j][i]!=-1&&path[i][k]!=-1&&(path[j][k]==-1||path[j][k]>path[j][i]+path[i][k]))      
					path[j][k]=path[j][i]+path[i][k];
	int mmin=2100000000,sum;
	for(i=1;i<=n;i++){ 
		sum=0; 
		for(j=1;j<=n;j++)	{  
			sum+=path[i][j];
			if(path[i][j]==-1)break;
  
		}   
		
		if(mmin>sum)mmin=sum;
	}
	double ss=double(mmin)/(n-1);
	ss*=100;
	cout<<int(ss)<<endl;
//	system("pause");
	return 0;
}

