#include<bits/stdc++.h>
using namespace std;

const double eps = 1e-10;

struct Point {
    double a, b; // a+bi
    Point(double _a = 0, double _b = 0) : a(_a), b(_b){}
};

int dcmp(double a, double b) {
    if(fabs(a - b) < eps)
        return 0;
    if(a > b)
        return 1;
    return -1;
}

Point operator + (Point A, Point B) {
    return Point(A.a + B.a, A.b + B.b);
}

Point operator - (Point A, Point B) {
    return Point(A.a - B.a, A.b - B.b);
}

Point operator * (Point A, Point B) {
    double a = A.a, b = A.b, c = B.a, d = B.b;
    return Point(a * c - b * d, b * c + a * d);
}

Point operator / (Point A, Point B) {
    double a = A.a, b = A.b, c = B.a, d = B.b;
    double na = (a * c + b * d) / (c * c + d * d), nb = (b * c - a * d) / (c * c + d * d);
    return Point(na, nb);
}

int main() {
    Point a(1.0, 1.0), b(2.0, 2.0);
    Point c = a + b;
    printf("%.2f %.2f\n", c.a, c.b);
    Point c = a - b;
    printf("%.2f %.2f\n", c.a, c.b);
    Point c = a * b;
    printf("%.2f %.2f\n", c.a, c.b);
    Point c = a / b;
    printf("%.2f %.2f\n", c.a, c.b);
    return 0;
}
