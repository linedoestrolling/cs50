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
}

void merge_sort (int input[], int start, int end, int size) {
    printf("start_index is %i\n", start);
    printf("end_index is %i\n", end);
    if (size <= 1) {
        printf("reach end case\n");
        return;
    }

    //test
    else {
        int middle  = (start+end)/2;

        printf("middle_index is %i\n", middle);

        merge_sort(input, start, middle, middle - start + 1);


        merge_sort(input, middle + 1, end, end - middle);

        //making the 2 subarrays
        int left_half[middle - start + 1];
        int right_half[end - middle];
        int left_array_size = 0;
        int right_array_size = 0;

        for (int i = start; i <= middle; i++) { //splitting the array into 2 sub arrays
            left_half[i] = input[i];
            left_array_size++;
        }

        for (int i = middle+1; i < end; i++) {  // second sub array
            right_half[i] = input[i];
            right_array_size++;
        }

        //merging

        int left_array_index = start;
        int right_array_index = middle + 1;
        int main_index = start;

        printf("left index initialized as : %i\n", left_array_index);
        printf("right index initialized as : %i\n", right_array_index);

        printf("middle_index is: %i\n\n", middle);

        // for (int i = 0; i < end - start + 1; i++) {
        //     temp_array[i] = 0;
        // }

        while (left_array_index <= middle && right_array_index <= end) {
            if (left_half[left_array_index] > right_half[right_array_index]) {
                printf("left index is : %i\n", left_array_index);
                printf("main index is : %i\n", main_index);
                printf("element is %i\n", input[left_array_index]);
                input[main_index]  = left_half[left_array_index];
                left_array_index++;
                main_index++;
            }
            else if (right_half[right_array_index ] > left_half[left_array_index]) {
                printf("right index is : %i\n", right_array_index);
                printf("main index is : %i\n", main_index);
                printf("element is %i\n", right_half[right_array_index]);
                input[main_index] = right_half[right_array_index];
                right_array_index++;
                main_index++;
            }
            else {
                printf("left index is : %i\n", left_array_index);
                printf("right index is : %i\n", right_array_index);
                printf("main index is : %i\n", main_index);
                printf("element 1 is %i\n", left_half[left_array_index]);
                printf("element 2 is %i\n", right_half[right_array_index]);
                input[main_index] = left_half[left_array_index];
                left_array_index++;
                main_index++;
                input[main_index] = right_half[right_array_index];
                right_array_index++;
                main_index++;
            }
        }

        while (left_array_index <= left_array_size) {
            printf("grabbing the rest in first half\n");
            input[main_index] = left_half[left_array_index];
            printf("grabbed element is: %i\n", left_half[left_array_index]);
            left_array_index++;
            main_index++;
        }
        while (right_array_index <= right_array_size) {
            printf("grabbing the rest in second half\n");
            input[main_index] = right_half[right_array_index];
            printf("grabbed element is: %i\n", right_half[right_array_index]);
            right_array_index++;
            main_index++;
        }



        for (int i = 0; i < (end - start + 1); i++) {
            printf("input element is: %i\n", input[i]);
        }


    }
}

