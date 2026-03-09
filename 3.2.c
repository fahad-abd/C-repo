/*
 * Author: Fahad Abdulla
 * Date: 09/03/2026
*/

#include <stdio.h>
#include <math.h>

#define SQUARE(x) ((x)*(x))
#define TWOPI 6.28318

double my_cos(double);

int main()
{
    double angle;

    printf("Enter value of x > ");
    scanf("%lf", &angle);

    double result = my_cos(angle);

    printf("cos(%lf) = %lf\n", angle, result);

    return 0;
}

double my_cos(double x)
{
    x = fmod(x, TWOPI);   // reduce angle within 0–2π

    double sum = 1;
    double x2 = SQUARE(x);
    double term = 1;
    double next = 0;

    double accuracy = 1;
    double required = 0.0001;

    int i = 1;

    while (1)
    {
        next = term * (-1) * x2 / ((2 * i) * (2 * i - 1));
        sum = sum + next;

        printf("Iteration = %d\n", i);

        term = next;
        i++;

        accuracy = (next/sum > 0) ? (next/sum) : -(next/sum);

        if (sum == 0 || accuracy <= required)
            break;

        if (i > 1000)
            return 0;
    }

    return sum;
}
