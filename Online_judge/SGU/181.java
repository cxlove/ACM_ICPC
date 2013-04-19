import java.io.*;
import java.util.*;
import java.math.*;

public class Solution{
  static Scanner cin = new Scanner(System.in);
	public static void main(String args[]){
		int f[]=new int [1005],ans[]=new int [1005];
		Arrays.fill(f, -1);
		int first=cin.nextInt();
		int a=cin.nextInt(),b=cin.nextInt(),c=cin.nextInt();
		int m=cin.nextInt(),k=cin.nextInt();
		if(k==0){
			System.out.println(first);
			return ;
		}
		int t;
		f[first%m]=0;ans[0]=first%m;
		for(t=1;f[ans[t]=(a*ans[t-1]*ans[t-1]+b*ans[t-1]+c)%m]<0;t++){
			f[ans[t]]=t;
		}
		if(k<t) System.out.println(ans[k]);
		else{
			System.out.println(ans[(k-f[ans[t]])%(t-f[ans[t]])+f[ans[t]]]);
		}
	}
}


