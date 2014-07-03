#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define eps 1e-8
using namespace std;
const int N = 105;
inline int dcmp(double d){
	return d<-eps?-1:d>eps;
}
inline double sqr(double d){
	return d*d;
}
struct Point{
	double x,y;
	Point(){}
	Point(double _x,double _y):x(_x),y(_y){}
	void input(){scanf("%lf%lf",&x,&y);}
	inline Point operator+(const Point &p)const{
		return Point(x+p.x,y+p.y);
	}
	inline bool operator==(const Point &p)const{
		return dcmp(x-p.x)==0&&dcmp(y-p.y)==0;
	}
	inline Point operator-(const Point&p)const{
		return Point(x-p.x,y-p.y);
	}
	inline double operator*(const Point &p)const{
		return x*p.y-y*p.x;
	}
	inline Point operator*(const double &k)const{
		return Point(x*k,y*k);
	}
	inline Point operator/(const double &k)const{
		return Point(x/k,y/k);
	}
	inline double operator/(const Point &p)const{
		return x*p.x+y*p.y;
	}
	inline double Distance(Point &p){
		return sqrt(sqr(p.x-x)+sqr(p.y-y));
	}
	inline Point turnLeft(){
		return Point(-y,x);
	}
};
struct Line{
	Point a,b;
	Line(){}
	Line(Point _a,Point _b):a(_a),b(_b){}
	inline double operator*(const Point &p)const{
		return (b-a)*(p-a);
	}
	inline Point CrossPoint(const Line &v){
		double s1=v*a,s2=v*b;
		return (a*s2-b*s1)/(s2-s1);
	}
	inline double DisPointToSeg(Point p){
		if(a==b) return a.Distance(p);
		Point q=p+(a-b).turnLeft();
		if(((p-a)*(q-a))*((p-b)*(q-b))>0)
			return min(p.Distance(a),p.Distance(b));
		return fabs((*this)*p)/a.Distance(b);
	}
};
struct Polygon{
	int n;
	Point p[10005];
	Polygon(){n=0;}
	inline void input(){
		for(int i=0;i<n;i++)
			p[i].input();
	}
	inline bool isConvex(){
		bool s[3]={false,false,false};
		p[n]=p[0];p[n+1]=p[1];
		for(int i=0;i<n;i++){
			s[dcmp((p[i+1]-p[i])*(p[i+2]-p[i]))+1]=true;
			if(s[0]&&s[2]) return false;
		}
		return true;
	}
	inline int PointInsert(const Point &P){
		p[n]=p[0];
		for(int i=0;i<n;i++){
			if(dcmp((p[i]-P)*(p[i+1]-P))==0&&dcmp((P-p[i])/(P-p[i+1]))<=0){
				if(p[i]==P||p[i+1]==P) return 3;
				return 2;
 			}
		}
		int cnt=0;
		for(int i=0;i<n;i++){
			int k=dcmp((p[i]-P)*(p[i+1]-P));
			int u=dcmp(p[i].y-P.y);
			int v=dcmp(p[i+1].y-P.y);
			if(k>0&&u<0&&v>=0) cnt++;
			if(k<0&&v<0&&u>=0) cnt--;
		}
		return cnt!=0;
	}
}pol;
struct Circle{
	Point c;
	double r;
	void input(){
		scanf("%lf",&r);
		c.input();
	}
}cir;
int main(){
	while(scanf("%d",&pol.n)!=EOF){
		if(pol.n<3) break;
		cir.input();
		pol.input();
		if(!pol.isConvex()) puts("HOLE IS ILL-FORMED");
		else if(pol.PointInsert(cir.c)!=1) puts("PEG WILL NOT FIT");
		else{
			int i;
			for(i=0;i<pol.n;i++){
				//printf("%.5f\n",Line(pol.p[i],pol.p[(i+1)%pol.n]).DisPointToSeg(cir.c));
				if(dcmp(Line(pol.p[i],pol.p[(i+1)%pol.n]).DisPointToSeg(cir.c)-cir.r)<0)
					break;
			}
			if(i==pol.n) puts("PEG WILL FIT");
			else puts("PEG WILL NOT FIT");
		}

	}
	return 0;
}