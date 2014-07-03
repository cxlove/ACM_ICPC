#include <cstdio>
using namespace std;
int main()
{
    int next[200],queue[200][200],qlenth[200],N,k,j,i;
    char datas[500],ans[500];
    for (scanf("%d",&N);N;scanf("%d",&N)){
        for (i=0;i<N;i++)scanf("%d",next+i);
        for (i=0;i<N;i++)next[i]--;
        for (i=0;i<N;i++){
            j=i;queue[i][0]=j;qlenth[i]=1;
            for (j=next[j];j!=i;j=next[j])
                queue[i][qlenth[i]++]=j;
        }
        for (scanf("%d",&k);k;scanf("%d",&k)){
            getchar();
            gets(datas);
            for (i=0;datas[i] && datas[i]!=10;i++);
            for (;i<N;i++)datas[i]=' ';
            for (i=0;i<N;i++)ans[queue[i][k%qlenth[i]]]=datas[i];
            ans[N]=0;
            puts(ans);
        }
        printf("\n");
    }
    return 0;
}