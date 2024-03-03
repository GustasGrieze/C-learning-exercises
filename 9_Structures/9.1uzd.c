#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

Point createPoint(double x, double y) {
    Point p;
    p.x = x;
    p.y = y;
    return p;
}

void printPoint(Point p) {
    printf("(%lf, %lf)\n", p.x, p.y);
}

double getDistance(Point a, Point b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

int main() {
    Point p1 = createPoint(2.0, -3.0);
    Point p2 = createPoint(-4.0, 5.0);

    printf("Point p1: ");
    printPoint(p1);
    printf("Point p2: ");
    printPoint(p2);

    double distance = getDistance(p1, p2);
    printf("The distance between p1 and p2 is: %lf\n", distance);

    return 0;
}
