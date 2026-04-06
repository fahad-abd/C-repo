#include <stdio.h>

int main()
{
    int a = 6, b = 7;
    int *pa = &a, *pb = &b;
    // calc opertions
    printf("a = %d, b = %d\n", *pa, *pb);
    printf("a + b = %d\n", *pa + *pb);
    printf("a - b = %d\n", *pa - *pb);  
    printf("a * b = %d\n", *pa * *pb);
    printf("a / b = %d\n", *pa / *pb);
    printf("a %% b = %d\n", *pa % *pb);
    return 0;
}
