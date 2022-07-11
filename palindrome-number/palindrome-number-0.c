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

// Simple solution: reverse the number and compare it with the original.

bool isPalindrome(int x);

int main(void) {
    int number = 101;
    
    if (isPalindrome(number))
        printf("Is palindrome\n");
    else
        printf("Is not palindrome\n");

    return 0;
}

bool isPalindrome(int x) {
    if (x < 0)
        return false;
    
    long reversed = 0;
    int x_copy = x;
    
    while (x_copy != 0) {
        reversed = reversed*10 + x_copy%10;
        x_copy = x_copy / 10;
    }

    return x == reversed;
}
