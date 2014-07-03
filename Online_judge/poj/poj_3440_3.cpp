#include<iostream>
#include<math.h>
using namespace std;
#define PI 3.141592653

int main()
{
    int num,i;
    double m,n,t,c;
    double pro1,pro2,pro3,pro4;
    cin>>num;
    for(i=1;i<=num;i++)
    {
        cin>>m>>n>>t>>c;
        double sq=m*n*t*t;
        pro2=(m-1)*n*t*c+(n-1)*m*t*c-2*(m-1)*(n-1)*c*c;
        pro2=pro2/sq;

        pro3=(m-1)*(n-1)*c*c*(1-PI/4);
        pro3=pro3/sq;

        pro4=(m-1)*(n-1)*c*c*PI/4;
        pro4=pro4/sq;
        
        pro1=1-(pro2+pro3+pro4);

        cout<<"Case "<<i<<":"<<endl;
        cout.setf(ios::fixed);
        cout.precision(4);
        cout<<"Probability of covering 1 tile  = "<<pro1*100<<"%"<<endl;
        cout<<"Probability of covering 2 tiles = "<<pro2*100<<"%"<<endl;
        cout<<"Probability of covering 3 tiles = "<<pro3*100<<"%"<<endl;
        cout<<"Probability of covering 4 tiles = "<<pro4*100<<"%"<<endl;

        if(i!=num)
            cout<<endl;
    }
    return 0;
}