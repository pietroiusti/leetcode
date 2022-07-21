#include <stdio.h>
#include <stdlib.h>

/* https://leetcode.com/problems/plus-one/ */

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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int *result = (int*) malloc((digitsSize+1) * sizeof(int));

    int i, j; // last index of digits, and last index of result
    int sum; // holds value of digits[i] + 1
    int done = 0; // flag: true if addition has already been made
    int oneDigitMore = 0; // flag: true if final result has one digit
                          // more than the original number
    for (i=digitsSize-1,j=digitsSize; i>=0; i--, j--) {
        if (done) {
            result[j] = digits[i];
            continue;
        }

        sum = digits[i] + 1;
        if (sum == 10) {
            if (i != 0) {
                result[j] = 0;
            } else {
                result[j] = 0;
                result[j-1] = 1;
                oneDigitMore = 1;
            }
        } else { // sum < 10
            result[j] = sum;
            done = 1;
        }
    }

    if (oneDigitMore) {
        *returnSize = digitsSize+1;
        return result;
    }
    else {
        *returnSize = digitsSize;
        return result+1;
    }
}

int main(void) {
    int arr[3] = {9, 9};
    int returnSize;
    int *result = plusOne(arr, 2, &returnSize);

    printf("returnSize: %i\n",returnSize);

    //print result array
    for (int i=0; i<returnSize; i++) {
        printf("%d\n", result[i]);
    }

    return 0;
}
