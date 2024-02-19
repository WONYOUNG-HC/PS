#include <stdio.h>
#include <stdlib.h>

int compare(const void *_arr1, const void *_arr2)
{
    int arr1 = *((int *)_arr1);
    int arr2 = *((int *)_arr2);

    if (arr1 < arr2)
        return 1;
    else if (arr1 > arr2)
        return -1;
    else
        return 0;
}

int main()
{
    int N, len = 0, num = 0;
    int arr[10] = {0};
    scanf("%d", &N);

    while (N > 0)
    {
        arr[num] = N % 10;
        N = N / 10;
        num++;
        len++;
    }

    qsort(arr, len, sizeof(int), compare);

    for (int i = 0; i < len; i++)
        printf("%d", arr[i]);
    printf("\n");

    return 0;
}