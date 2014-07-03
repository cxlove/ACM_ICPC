#include<iostream>
#include<cstring>
using namespace std;
struct node
{
	int a,b,c;
}d[25010];
int main()
{
	int n;
	bool m[64][64][64];
	memset(m,false,sizeof(m));
	cin>>n;
	d[1].a=32;
	d[1].b=32;
	d[1].c=0;
	m[32][32][0]=true;
	int j;char ch;
	int x,y,z;
	int area=5,i;
	for( i=2;i<=n;i++)
	{
		cin>>j>>ch;
		x=d[j].a;;
		z=d[j].c;
		y=d[j].b;
		switch(ch)
		{
		case 'L':y--;break;
		case 'R':y++;break;
		case 'F':x++;break;
		case 'B':x--;break;
		case 'O':z++;break;
		case 'U':z--;break;
		}
		if(z<0)
			break;
		if(m[x][y][z])
			break;
		m[x][y][z]=true;
		d[i].a=x;
		d[i].b=y;
		d[i].c=z;
		area+=6;
		if(m[x][y][z+1])
			area-=2;
		if(m[x+1][y][z])
			area-=2;
		if(m[x-1][y][z])
			area-=2;
		if(m[x][y+1][z])
			area-=2;
		if(m[x][y-1][z])
			area-=2;
		if(z==0)
			area-=1;
		else
			if(m[x][y][z-1])
				area-=2;
	}
	cout<<(i==n+1?area:-1)<<endl;
	//system("pause");
	return 0;
}








