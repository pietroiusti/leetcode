#include <stdio.h>

/* https://leetcode.com/problems/remove-element/ */

/* Given an integer array nums and an integer val, remove all
 * occurrences of val in nums in-place. The relative order of the
 * elements may be changed. */

/* Since it is impossible to change the length of the array in some
 * languages, you must instead have the result be placed in the first
 * part of the array nums. More formally, if there are k elements
 * after removing the duplicates, then the first k elements of nums
 * should hold the final result. It does not matter what you leave
 * beyond the first k elements. */

/* Return k after placing the final result in the first k slots of
 * nums. */

/* Do not allocate extra space for another array. You must do this by
 * modifying the input array in-place with O(1) extra memory. */

// Example:
// nums = {0, 1, 2, 3, 4, 5, 8, 5, 9, 5}, val= 5
// =>
// {0, 1, 2, 3, 4, 8, 9}

int removeElement(int* nums, int numsSize, int val){
    int removed = 0; // number of values removed
    int i = 0; // index for insertion
    int j = 0; // index for iteration
    
    while (j < numsSize) {
        if (nums[j] == val) {
            j++;
            removed++;
        } else {
            nums[i] = nums[j]; // store value
            i++;
            j++;
        }
    }
    
    return numsSize - removed;
}

int main(void) {
    int arr[10] = {0, 1, 2, 3, 4, 5, 8, 5, 9, 5};

    int n = removeElement(arr, 10, 5);

    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }
}
