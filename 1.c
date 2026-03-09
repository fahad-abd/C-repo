#include <stdio.h>
#include <math.h>

#define P 3.141
#define sq(a) ((a)*(a))

double distance_between(double a1, double b1, double a2, double b2)
{
    double d;
    d = sqrt(sq(a2 - a1) + sq(b2 - b1));
    return d;
}

double circle_perimeter(double d)
{
    return P * d;
}

double circle_area(double d)
{
    double radius;
    radius = d / 2.0;
    return P * sq(radius);
}

int main()
{
    double xA, yA, xB, yB;
    double d, peri, ar;

    printf("First Point\n");
    printf("Enter x and y : ");
    scanf("%lf %lf", &xA, &yA);

    printf("Second Point\n");
    printf("Enter x and y : ");
    scanf("%lf %lf", &xB, &yB);

    d = distance_between(xA, yA, xB, yB);
    peri = circle_perimeter(d);
    ar = circle_area(d);

    printf("\nDiameter = %lf", d);
    printf("\nPerimeter = %lf", peri);
    printf("\nArea = %lf", ar);

    return 0;
}
