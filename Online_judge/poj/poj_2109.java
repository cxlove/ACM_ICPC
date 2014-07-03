import java.util.*;
import java.math.*;
import java.io.*;
public class Main{
	static Scanner cin = new Scanner (System.in);
	public static void main(String args[]){
		while(cin.hasNext()){
			int n=cin.nextInt();
			BigInteger p=cin.nextBigInteger();
			BigInteger ans=BigInteger.ONE,low=BigInteger.ONE,high=BigInteger.valueOf(1000000000),mid;
			while(low.compareTo(high)<=0){
				mid=low.add(high).divide(BigInteger.valueOf(2));
				BigInteger tmp=mid.pow(n);
				if(tmp.equals(p)){
					ans=mid;
					break;
				}
				else if(tmp.compareTo(p)>0){
					ans=mid;
					high=mid.subtract(BigInteger.ONE);
				}
				else{
					ans=mid;
					low=mid.add(BigInteger.ONE);
				}
			}
			System.out.println(ans);
		}
	}
}