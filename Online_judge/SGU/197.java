import java.io.*;
import java.util.*;
import java.math.*;
class Matrix{
  int a[][]=new int [1<<5][1<<5];
	Matrix(){
		for(int i=0;i<(1<<5);i++)
			for(int j=0;j<(1<<5);j++)
				a[i][j]=(i==j?1:0);
	}
	void debug(int m){
		for(int i=0;i<(1<<m);i++){
			for(int j=0;j<(1<<m);j++)
				System.out.print(a[i][j]);
			System.out.println();
		}
	}
	Matrix(int f){
		for(int i=0;i<(1<<5);i++)
			for(int j=0;j<(1<<5);j++)
				a[i][j]=0;
	}
	Matrix mult(Matrix m1,Matrix m2,int m,int p){
		Matrix ret=new Matrix(1);
		for(int i=0;i<(1<<m);i++){
			for(int j=0;j<(1<<m);j++){
				for(int k=0;k<(1<<m);k++){
					ret.a[i][j]=(ret.a[i][j]+m1.a[i][k]*m2.a[k][j])%p;
				}
			}
		}
		return ret;
	}
	Matrix pow(BigInteger n,int m,int p){
		Matrix ret=new Matrix();
		Matrix tmp=this;
		while(!n.equals(BigInteger.ZERO)){
			if(n.mod(BigInteger.valueOf(2)).equals(BigInteger.ONE)){
				ret=mult(ret,tmp,m,p);
			}				
			tmp=mult(tmp,tmp,m,p);
			n=n.divide(BigInteger.valueOf(2));
		}
		return ret;
	}
}
public class Solution{
	static Scanner cin = new Scanner(System.in);
	public static int check(int a,int b,int m){
		for(int i=1,t=3;i<m;t<<=1,i++){
			if((a&t)==t&&(b&t)==t)
				return 0;
			if((a&t)==0&&(b&t)==0)
				return 0;
		}
		return 1;
	}
	public static void main(String[] args)
	{
		BigInteger n;
		int m,p;
		n=cin.nextBigInteger();
		m=cin.nextInt();p=cin.nextInt();
		Matrix init=new Matrix(1);
		for(int i=0;i<(1<<m);i++){
			for(int j=0;j<(1<<m);j++){
				init.a[i][j]=check(i,j,m);
			}
		}
		Matrix ret=new Matrix();
		ret=init.pow(n.subtract(BigInteger.ONE), m, p);
		int ans=0;
		for(int i=0;i<(1<<m);i++)
			for(int j=0;j<(1<<m);j++)
				ans=(ans+ret.a[i][j])%p;
		System.out.println(ans);		
	}
}


