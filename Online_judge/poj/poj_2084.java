import java.util.*;
import java.math.*;
public class Main{
    public static void main(String[] args) 
    {
        int n;
        Scanner in=new Scanner(System.in);
        BigInteger one=BigInteger.ONE;
        BigInteger four=new BigInteger("4");
        BigInteger two=new BigInteger("2");
        BigInteger st=null;
        BigInteger t=null;
        while(in.hasNextInt())
        {
            n=in.nextInt();
            if(n==-1)break;
            t=BigInteger.ONE;
            for(int i=2;i<=n;i++)
            {
                st=new BigInteger(""+i);
                /*h(n)=((4*n-2)/(n+1))*h(n-1); n>=2&&h(1)=1,h(0)=1*/
                t=t.multiply(st.multiply(four).subtract(two)).divide(st.add(one));
            }
            System.out.println(t);
        }
    }
}