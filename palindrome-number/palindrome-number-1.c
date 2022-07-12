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

// If x is negative, then return false, becuase no number has a minus
// on both ends.
//
// If x ends with 0, then return false if the number is not 0, because
// only the number 0 starts with 0.
//
// If neither x is negative nor it ends with 0, we have two possible
// cases. Either x has an even number of digits, or it has an even
// number of digits. Let's consider both cases.
//
// If x has an even number of digits, then, after our loop, we can end
// up with x and half_reversed having the same number of digits (when
// the second reversed half of x is greater or equal to the first half
// of x) or we can end up with x having a digit less than
// half_reversed (when the second reversed half of x is less than the
// first half of x. This happens with 1211, for example.) If they have
// the same number of digits, then only the first disjunct of
// `half_reversed || x == half_reversed/10;` has hope to be true. If x
// has a digit less, then only the second disjuct has hope to be true.
//
// If x has an odd number of digits, then, after our loop, we will end
// up with x having a digit less than half_reversed. In this case only
// the second disjunct of `half_reversed || x == half_reversed/10;`
// has hope to be true (`half_reversed/10` removes the ``central
// digit'' of the original value of x).

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
