#include <stdio.h>
#include <string.h>

#define MAX_CHARS 100
#define GoToXY(x, y) printf("\033[%d;%dH", (y), (x))
#define CLEAR_SCREEN() printf("\033[H\033[J")

int main()
{
    char string[MAX_CHARS];
    printf("Enter a string: ");
    fgets(string, MAX_CHARS, stdin);
    string[strcspn(string, "\n")] = '\0';

    char* pstr = string; // Pointer to the start of the string
    int nchars = strlen(string);
    int isStrLong = nchars > 8 ? 1 : 0;
    CLEAR_SCREEN();
    int startY = 1;
    int boxWidth = 14;
    if (isStrLong)
    {
        printf("+------+-----------------+\n");
        printf("+ Char | Memory Address  |\n");
        printf("+------+-----------------+\n");
        for (int i = 0; i < nchars; i++)
        {
            printf("|   %c  |   %lu    |\n", *(pstr + i), &(pstr[i]));
        }
        printf("+------+-----------------+\n");
    }
    else {
        printf("+------+\n| Chars |\n+------+\n");
        for (int i = 0; i < nchars; i++)
        {
            int x = 8 + i * (boxWidth + 1);
            GoToXY(x, startY);
            printf("+--------------+");
            GoToXY(x, startY + 1);
            printf("|      %c       |", *(pstr + i));
            GoToXY(x, startY + 2);
            printf("+--------------+");
        }
        int addressY = startY + 2;
        GoToXY(1, addressY);
        printf("+------+\n| Addr |\n+------+\n");
        for (int i = 0; i < nchars; i++)
        {
            int x = 8 + i * (boxWidth + 1);
            GoToXY(x, addressY);
            printf("+--------------+");
            GoToXY(x, addressY + 1);
            printf("|   %lu  |", &(pstr[i]));
            GoToXY(x, addressY + 2);
            printf("+--------------+");
        }
        GoToXY(1, addressY + 4);
    }
    return 0;
}
