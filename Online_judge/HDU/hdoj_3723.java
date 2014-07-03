import java.util.*;
import java.math.*;
public class Main
{
    public static void main(String[] args)
    {
        Scanner cin = new Scanner(System.in);
        while(cin.hasNext())
        {
            int n;
            n=cin.nextInt();
            BigInteger ans=BigInteger.ONE;
            BigInteger tmp=BigInteger.ONE;
            for(int i=0;i<n/2;i++)
            {
                tmp=tmp.multiply(BigInteger.valueOf(n-2*i)).multiply(BigInteger.valueOf(n-2*i-1)).divide(BigInteger.valueOf(i+1)).divide(BigInteger.valueOf(i+2));
                ans=ans.add(tmp);
            }
            ans=ans.mod(BigInteger.TEN.pow(100));
            System.out.println(ans);
        }
    }
}
