/*
 * Author: Fahad Abdulla
 * Date: 09/03/2026
 */

#include <stdio.h>
#include <math.h>

#define sqr(x) ((x)*(x))
#define TwoPI 6.28318

double calc_sin(double);

int main()
{
    double a;
    printf("Enter x value > ");
    scanf("%lf", &a);
    printf("sin(%lf) = %lf", a, calc_sin(a));
    return 0;
}

double calc_sin(double x) 
{
    x = fmod(x, TwoPI);
    double Taylorsum = x, xsqr = sqr(x), currAcc = 1, reqAcc = 0.0001;
    double currTerm = x, nextTerm = 0;
    int n = 1;

    while (1)
    {
        nextTerm = (double)currTerm * -1 * xsqr / ((2 * n) * (2 * n + 1));
        Taylorsum += nextTerm;
        printf("N = %d\n", n);
        currTerm = nextTerm;
        n++;
        currAcc = (nextTerm / Taylorsum) > 0 ? (nextTerm / Taylorsum) : -1 * (nextTerm / Taylorsum);
        if (Taylorsum == 0 || currAcc <= reqAcc) break;
        if (n > 1000) return 0;
    }
    return Taylorsum;
}
