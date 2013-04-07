
class TheNumberGameDivOne
{
    public:
    string find(long long n)
    {
        int cnt=0;
        if(n&1) return "Brus";
        while(n%2==0){
        	cnt++;
        	n/=2;
        }
        if(n==1&&cnt&1) return "Brus";
        else return "John";
    }
}; 