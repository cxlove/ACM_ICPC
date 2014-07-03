import java.util.*;
import java.io.*;
import java.math.*;
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		int t = 1;
		Task solver = new Task();
		while ((t --) > 0)
			solver.solve(in, out);
		out.close();
	}
}
class Task{
	static int N = 100005;
	static int S = 30;
	Vector ans = new Vector(); 
	int next[] = new int [N];
	int rank[] = new int [N];
	int a[] = new int [N];
	int r[] = new int [N];
	int less[] = new int [N] , nonbig [] = new int [N];
	int lowbit (int x) {
		return x & (-x);
	}
	void add (int x , int val) {
		if (x == 0) return ;
		for (int i = x ; i < N ; i += lowbit(i)){
			r[i] += val;
		}
	}
	int sum (int x) {
		int ret = 0;
		for (int i = x ; i > 0 ; i -= lowbit(i)) {
			ret += r[i];
		}
		return ret;
	}
	void get_next (int s[] , int l) {
	    next[0] = -1;
	    int i = 0 , j = -1;
	    while (i < l) {
	        if (j == -1 || (sum(s[i]) == nonbig[j] && sum(s[i] - 1) == less[j])) {
	            i ++ ; j ++ ;
	            next[i] = j;
	            if (i == l) return ;
	            add (s[i] , 1);
	        }
	        else {
	        	for (int k = i - j ; k < i - next[j] ; k ++)
	        		add (s[k] , -1);
	        	j = next[j];
	        }
	    }
	}
	void kmp (int a[] , int ls , int p[] , int lp) {
		int i = 0 , j = 0 ;
		add (a[0] , 1);
		while (i < ls && j < lp) {
			if (j == -1 || (sum(a[i]) == nonbig[j] && sum(a[i] - 1) == less[j])) {
				i ++ ; j ++ ;
				add (a[i] , 1);
			}
			else {
				for (int k = i - j ; k < i - next[j] ; k ++)
					add (a[k] , -1);
				j = next[j];
			}
			if (j == lp) {
				ans.add(i - lp + 1);
				for (int k = i - j ; k < i - next[j] ; k ++)
					add (a[k] , -1);
				j = next[j];
			}
		}
	}
	void solve (InputReader cin , PrintWriter cout) {
		int n = cin.nextInt() , k = cin.nextInt() , s=cin.nextInt();
		for (int i = 0 ; i < n ; i ++)
			a[i] = cin.nextInt();
		Arrays.fill(r, 0);
		for (int i = 0 ; i < k ; i ++){
			rank[i] = cin.nextInt();
			add (rank[i] , 1);
			less[i] = sum (rank[i] - 1);
			nonbig[i] = sum (rank[i]);
		}
		Arrays.fill(r, 0);
		get_next (rank , k);
		Arrays.fill(r, 0);
		kmp (a , n , rank , k);
		cout.println(ans.size());
		for (int i = 0 ; i < ans.size() ; i ++)
			cout.println(ans.elementAt(i));
	}
}
class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;
    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = null;
    }
    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }
    public int nextInt() {
        return Integer.parseInt(next());
    }
    public long nextLong() {
    	return Long.parseLong(next());
    }
    public double nextDouble() {
    	return Double.parseDouble(next());
    }
    public BigInteger nextBigInteger() {
    	return new BigInteger(next());
    }
}