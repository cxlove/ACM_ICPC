#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const double pi = acos (-1.0);
// Complex  z = a + b * i  
struct Complex {
    double a, b;
    Complex(double _a=0.0,double _b=0.0):a(_a),b(_b){}
    Complex operator + (const Complex &c) const {
        return Complex(a + c.a , b + c.b);
    }
    Complex operator - (const Complex &c) const {
        return Complex(a - c.a , b - c.b);
    }
    Complex operator * (const Complex &c) const {
        return Complex(a * c.a - b * c.b , a * c.b + b * c.a);
    }
};
//len = 2 ^ k
void change (Complex y[] , int len) {
    for (int i = 1 , j = len / 2 ; i < len -1 ; i ++) {
        if (i < j) swap(y[i] , y[j]);
        int k = len / 2;
        while (j >= k) {
            j -= k;
            k /= 2;
        }
        if(j < k) j += k;
    } 
}
// FFT 
// len = 2 ^ k
// on = 1  DFT    on = -1 IDFT
void FFT (Complex y[], int len , int on) {
    change (y , len);
    for (int h = 2 ; h <= len ; h <<= 1) {
        Complex wn(cos (-on * 2 * pi / h), sin (-on * 2 * pi / h));
        for (int j = 0 ; j < len ; j += h) {
            Complex w(1 , 0);
            for (int k = j ; k < j + h / 2 ; k ++) {
                Complex u = y[k];
                Complex t = w * y [k + h / 2];
                y[k] = u + t;
                y[k + h / 2] = u - t;
                w = w * wn;
            }
        }
    }
    if (on == -1) {
        for (int i = 0 ; i < len ; i ++) {
            y[i].a /= len;
        }
    }
}
const int N = 51005;
char s1[N] , s2[N];
int sum[N << 2]; 
Complex x1[N << 2] , x2[N << 2];
int main () {
    // freopen ("input.txt" , "r" , stdin);
    while (scanf ("%s %s", s1 ,s2) != EOF) {
        int l1 = strlen (s1);
        int l2 = strlen (s2);
        int l = 1;
        while (l < l1 * 2|| l < l2 * 2) l <<= 1;
        for (int i = 0 ; i < l1 ; i ++) {
            x1[i] = Complex (s1[l1 - i - 1] - '0' , 0);
        }
        for (int i = l1 ; i < l ; i ++) {
            x1[i] = Complex (0 , 0);
        }
        for (int i = 0 ; i < l2 ; i ++) {
            x2[i] = Complex (s2[l2 - i - 1] - '0' , 0);
        }
        for (int i = l2 ; i < l ; i ++) {
            x2[i] = Complex (0 , 0);
        }
        FFT (x1 , l , 1);
        FFT (x2 , l , 1);
        for (int i = 0 ; i < l ; i ++) {
            x1[i] = x1[i] * x2[i];
        }
        FFT (x1 , l , -1);
        for (int i = 0 ; i < l ; i ++) {
            sum[i] = (int) (x1[i].a + 0.5); 
        }
        for (int i = 0 ; i < l ; i ++) {
            sum[i + 1] += sum[i] / 10;
            sum[i] %= 10;
        }
        l = l1 + l2 - 1;
        while (sum[l] <= 0 && l > 0) l --;
        for (int i = l ; i >= 0 ; i --) {
            printf("%d", sum[i]);
        }
        puts("");
    }
    return 0;
}