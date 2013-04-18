
By cxlove, contest: Croc Champ 2013 - Qualification Round, problem: (E) Tree String Problem, Accepted, #
 import java.io.*;
import java.util.*;
import java.math.*;

public class Main{
    static Scanner cin = new Scanner(System.in);
    static Vector edge[]=new Vector[100005];
    static String s[]=new String[100005];
    static String word;
    static int fail[]=new int[100005];
    static int ret=0;
    public static void dfs(int u,int now){
        for(int k=0;k<edge[u].size();k++){
            int v=(int) edge[u].elementAt(k);
            String str=s[v];
            int i,j;
            for(i=now,j=0;i<word.length()&&j<str.length();){
                if(i==-1||word.charAt(i)==str.charAt(j)){
                    i++;j++;
                }
                else i=fail[i];
                if(i==word.length()){
                    ret++;
                    i=fail[i];
                }
            }
            dfs(v,i);
        }
    }
    public static void main(String[] args){
        int n=cin.nextInt();
        for(int i=1;i<=n;i++)
            edge[i]=new Vector();
        for(int i=2;i<=n;i++){
            int p=cin.nextInt();
            edge[p].addElement(i);
            s[i]=cin.next();
        }
        word=cin.next();
        fail[0]=-1;
        for(int i=0,j=-1;i<word.length();){
            if(j==-1||(word.charAt(i)==word.charAt(j))){
                i++;j++;
                fail[i]=j;
            }
            else j=fail[j];
        }
        dfs(1,0);
        System.out.println(ret);
    }
}