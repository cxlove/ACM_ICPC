#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>



#include <set>

#define         MAX_SIZE        200037
#define         P_A                0
#define         P_B                1

using namespace std;

class Card{
public:
    void setValue(int _h,int _w,int _b){
        h=_h;
        w=_w;
        b=_b;
    }
    int h;
    int w;
    int b;
} cs[MAX_SIZE];

int N;

multiset<int> myMs;

int comp(Card l,Card r){
    if(l.h==r.h){
        if(l.w==r.w){
            return l.b<r.b;
        }
        else
            return l.w>r.w;
    }
    return l.h>r.h;
}
int T;

int main()
{
    scanf("%d",&T);
    multiset<int>::iterator iter;
    int tmph,tmpw;
    int sum;

    while(T--)
    {
        scanf("%d",&N);
        myMs.clear();
        sum=0;
        for(int i=0;i<N;++i)
        {
            scanf("%d%d",&tmph,&tmpw);
            cs[i].setValue(tmph,tmpw,P_A);
        }
        for(int i=0;i<N;++i)
        {
            scanf("%d%d",&tmph,&tmpw);
            cs[i+N].setValue(tmph,tmpw,P_B);
        }
        sort(cs,cs+N+N,comp);
        for(int i=0;i<N+N;++i)
        {
            if(cs[i].b==P_A)
                myMs.insert(cs[i].w);
            else
            {
                iter=myMs.lower_bound(cs[i].w);
                if(iter!=myMs.end())
                {
                    ++sum;
                    myMs.erase(iter);
                }
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}