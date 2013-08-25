//FFT copy from kuangbin    
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