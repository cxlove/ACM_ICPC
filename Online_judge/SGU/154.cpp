import java.io.*;
import java.util.*;
import java.math.*;

public class Solution{
  static Scanner cin = new Scanner(System.in);
	
	public static void main(String args[]){
		BigInteger n=cin.nextBigInteger();
		BigInteger low=BigInteger.ONE,high=BigInteger.valueOf(1000000000000000l),mid,ans=BigInteger.valueOf(-1);
		while(low.compareTo(high)<=0){
			mid=low.add(high).divide(BigInteger.valueOf(2));
			BigInteger temp=BigInteger.ZERO,t=mid;
			while(t!=BigInteger.ZERO){
				t=t.divide(BigInteger.valueOf(5));
				temp=temp.add(t);
			}
			if(temp.compareTo(n)==0){
				ans=mid;
				high=mid.subtract(BigInteger.ONE);
			}
			else if(temp.compareTo(n)>0){
				high=mid.subtract(BigInteger.ONE);
			}
			else
				low=mid.add(BigInteger.ONE);
		}
		if(ans.equals(BigInteger.valueOf(-1)))
				System.out.println("No solution");
		else	System.out.println(ans);
	}
}


