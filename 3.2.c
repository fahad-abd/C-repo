/*
 * Author:Fahad Abdulla
 * Date: 09/03/2026
*/
#include <stdio.h>
#include <math.h>

#define sqr(x) ((x)*(x))
#define TwoPI 6.28318

double calc_cos(double);

int main()
{
    double a;
    printf("Enter x value > ");
    scanf("%lf", &a);
    printf("cos(%lf) = %lf", a, calc_cos(a));
    return 0;
}

double calc_cos(double x) // where x in radians
{
    x = fmod(x, TwoPI); // because cos repeats and can incress efficiency
    double Taylorsum = 1, xsqr = sqr(x), currAcc = 1, reqAcc = 0.0001;
    double currTerm = 1, nextTerm = 0;
    int n = 1;

    while (1)
    {
        nextTerm = (double)currTerm * -1 * xsqr / ((2 * n) * (2 * n - 1));
        Taylorsum += nextTerm;
        printf("N = %d\n", n);
        currTerm = nextTerm;
        n++;
        // stop 
        currAcc = (nextTerm / Taylorsum) > 0 ? (nextTerm / Taylorsum) : -1 * (nextTerm / Taylorsum);
        if (Taylorsum == 0 || currAcc <= reqAcc) break;
        // just for extra safe
        if (n > 1000) return 0;
    }
    return Taylorsum;
}
