#include<iostream>
#include<algorithm>
using namespace std;

//不同种类的面值，先前最佳可行解，当前解
int kind[100],pre[4],cur[4];
//种类，需求，先前已存在最佳解的种类数、张数、单张最大面值
int types,need,PreKind,PreNum,PreVal;
//最佳方案的个数
int TieNum;

//当前可以购买的种类，上次购买的种类，当前购买的种类数、张数、单张最大面值
void DFS(int k,int LastGetKind,int CurKind,int CurNum,int CurVal,int cost)
{
	if(CurNum>4 || (CurNum==4 && cost!=need)) return ;
	if(cost==need) //可行方案
	{
		if( (PreKind==0) || /*1.先前没有可行解*/
			(CurKind>PreKind) ||  /*2.种类多*/
			(CurKind==PreKind && CurNum<PreNum) || /*3.张数少*/
			(CurKind==PreKind && CurNum==PreNum && CurVal>PreVal)) /*4.面值大*/
		{
			PreKind=CurKind;
			PreNum=CurNum;
			PreVal=CurVal;
			for(int i=0;i<CurNum;i++)
				pre[i]=cur[i];
			TieNum=1;
		}
		else if(CurKind==PreKind && CurNum==PreNum && CurVal==PreVal) //存在多种最佳方案
			TieNum++;
		return ;
	}
	for(int i=k;i<types;i++)
	{
		if(cost+kind[i]>need) break;
		int KIND=CurKind,VAL=CurVal;
		if(LastGetKind!=i) KIND=CurKind+1;
		if(CurVal<kind[i]) VAL=kind[i];
		cur[CurNum]=kind[i];
		DFS(i,i,KIND,CurNum+1,VAL,cost+kind[i]);
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(scanf("%d",&kind[0])!=EOF)
	{
		types=0;
		while(kind[types]!=0)
			scanf("%d",&kind[++types]);
		//===============================
		//for(int i=0;i<types;i++)
		//	printf("%d ",kind[i]);
		//printf("\n");
		//===============================
		//按面值从小到大排序
		sort(kind,kind+types);
		while(scanf("%d",&need) && need)
		{
			PreKind=PreNum=PreVal=0;
			TieNum=1;
			DFS(0,-1,0,0,0,0);
			if(PreKind==0)
				printf("%d ---- none\n",need);
			else if(TieNum>1)
				printf("%d (%d): tie\n",need,PreKind);
			else
			{
				printf("%d (%d): ",need,PreKind);
				for(int i=0;i<PreNum-1;i++)
					printf("%d ",pre[i]);
				printf("%d\n",pre[PreNum-1]);
			}
		}
	}
	return 0;
}
