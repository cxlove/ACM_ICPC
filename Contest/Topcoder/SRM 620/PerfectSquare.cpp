// BEGIN CUT HERE

// END CUT HERE
#line 5 "PerfectSquare.cpp"
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
typedef long long LL;
const int maxn = 405 * 50;
int equ, var; // 有equ个方程，var个变元。增广阵行数为equ, 分别为0到equ - 1，列数为var + 1，分别为0到var.
int a[maxn][405];
int x[maxn]; // 解集.
bool free_x[maxn]; // 判断是否是不确定的变元.
int free_num;
// 高斯消元法解方程组(Gauss-Jordan elimination).(-2表示有浮点数解，但无整数解，-1表示无解，0表示唯一解，大于0表示无穷解，并返回自由变元的个数)
int Gauss() {
    int i, j, k;
    int max_r; // 当前这列绝对值最大的行.
    int col; // 当前处理的列.
    int ta, tb , LCM , temp;
    int free_x_num ; int free_index;
    // 转换为阶梯阵.
    col = 0; // 当前处理的列.
    for (k = 0; k < equ && col < var; k++, col++) { // 枚举当前处理的行.
        // 找到该col列元素绝对值最大的那行与第k行交换.(为了在除法时减小误差)
        max_r = k;
        for (i = k + 1; i < equ; i++) {
            if (abs(a[i][col]) > abs(a[max_r][col])) max_r = i;
        }
        if (max_r != k) { // 与第k行交换.
            for (j = k; j < var + 1; j++) swap(a[k][j], a[max_r][j]);
        }
        if (a[k][col] == 0) { // 说明该col列第k行以下全是0了，则处理当前行的下一列.
            k--; continue;
        }
        for (i = k + 1; i < equ; i++) { // 枚举要删去的行.
            if (a[i][col] != 0) {
                for (j = col; j < var + 1; j++) {
                    a[i][j] = a[i][j] ^ a[k][j];
                }
            }
        }
    }
    // 1. 无解的情况: 化简的增广阵中存在(0, 0, ..., a)这样的行(a != 0).
    for (i = k; i < equ; i++) { 
   // 对于无穷解来说，如果要判断哪些是自由变元，那么初等行变换中的交换就会影响，则要记录交换.
        if (a[i][col] != 0) return -1;
	}
    return var - k; 
}

class PerfectSquare {
    public:
    int ways(vector <int> x) {
    	vector <int> f;
    	int n = x.size();
    	for (int i = 1 ; i * i <= n ; i ++) {
    		if (i * i == n) {
    			n = i;
    			break;
    		}
    	}
    	for (int i = 0 ; i < n * n ; i ++) {
    		int m = x[i];
    		for (int j = 2 ; j * j <= m ; j ++) {
    			if (m % j == 0) {
    				f.push_back (j);
    				while (m % j == 0) m /= j;
    			}
    		}
    		if (m > 1) f.push_back (m);
    	}
    	sort (f.begin () , f.end ());
    	f.resize (unique (f.begin () , f.end ()) - f.begin ());
    	memset (a , 0 , sizeof (a));
    	for (int i = 0 ; i < n ; i ++) {
    		for (int j = i * n  ; j < n + i * n ; j ++) {
    			a[i][j] = 1;
    		}
    		a[i][n * n] = 1;
    	}
    	for (int i = 0 ; i < n ; i ++) {
    		for (int j = 0 ; j < n ; j ++) {
    			a[i + n][j * n + i] = 1;
    		}
    		a[i + n][n * n] = 1;
    	}
    	for (int i = 0 ; i < f.size() ; i ++) {
    		for (int j = 0 ; j < n * n ; j ++) {
    			int cnt = 0;
    			int m = x[j];
    			// cout << m << " " << f[i] << endl;
    			while (m % f[i] == 0) {
    				m /= f[i] ; 
    				cnt = 1 - cnt;
    			}
    			a[i + n * 2][j] = cnt;
    		}
    	}
    	equ = n * 2 + f.size();var = n * n;
    	// cout << equ << " " << var << endl;
    	int ret = 1 , ans = Gauss ();
    	if (ans == -1) return 0;
    	for (int i = 0 ; i < ans ; i ++) {
    		ret = (1LL * ret * 2) % 1000000007;
    	}
    	return ret;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 1,
 1, 2}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, ways(Arg0)); }
	void test_case_1() { int Arr0[] = {620, 620,
 620, 620}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, ways(Arg0)); }
	void test_case_2() { int Arr0[] = {1, 2, 3,
 4, 5, 6,
 7, 8, 9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, ways(Arg0)); }
	void test_case_3() { int Arr0[] = {2, 2, 2, 2, 2,
 2, 2, 2, 2, 2,
 2, 2, 2, 2, 2,
 2, 2, 2, 2, 2,
 2, 2, 2, 2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, ways(Arg0)); }
	void test_case_4() { int Arr0[] = {2, 3, 4, 5,
 6, 7, 8, 9,
 10,11,12,13,
 14,15,16,17}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(4, Arg1, ways(Arg0)); }
	void test_case_5() { int Arr0[] = {9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,
 9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,
 9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,
 9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,
 9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,
 9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,
 9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,
 9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,
 9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,
 9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 993282280; verify_case(5, Arg1, ways(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    PerfectSquare ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
