import java.io.*;
import java.util.*;
import java.math.*;

public class Solution{
  static Scanner cin = new Scanner(System.in);
	public static void main(String args[]){
		int p=cin.nextInt();
		int m=cin.nextInt();
		int c=cin.nextInt();
		int k=cin.nextInt();
		int r=cin.nextInt();
		int v=cin.nextInt();
		System.out.println(Math.min(p/k,Math.min(m/r,c/v)));
	}
}


