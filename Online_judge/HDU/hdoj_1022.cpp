#include<cstdio>
#include<stack>
using namespace std;
int main()
{
    int i,j,k,n,ok,flg[22];
    char in[10],out[10];
    while(scanf("%d",&n)!=EOF)
    {
        scanf("%s%s",in,out);
        stack<int> s;
        i=j=k=0;ok=1;
        while(j<n)
        {
            if(in[i]==out[j])
            {
                flg[k++]=0;flg[k++]=1;i++;j++;
            }
            else if(!s.empty() && s.top()==(out[j]-'0'))
            {
                flg[k++]=1;s.pop();j++;
            }
            else if(i<n)
            {
                s.push(in[i++]-'0');flg[k++]=0;
            }
            else 
            {
                ok=0;break;
            }
        }
        if(ok==0)printf("No.\n");
        else
        {
            printf("Yes.\n");
            for(i=0;i<k;i++)
            {
                if(flg[i]==0)printf("in\n");
                else printf("out\n");
            }
        }
        printf("FINISH\n");
    }
    return 0;
}