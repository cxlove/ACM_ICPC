#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int l,n,m;
	int a[50005];
	cin>>l>>n>>m;
	int r;
	a[0]=0;a[n+1]=l;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a,a+n+2);
	int low=l,high=l,mid;
	for(int i=1;i<=n+1;i++)
		if(a[i]-a[i-1]<low)
			low=a[i]-a[i-1];
	while(low<high)
	{
		int count=0;
		int b=0;
		mid=(low+high)/2;
		for(int i=1;i<=n+1;i++)
		{
			if(a[i]-a[b]<mid)
				count++;
			else
				b=i;
		}
		if(count<=m)
		{
			if(low!=mid)
				low=mid;
			else
				break;
		}
		else
			high=mid;
	}
	cout<<low<<endl;
	//system("pause");
	return 0;
}


