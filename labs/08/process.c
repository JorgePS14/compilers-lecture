#include <stdio.h>
#include <stdlib.h>

int proc(int a[]) {
	int sum = 0, i;
	for (i = 0; i < 1000000; i++)
		sum += a[i];
	return sum;
}

int main()
{
    int * array =  (int *)malloc(sizeof(int) * 1000000);
    printf("Sum of elements is: %d", proc(array));
    return 0;
}