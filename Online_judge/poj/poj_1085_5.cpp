#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define M 11
int map[M][M]=
{{0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,0,0,0,0,0,0,0},
{0,0,0,2,3,4,0,0,0,0,0},
{0,1,2,0,0,5,6,0,0,0,0},
{0,0,3,0,0,7,0,9,10,0,0},
{0,0,4,5,7,0,8,0,11,12,0},
{0,0,0,6,0,8,0,0,0,13,14},
{0,0,0,0,9,0,0,0,15,0,0},
{0,0,0,0,10,11,0,15,0,16,0},
{0,0,0,0,0,12,13,0,16,0,17},
{0,0,0,0,0,0,0,14,0,17,0}
};
int tri[9]={7,152,52,352,34304,3200,71680,12544,155648};
/*tri[0]=1|(1<<1)|(1<<2);tri[1]=(1<<3)|(1<<4)|(1<<7);tri[2]=(1<<2)|(1<<4)|(1<<5);tri[3]=(1<<5)|(1<<6)|(1<<8);tri[4]=(1<<9)|(1<<10)|(1<<15);tri[5]=(1<<7)|(1<<10)|(1<<11);tri[6]=(1<<11)|(1<<12)|(1<<16);tri[7]=(1<<8)|(1<<12)|(1<<13);tri[8]=(1<<13)|(1<<14)|(1<<17);*/

const int mirror=(1<<18)-1;

int MinSearch(int ,int ,int ,int );
int MaxSearch(int ,int ,int ,int );

int Place(int s,int seg,int &of)
{
	int i;
	int r=s|seg;
	for(i=0;i<9;i++){
		if(((tri[i]&s)!=tri[i])&&((tri[i]&r)==tri[i]))
			of++;
	}
	return r;
}
int MaxSearch(int statu,int alpha,int as,int bs)
{

	int bit,seg;
	int cs,r;
	int max=-1,tmp;
	if(as>=5) return 1;
	if(bs>=5) return -1;
	if(statu==mirror)
		return as>bs?1:-1;

	bit=(~statu)&mirror;

	while(bit){
		seg=bit&(-bit);
		cs=as;
		r=Place(statu,seg,cs);
		if(cs>as)
			tmp=MaxSearch(r,alpha,cs,bs);
		else
			tmp=MinSearch(r,max,cs,bs);

		if(tmp>max) 
			max=tmp;
		if(max>=alpha)
			return max;
		bit-=seg;
	}
	return max;
}
int MinSearch(int statu,int beta,int as,int bs)
{
	int bit,seg,cs,r;
	int min=1,tmp;
	if(as>=5) return 1;
	if(bs>=5) return -1;
	if(statu==mirror)
		return as>bs?1:-1;
	bit=(~statu)&mirror;
	while(bit){
		seg=bit&(-bit);
		cs=bs;
		r=Place(statu,seg,cs);
		if(cs>bs)
			tmp=MinSearch(r,beta,as,cs);
		else
			tmp=MaxSearch(r,min,as,cs);
		if(tmp<min) min=tmp;
		if(tmp<=beta) 
			return min;
		bit-=seg;
	}
	return min;
}

int main()
{
	int t,k=0;
	int a,b,n,i,turn;
	int res;
	int ofa,ofb;
	int ta,tb;
	int status;
	scanf("%d",&t);
	while(t--){

		scanf("%d",&n);

		status=ofa=ofb=0;

		for(turn=i=0;i<n;i++){
			scanf("%d%d",&a,&b);
			ta=ofa,tb=ofb;
			status=Place(status,1<<map[a][b],(turn&1)?ofb:ofa);
			if(ta==ofa&&tb==ofb)
				turn++;
		}
		if(turn&1)
			res=MinSearch(status,-1,ofa,ofb);
		else
			res=MaxSearch(status,1,ofa,ofb);
		printf("Game %d: %c wins.\n",++k,res==1?'A':'B');
	}
	return 0;
}
