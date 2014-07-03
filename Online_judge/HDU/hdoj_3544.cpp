#include<iostream>
using namespace std;
int main()
{
    int t,n,cas=1;
    long long a,b,x,y;
    cin>>t;
    while(t--)
    {
        cin>>n;
        a=b=0;
        for(int i=0;i<n;i++)
        {
            cin>>x>>y;
            while(1)
            {
                if(x==1)
                {
                    b+=y-1;break;
                }
                if(y==1)
                {
                    a+=x-1;break;
                }
                a++,b++;
                x=x>>1;
                y=y>>1;
            }
        }
        cout<<"Case "<<cas++<<": ";
        if(a>b) cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }
    return 0;
}    