#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

/* https://leetcode.com/problems/remove-duplicates-from-sorted-array */

/* `curr` stores the curent value the next numbers will be judged
 * against. `removed` stores the number of numbers we are removing. I
 * use the variable i to keep track of the index at which I want to
 * insert the next number, and the variable j to interate over each
 * number in nums. If `num[j]` is equal to `curr`, then we just keep
 * going and add 1 to `removed`. If it's different then we insert it
 * at `i`... */

int removeDuplicates(int* nums, int numsSize) {
    int removed = 0;
    int curr = nums[0];
    int i = 1; //for insertion
    int j = 1; //for iteration
    
    while (j < numsSize) {
        if (curr == nums[j]) {
            j++;
            removed++;
        } else {
            nums[i] = nums[j];
            curr = nums[i];
            i++;
            j++;
        }
    }
    return numsSize - removed;
}

int main(void) {
    int nums[6] = {0, 0, 1, 1, 1, 2};

    int result = removeDuplicates(nums, 6);

    for (int i = 0; i < result; i++) {
        printf("%d\n", nums[i]);
    }

    return 0;
}
