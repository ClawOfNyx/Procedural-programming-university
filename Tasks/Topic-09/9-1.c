#include <stdio.h>
#include <math.h>

typedef struct Point {
    double x, y;
} Point;

void printPoint(Point p);
Point createPoint(double x, double y);
double getDistance(Point a, Point b);

int main() {
    Point p1, p2;
    
    // p1 = createPoint(2, -3);
    // p2 = createPoint(-4, 5);
    // printPoint(p1);
    // printPoint(p2);
    printf("dist = %lf", getDistance(createPoint(2, -3), createPoint(-4, 5)));

    return 0;
}

void printPoint(Point p) {
    printf("(%.2lf; %.2lf)\n", p.x, p.y);
}

Point createPoint(double x, double y) {
    Point ptr;
    ptr.x = x;
    ptr.y = y;

    return ptr;
}

double getDistance(Point a, Point b) {
    return sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2));
}