//date:2011-04-22 10:52:33
//code length:3656B
//Problem: 1873		User: himdd
//Memory: 132K		Time: 110MS
//Language: C++		Result: Accepted

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define inf 1e-8
#define N 33
int n;
struct Point{
		double x, y, len, v;
		Point operator -(const Point  p) const
		{
			Point res;
			res.x=this->x-p.x;
			res.y=this->y-p.y;
			return res;
		}
};

//求两点间的距离
double Distance(const Point& one,const Point &two)
{
	return sqrt((one.x-two.x)*(one.x-two.x)+
		(one.y-two.y)*(one.y-two.y));
}
bool zore(double temp)
{
	return fabs(temp)<inf;
}
int to_int(double temp)
{
	if(zore(temp))return 0;
		else return temp>0?1:-1;
}
//求矢量叉积
double multi(const Point &veca,const Point& vecb)
{
	return veca.x*vecb.y-vecb.x*veca.y;
}
//计算多边形周长,顶点按顺时针或逆时针给出
double get_girth(int resize,Point *result)
{
	 	double sum=0;
		for(int j=0;j<resize;j++)
		{
			sum+=Distance(result[j],result[(j+1)%resize]);
		}
		return sum;
}
//计算多边形面积,顶点按顺时针或逆时针给出
double area_polygon(int n,Point *p){
	 double s1=0,s2=0;
	 for (int i=0;i<n;i++)
		s1+=p[i].x*p[(i+1)%n].y,s2+=p[(i+1)%n].x*p[i].y;
	 return fabs(s1-s2)/2;
}
Point base;
 bool compare2(const Point& one,const Point &two)
{
	double re=multi(one-base,two-base);
	 if(to_int(re)>0)return true;
	 //如果在同一线上的点距base近的点在后,
	 //在while循环中除距base最远的点外都将被踢除
	 else if(zore(re)&&
		 to_int(Distance(one,base)-Distance(two,base))<0)
		 return true;
	 else return false;
}
bool compare1(const Point& one,const Point &two)
{
	return one.y<two.y||(one.y==two.y&&one.x<two.x);
}
//通过矢量叉积求极角关系（ac）(bc)
//k > 0 ,ac在bc顺时针方向上

 int create_convex(int vsize,Point * v,Point *result,Point &base)
 {
	//寻找base点
	base=v[0];
	int index=0;
	for(int i=1;i<vsize;i++)
	{
		if(compare1(v[i],base))
		{  base=v[i];index=i;}
	}
	swap(v[index],v[0]);
	sort(v+1,v+vsize,compare2);
	result[0]=v[0];
	int k=1;
	int pos=0;
	while(k<vsize)
	{
		while(pos>0&&to_int(multi(v[k]-result[pos-1],result[pos]-result[pos-1]))>=0)
		    pos--;
		result[++pos]=v[k++];
	}
	//while(zore(multi(v[0]-result[pos-1],result[pos]-result[pos-1])))
	//	pos–;
	return pos+1;
}
int main() {
	//freopen("1.txt","r",stdin);
	Point plist[N], tree[N]; //存放坐标上的点
	Point ch[N]; //存放凸包上的点
    int i, j, nt, T = 0;
    while (scanf("%d", &nt),nt) {
        double min_value = 1e20, best_cut_len, best_con_len;
        double cut_len, con_len, cut_v;
        int ans[N], nans;
        for (i = 0; i < nt; i++)
            scanf("%lf%lf%lf%lf", &tree[i].x, &tree[i].y, &tree[i].v, &tree[i].len);
        for (i = 1; i < (1 << nt); i++) {
            cut_len = cut_v = 0.0;
            n = 0;
            for (j = 0; j < nt; j++) {
                int s = 1 << j;
                if (s & i)
                    cut_len += tree[j].len, cut_v += tree[j].v;
                else
                    plist[n++] = tree[j];
            }
            if (cut_v > min_value)
                continue;

			int nm=create_convex(n,plist,ch,base);
            con_len = get_girth(nm,ch);
            if (con_len <= cut_len && cut_v < min_value) {
                min_value = cut_v;
                best_cut_len = cut_len;
                best_con_len = con_len;
                for (nans = j = 0; j < nt; j++) {
                    int s = 1 << j;
                    if (s & i)
                        ans[nans++] = j + 1;
                }
            }
        }
        printf("Forest %d\n", ++T);
        printf("Cut these trees: ");
        for (i = 0; i < nans; i++)
            printf("%d ", ans[i]);
        printf("\n");
        printf("Extra wood: %.2lf\n\n",best_cut_len-best_con_len);
    }
}
