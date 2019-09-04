#include <stdio.h>

/*
        - sorts the array a with n elements in non-increasing order
*/
void bubble_sort(int *a, int n)
{
        for(int i = 0; i < n; i++){
                for(int j = i; j > 0; j--){
                        if(a[j] > a[j - 1]){
                                int tmp = a[j];
                                a[j] = a[j - 1];
                                a[j - 1] = tmp;
                        }
                }
        }
}

int main()
{
        int a[5] = {2, 3, 1, 0, 3};

        bubble_sort(a, 5);

        for(int i = 0; i < 5; i++){
                printf("%d ", a[i]);
        }
}
