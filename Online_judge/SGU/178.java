import java.io.*;
import java.util.*;
import java.math.*;

public class Solution{
  static Scanner cin = new Scanner(System.in);
	static boolean check(long n,int cnt){
		if(n==1) return true;
		long s=cnt;
		for(int i=1;i<=cnt;i++){
			if((s=(s+s+1))+s+1>=n)
				return true;
		}
		return false;
	}
	public static void main(String args[]){
		long n=cin.nextLong();
		int low=0,high=55,mid,ans=0;
		while(low<=high){
			mid=(low+high)/2;
			if(check(n,mid)){
				ans=mid;
				high=mid-1;
			}
			else low=mid+1;
		}
		System.out.println(ans);
	}
}


