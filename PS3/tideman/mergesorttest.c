#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

void merge_sort (int input[], int p, int r, int size);

int main (void) {
    int arr[8];
    arr[0] = 3;
    arr[1] = 6;
    arr[2] = 2;
    arr[3] = 4;
    arr[4] = 1;
    arr[5] = 5;
    arr[6] = 8;
    arr[7] = 7;
    merge_sort(arr, 0, 7, 8);
    //test
}

void merge_sort (int input[], int p, int r, int size) { 
    printf("p is %i\n", p);
    printf("r is %i\n", r);
    if (size <= 1) {
        printf("reach end case\n");
        return;
    }
    else {
        int q = (p+r)/2;
        int left_half[q - p + 1];
        int right_half[r - q];

        for (int i = p; i <= q; i++) { //splitting the array into 2 sub arrays
            left_half[i] = input[i];
        }

        for (int i = q+1; i < q; i++) {  // second sub array
            right_half[i] = input[i];
        }

        printf("q is %i\n", q);
        merge_sort(left_half, 0, q - p, q - p + 1);
        merge_sort(right_half, 0, r - q - 1, r - q);

        //merging
        int a = 0;
        int b = 0;
        int c = 0;
        printf("a initialized as : %i\n", a);
        printf("b initialized as : %i\n", b);
        printf("c initialized as : %i\n", c);
        printf("r initialized as : %i\n", r);
        printf("q is: %i\n", q);
        int temp_array[r - p + 1];
        for (int i = 0; i < r - p + 1; i++) {
            temp_array[i] = 0;
        }

        int left_half_size = sizeof(left_half);
        int right_half_size = sizeof(right_half);

        while (a <= left_half_size && b <= right_half_size) {
            if (left_half[a] > right_half[b]) {
                printf("a is : %i\n", a);
                printf("c is : %i\n", c);
                printf("element is %i\n", left_half[a]);
                temp_array[c] = left_half[a];
                a++;
                c++;
            }
            else if (right_half[b] > left_half[a]) {
                printf("b is : %i\n", b);
                printf("c is : %i\n", c);
                printf("element is %i\n", right_half[b]);
                temp_array[c] = right_half[b];
                b++;
                c++;
            }
            else {
                printf("a is : %i\n", a);
                printf("b is : %i\n", b);
                printf("c is : %i\n", c);
                printf("element 1 is %i\n", left_half[a]);
                printf("element 2 is %i\n", right_half[b]);
                temp_array[c] = left_half[a];
                a++;
                c++;
                temp_array[c] = right_half[b];
                b++;
                c++;
            }
        }

        while (a <= left_half_size) {
            printf("grabbing the rest in first half\n");
            temp_array[c] = left_half[a];
            printf("grabbed element is: %i\n", input[a]);
            a++;
            c++;
        }
        while (b <= right_half_size) {
            printf("grabbing the rest in second half\n");
            temp_array[c] = input[b];
            printf("grabbed element is: %i\n", input[b]);
            b++;
            c++;
        }

        
        for (int i = 0; i < (r - p + 1); i++) {
            input[i] = temp_array[i];
        } 
        
        for (int i = 0; i < (r - p + 1); i++) {
            printf("input element is: %i\n", input[i]);
        }


    }
}
