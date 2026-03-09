/*
 author : fahad abdulla
 date   : 09/03/2026
*/

#include <stdio.h>

int main()
{
    int a[10][10];
    int r, c;
    int i, j;

    int mn, cl;
    int f;
    int sp = 0;

    int l, s;

    printf("enter rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("enter matrix elements:\n");

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    /* saddle point */

    for(i = 0; i < r; i++)
    {
        mn = a[i][0];
        cl = 0;

        for(j = 1; j < c; j++)
        {
            if(a[i][j] < mn)
            {
                mn = a[i][j];
                cl = j;
            }
        }

        f = 1;

        for(j = 0; j < r; j++)
        {
            if(a[j][cl] > mn)
            {
                f = 0;
                break;
            }
        }

        if(f == 1)
        {
            printf("saddle point = %d at (%d,%d)\n", mn, i+1, cl+1);
            sp = 1;
        }
    }

    if(sp == 0)
        printf("no saddle point\n");

    /* second largest */

    l = a[0][0];
    s = a[0][0];

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            if(a[i][j] > l)
            {
                s = l;
                l = a[i][j];
            }
            else if(a[i][j] > s && a[i][j] != l)
            {
                s = a[i][j];
            }
        }
    }

    printf("second largest = %d\n", s);

    return 0;
}
