
#include <iostream>   
using namespace std;  
#define MAXN 205   
#define INF 2110000000   
#define MIN(x,y) (x<y?x:y)   
int map[MAXN][MAXN];  
int max_flow(int num,int map[][MAXN],int source,int sink)//参数含义   
{  
    int my_queue[MAXN],queue_first,queue_end;//数组做队列     
    int pre[MAXN],min_flow[MAXN];  
    int flow[MAXN][MAXN];   
    int ans=0;   
    memset(flow,0,sizeof(flow));  
    while(1)   
    {  
        queue_first=0;//初始列   
        queue_end=0;  
        my_queue[queue_end++]=source;  
        memset(pre,-1,sizeof(pre));  
        min_flow[source]=INF;  
        pre[source]=-2;   
        while(queue_first<queue_end)//BFS寻路径   
        {  
            int temp=my_queue[queue_first++];//出队列   
            for(int i=0;i<num;i++)//由结点te展   
            {  
                if(pre[i]==-1&&flow[temp][i]<map[temp][i])   
                {     
                    my_queue[queue_end++]=i;//加入队列   
                    pre[i]=temp;//标示父节点   
                    min_flow[i]=MIN(min_flow[temp],(map[temp][i]-flow[temp][i]));//求得ow   
                }  
            }  
            if(pre[sink]!=-1)//sink的父节点   
            {  
                int k=sink;  
                while(pre[k]>=0)  
                {  
                    flow[pre[k]][k]+=min_flow[sink];//将新的入flow   
                    flow[k][pre[k]]=-flow[pre[k]][k];  
                    k=pre[k];  
                }  
                break;  
            }  
        }  
        if(pre[sink]==-1) return ans;//不存在，返回   
        else ans+=min_flow[sink];  
    }     
}  
int main()  
{  
    int m,n;  
    while(cin>>n>>m)  
    {  
        int a,b,cost;  
        memset(map,0,sizeof(map));  
        for(int i=0;i<n;i++)  
        {  
            cin>>a>>b>>cost;  
            map[a-1][b-1]+=cost;  
        }  
        cout<<max_flow(m,map,0,m-1)<<endl;  
    }  
    return 0;  
}  
