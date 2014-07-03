#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct line{
	int left,right,mid,lx,rx,val;
	bool flag(){return val==(right-left+1);};
}L[160000];
void bulid(int step,int l,int r)
{
	L[step].left=l;
	L[step].right=r;
	L[step].mid=(l+r)/2;
	L[step].val=L[step].rx=L[step].lx=(r-l+1);
	if(l==r)
		return;
	bulid(2*step,l,(l+r)/2);
	bulid(2*step+1,(l+r)/2+1,r);
}
void update(int step,int a,int mark)
{
	if(L[step].left==L[step].right)
	{
		L[step].val=L[step].rx=L[step].lx=(mark==1?0:1);
		return ;
	}
	if(a<= L[step].mid) update( 2*step,a,mark );   
	else update(2*step+1,a,mark );
	L[step].val=max(L[2*step].rx + L[2*step+1].lx, max(L[step*2].val,L[2*step+1].val ));
	L[step].lx=L[2*step].lx+(L[2*step].flag()?L[2*step+1].lx:0);    
    L[step].rx=L[2*step+1].rx+(L[2*step+1].flag()?L[2*step].rx:0);  
}
int query(int step,int a)
{
	if(L[step].flag()||L[step].val==0||L[step].left==L[step].right)
		return L[step].val;
	if ( a <=L[step].mid ) {
         if ( a>L[step].mid-L[2*step].rx )  
             return L[2*step].rx + query(2*step+1, L[step].mid+1); 
         else return query ( 2*step,a  );    
    } else {
         if ( a <=L[step].mid + L[2*step+1].lx )  
             return L[2*step+1].lx +query(2*step,L[step].mid );
         else return query ( 2*step+1,a  );   
    }
}
int main()
{
	int n,m;
	int des[160000];
	int top;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		char ch[5];
		int k;
		top=-1;
		bulid(1,1,n);
		while(m--)
		{
			scanf("%s",ch);
			switch(ch[0])
			{
			case 'D':
				{
					scanf("%d",&k);
					update(1,k,1);
					des[++top]=k;
					break;
				}
			case 'R':
				{
					if(top<0)
						break;
					update(1,des[top],0);
					top--;
					break;
				}
			case 'Q':
				{
					scanf("%d",&k);
					printf("%d\n",query(1,k));
					break;
				}
			}
		}
	}
	return 0;
}


