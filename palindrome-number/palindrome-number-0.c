#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/* https://leetcode.com/problems/palindrome-number/ */
/* */
/* */
/* Given an integer x, return true if x is palindrome integer. */
/* */
/* */
/* An integer is a palindrome when it reads the same backward as forward. */

// simple solution

void itoa(uint32_t n, char s[]);
void reverse(char s[], int l);
int isPalindrome(int x);

int main(void) {
    if(isPalindrome(1023401) == 0) {
        printf("is palidrome.\n");
    } else {
        printf("is not palindrome.\n");
    }
    return 0;
}

void itoa(uint32_t n, char s[])
{
    uint32_t i = 0;
    do {
        s[i] = n % 10 + '0';
        n = n / 10;
        i++;
    } while (n != 0);
    s[i] = '\0';
    reverse(s, i);
}

// Reverse string s of length l
void reverse(char s[], int l) {
    int temp, i;
    l--;
    for (i = 0; i < l; i++, l--) {
        temp = s[i];
        s[i] = s[l];
        s[l] = temp;
    }
}

int isPalindrome(int x) {
    char *s = malloc(2147483649*sizeof(char));
    itoa(x, s);

    char *reversed = malloc(2147483649*sizeof(char));
    itoa(x, reversed);
    reverse(reversed, strlen(reversed));
    
    return strcmp(s, reversed);    
}
