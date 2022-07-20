#include <stdio.h>
#include <stdlib.h>

/* You are given a large integer represented as an integer array
 * digits, where each digits[i] is the ith digit of the integer. The
 * digits are ordered from most significant to least significant in
 * left-to-right order. The large integer does not contain any leading
 * 0's. */

/* Increment the large integer by one and return the resulting array
 * of digits. */ 

/* Example 1: */
/* Input: digits = [1,2,3] */
/* Output: [1,2,4] */
/* Explanation: The array represents the integer 123. */
/* Incrementing by one gives 123 + 1 = 124. */
/* Thus, the result should be [1,2,4]. */

/* Example 2: */
/* Input: digits = [4,3,2,1] */
/* Output: [4,3,2,2] */
/* Explanation: The array represents the integer 4321. */
/* Incrementing by one gives 4321 + 1 = 4322. */
/* Thus, the result should be [4,3,2,2]. */

/* Example 3: */
/* Input: digits = [9] */
/* Output: [1,0] */
/* Explanation: The array represents the integer 9. */
/* Incrementing by one gives 9 + 1 = 10. */
/* Thus, the result should be [1,0]. */
 

/* Constraints: */
/* 1 <= digits.length <= 100 */
/* 0 <= digits[i] <= 9 */
/* digits does not contain any leading 0's. */


int intPow(int base, int n) { // Cf. K&R
    int i , p;
    p = 1;    
    for (i = 1; i <= n; i++) {
        p = p * base;
    }
    return p;
}

void reverseIntArray(int *arr, int len) {
    int i = len - 1;
    int j = 0;
    while(i > j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i--;
        j++;
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int *result = malloc(digitsSize+1 * sizeof(int));

    // turn array into integer value
    int sum = 0;
    for (int i=0, j=digitsSize-1; j >= 0; i++, j--) {
        sum += digits[j] * intPow(10, i);
    }    

    // add 1
    sum = sum + 1;

    // remove each digit from sum and put it into the result array
    // keeping track of how many digits we remove
    int i = 0;
    while (sum) {
        result[i] = sum % 10;
        sum = sum / 10;
        i++;
    }

    //return reversed array
    *returnSize = i;
    reverseIntArray(result, i);
    return result;
}

int main(void) {
    int arr[3] = {9, 9, 9};
    int returnSize;
    int *result = plusOne(arr, 3, &returnSize);

    // print result array
    for (int i=0; i<returnSize; i++) {
        printf("%d\n", result[i]);
    }

    return 0;
}
