#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

/* https://leetcode.com/problems/palindrome-number/ */
/* */
/* */
/* Given an integer x, return true if x is palindrome integer. */
/* */
/* */
/* An integer is a palindrome when it reads the same backward as forward. */

// Better solution: reverse only half of the number and compare the two halves.

bool isPalindrome(int x);

int main(void) {
    int number = 1241;

    if (isPalindrome(number))
        printf("Is palindrome\n");
    else
        printf("Is not palindrome\n");

    return 0;
}

bool isPalindrome(int x) {
    if (x < 0 || (x%10 == 0 && x!=0)) {
        return false;
    }

    long half_reversed = 0;

    while (x > half_reversed) {
        //printf("x: %d\n", x);
        //printf("half_reversed: %d\n", half_reversed);
        half_reversed = half_reversed*10 + x%10;
        x = x / 10;
    };

    return x == half_reversed || x == half_reversed/10;
}
