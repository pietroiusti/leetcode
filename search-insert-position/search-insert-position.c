#include <stdio.h>

/* https://leetcode.com/problems/search-insert-position/ */

/* Given a sorted array of distinct integers and a target value, *
return the index if the target is found. If not, return the index *
where it would be if it were inserted in order.  You must write an
algorithm with O(log n) runtime complexity. */

// Solution: I'm using a slightly modified bynary search function...

int searchInsert(int* nums, int numsSize, int target){
    int start_index = 0;
    int end_index = numsSize-1;
    int middle;
    while (start_index <= end_index) {
        middle = start_index+(end_index-start_index)/2;
        if (nums[middle]==target){
            return middle;
        }
        if (nums[middle]<target)
            start_index = middle+1;
        else
            end_index = middle-1;
    }
    return nums[middle] < target ? middle+1 : middle;
}

int main(void) {
    int nums[] = {1, 3, 5, 6};
    int result1 = searchInsert(nums, 4, 2);
    int result2 = searchInsert(nums, 4, 5);

    printf("result1: %d\n", result1); // => result1: 1
    printf("result2: %d\n", result2); // => result2: 2

    return 0;
}
