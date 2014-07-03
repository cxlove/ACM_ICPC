#include<cstdio>  
#include<algorithm>  
#include<set>  
#define INF 1e18  
using namespace std;  
int n;  
struct monk  
{  
    int id,grade;  
    bool operator <(const monk& b)const//递增排序  
    {  
        return grade<b.grade;  
    }  
};  
typedef set<monk>::iterator SetIt;  
  
set<monk> se;  
inline int fabs(int x){return x>0?x:-x;}  
monk choose(monk a,monk now,monk b)//如果有2个可能的选择的话，怎样去选的子函数  
{  
    int aa=fabs(a.grade-now.grade);  
    int bb=fabs(now.grade-b.grade);  
    if(aa>bb) return b;  
    if(aa<bb) return a;  
    if(a.grade<now.grade)  
        return a;  
    return b;  
}  
void deal()  
{  
    se.clear();  
    monk now,ans;  
    now.id=1;now.grade=100000000;  
    se.insert(now);//插入第一个点  
    for(int i=1;i<=n;i++)  
    {  
        scanf("%d%d",&now.id,&now.grade);  
        SetIt it=se.lower_bound(now),left;//二分查找，找到的是大于等于now.grade的和尚  
        if(it!=se.begin())//如果找到的不是最小的，那么可能有2个选择的可能，另外因为新来的不可能是最大的  
        {  
             left=it;left--;  
             ans=choose(*left,now,*it);  
         }  
        else  ans=*it;//找到的是最小的的时候，就可以确定答案了  
        printf("%d %d\n",now.id,ans.id);  
        se.insert(now);// 插入  
    }  
}  
int main()  
{  
    while(scanf("%d",&n),n) deal();  
    return 0;  
}  