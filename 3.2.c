/*
 * Author: Fahad Abdulla
 * Date: 09/03/2026
*/

#include <stdio.h>

int main()
{
    int m, n;
    int saddle_points = 0;

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &m, &n);

    int matrix[m][n];

    printf("Enter the elements of the matrix:\n");

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < m; i++)
    {
        int min = matrix[i][0];
        int col = 0;

        for (int j = 1; j < n; j++)
        {
            if (matrix[i][j] < min)
            {
                min = matrix[i][j];
                col = j;
            }
        }

        int isSaddle = 1;

        for (int k = 0; k < m; k++)
        {
            if (matrix[k][col] > min)
            {
                isSaddle = 0;
                break;
            }
        }

        if (isSaddle)
        {
            printf("Saddle point: %d\n", min);
            saddle_points++;
        }
    }

    if (saddle_points == 0)
        printf("No saddle point found\n");

    return 0;
}
