/*
 * Author: Fahad Abdulla
 * Date: 09/03/2026
*/
#include<stdio.h>

int main()
{
    int a[10][10],m,n,i,j;
    int min,max,col;
    int saddle=0;
    int largest,second;

    printf("Enter rows and columns: ");
    scanf("%d%d",&m,&n);

    printf("Enter matrix elements:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    for(i=0;i<m;i++)
    {
        min=a[i][0];
        col=0;

        for(j=1;j<n;j++)
        {
            if(a[i][j]<min)
            {
                min=a[i][j];
                col=j;
            }
        }

        max=1;

        for(j=0;j<m;j++)
        {
            if(a[j][col]>min)
            {
                max=0;
                break;
            }
        }

        if(max==1)
        {
            printf("Saddle point = %d at position (%d,%d)\n",min,i+1,col+1);
            saddle=1;
        }
    }

    if(saddle==0)
    printf("No saddle point exists\n");


    /* Finding Second Largest */

    largest=a[0][0];
    second=a[0][0];

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]>largest)
            {
                second=largest;
                largest=a[i][j];
            }
            else if(a[i][j]>second && a[i][j]!=largest)
            {
                second=a[i][j];
            }
        }
    }

    printf("Second largest element = %d",second);

    return 0;
}

