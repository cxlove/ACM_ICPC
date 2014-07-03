#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<vector>
#define C    240
#define TIME 10
#define inf 1<<25
#define LL long long
using namespace std;
int c[30][30]={0};
void Init(){
    for(int i=0;i<=26;i++){
        c[i][0]=c[i][i]=1;
        for(int j=1;j<i;j++)
            c[i][j]=c[i-1][j]+c[i-1][j-1];
    }
}
char str[20];
int main(){
    Init();
    while(scanf("%s",str)!=EOF){
        int len=strlen(str),j;
        for(j=0;j<len-1;j++)
			if(str[j]>=str[j+1])
				break;
		if(j<len-1){
			printf("0\n");
			continue;
		}
        LL sum=0;
        for(int i=1;i<len;i++)
            sum+=c[26][i];
        for(int i=0;i<len;i++){
            char ch=i==0?'a':(str[i-1]+1);
            for(char j=ch;j<str[i];j++)
                 sum+=c['z'-j][len-1-i];
        }
        printf("%I64d\n",sum+1);
    }
    return 0;
}


