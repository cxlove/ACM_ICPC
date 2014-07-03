#include <cstdio>
#include<cmath>
#include<algorithm>
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
using namespace std;

struct point {
    double x, y;
};

double xmult(point p1, point p2, point p0) {
    return (p1.x - p0.x)*(p2.y - p0.y)-(p2.x - p0.x)*(p1.y - p0.y);
}

double area_triangle(point p1, point p2, point p3) {
    return fabs(xmult(p1, p2, p3)) / 2;
}

int same_side(point p1, point p2, point l1, point l2) {
    return xmult(l1, p1, l2) * xmult(l1, p2, l2) > eps;
}

int dot_online_in(point p, point l1, point l2) {
    return zero(xmult(p, l1, l2)) && (l1.x - p.x)*(l2.x - p.x) < eps && (l1.y - p.y)*(l2.y - p.y) < eps;
}

int dots_inline(point p1, point p2, point p3) {
    return zero(xmult(p1, p2, p3));
}

int intersect_in(point u1, point u2, point v1, point v2) {
    if (!dots_inline(u1, u2, v1) || !dots_inline(u1, u2, v2))
        return !same_side(u1, u2, v1, v2) && !same_side(v1, v2, u1, u2);
    return dot_online_in(u1, v1, v2) || dot_online_in(u2, v1, v2) || dot_online_in(v1, u1, u2) || dot_online_in(v2, u1, u2);
}

point intersection(point u1, point u2, point v1, point v2) {
    point ret = u1;
    double t = ((u1.x - v1.x)*(v1.y - v2.y)-(u1.y - v1.y)*(v1.x - v2.x))
            / ((u1.x - u2.x)*(v1.y - v2.y)-(u1.y - u2.y)*(v1.x - v2.x));
    ret.x += (u2.x - u1.x) * t;
    ret.y += (u2.y - u1.y) * t;
    return ret;
}

int parallel(point u1, point u2, point v1, point v2) {
    return zero((u1.x - u2.x)*(v1.y - v2.y)-(v1.x - v2.x)*(u1.y - u2.y));
}


double fun(point s1, point s2, point s3) {
    point temp;
    temp.x = s2.x + 1, temp.y = s2.y;
    temp=intersection(s1,s3,s2,temp);
    return area_triangle(s1,s2,temp);
}
point s[5];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf",
                &s[1].x, &s[1].y, &s[2].x, &s[2].y, &s[3].x, &s[3].y, &s[4].x, &s[4].y);
        if (s[1].y == s[2].y || s[3].y == s[4].y)
            printf("0.00\n");
        else if (!intersect_in(s[1], s[2], s[3], s[4]))
            printf("0.00\n");
        else if (parallel(s[1], s[2], s[3], s[4]))
            printf("0.00\n");
        else {
            point ret = intersection(s[1], s[2], s[3], s[4]);
            point e[5];
            int num = 0;
            for (int i = 1; i < 5; ++i)
                if (s[i].y > ret.y)
                    e[num++] = s[i];
            if (num != 2)
                printf("0.00\n");
            else {
                if (e[1].y < e[0].y)
                    swap(e[0], e[1]);
                if (e[0].x == e[1].x)
                    printf("0.00\n");
                else if (e[0].x < ret.x && e[1].x < e[0].x && xmult(e[1], e[0], ret) > eps)
                    printf("0.00\n");
                else if (e[0].x > ret.x && e[1].x > e[0].x && xmult(e[1], e[0], ret) < eps)
                    printf("0.00\n");
                else
                    printf("%.2lf\n", fun(ret, e[0], e[1]));
            }

        }
    }
    return 0;
}

