#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int a[1005],b[1005],c[1005];
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(a[i]==b[j])
			{
				c[i]=j;
			    break;
			}
	int ans=0;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(c[i]<c[j])
				ans++;
		}
	}
	cout<<ans<<endl;
//	system("pause");
	return 0;
}