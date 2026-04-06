#include <stdio.h>

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    size_t sizeof_arr = sizeof(arr) / sizeof(arr[0]);
    int *parr = &arr[0];
    int sum = 0;
    printf("Array elements: ");
    for(int i = 0; i < sizeof_arr; i++)
    {
        printf("%d, " , *(parr + i));
    }
    printf("\n");
    for(int i = 0; i < sizeof_arr; i++)
    {
        sum += *parr;
        parr++; // Move pointer to next element
    }
    printf("Sum of array elements: %d\n", sum);
    return 0;

}
