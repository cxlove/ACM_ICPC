import java.io.*;
import java.util.*;
import java.math.*;

public class Solution{
  static Scanner cin = new Scanner(System.in);
	public static void main(String args[]){
		BigInteger n=cin.nextBigInteger();
		if(n.mod(BigInteger.valueOf(2)).equals(BigInteger.ONE))
			System.out.println(n.divide(BigInteger.valueOf(2)));
		else{
			BigInteger m=n.divide(BigInteger.valueOf(2));
			if(m.mod(BigInteger.valueOf(2)).equals(BigInteger.ONE))
				System.out.println(m.subtract(BigInteger.valueOf(2)));
			else
				System.out.println(m.subtract(BigInteger.ONE));
		}
	}
}


