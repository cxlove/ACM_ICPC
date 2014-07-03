import java.util.*;
import java.math.*;
public class Main
{
    public static void main(String[] args)
    {
        Scanner cin = new Scanner(System.in);
        BigInteger []f=new BigInteger[1000];
        f[0]=BigInteger.ONE;f[1]=BigInteger.ONE;
        BigInteger mmax=BigInteger.TEN.pow(100);
        int n=1;
        for(int i=2;;i++)
        {
            f[i]=f[i-1].add(f[i-2]);n=i;
            if(f[i].compareTo(mmax)>0) break;
            
        }
        while(cin.hasNext())
        {
            BigInteger l=cin.nextBigInteger();
            BigInteger r=cin.nextBigInteger();
            if(l.compareTo(BigInteger.ZERO)==0&&r.compareTo(BigInteger.ZERO)==0) break;
            int ans=0;
            for(int i=1;i<n;i++)
            {
                if(r.compareTo(f[i])>=0&&f[i].compareTo(l)>=0) ans++;
            }
            System.out.println(ans);
        }
    }
}
