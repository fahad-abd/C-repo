/*
 * Author: Fahad Abdulla
 * Date: 09/03/2026
 */

#include <stdio.h>
#include <math.h>

#define SQUARE(x) ((x)*(x))
#define TWOPI 6.2831

double my_sin(double);

int main()
{
    double angle;

    printf("Enter value of x : ");
    scanf("%lf", &angle);

    double result = my_sin(angle);

    printf("sin(%lf) = %lf\n", angle, result);

    return 0;
}

double my_sin(double x)
{
    x = fmod(x, TWOPI);

    double sum = x;
    double x2 = SQUARE(x);
    double term = x;
    double next = 0;

    double accuracy = 1;
    double required = 0.0001;

    int i = 1;

    while (1)
    {
        next = term * (-1) * x2 / ((2*i)*(2*i+1));
        sum = sum + next;

        term = next;
        i++;

        accuracy = (next/sum > 0) ? (next/sum) : -(next/sum);

        if(sum == 0 || accuracy <= required)
            break;

        if(i > 1000)
            return 0;
    }

    return sum;
}
