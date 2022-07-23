#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Given two binary strings a and b, return their sum as a binary string. */

/* Example 1: */
/* Input: a = "11", b = "1" */
/* Output: "100" */

/* Example 2: */
/* Input: a = "1010", b = "1011" */
/* Output: "10101" */

/* Constraints: */

/* 1 <= a.length, b.length <= 104 */
/* a and b consist only of '0' or '1' characters. */
/* Each string does not contain leading zeros except for the zero itself. */

char *addBinary(char *a, char *b) {
    // get last indices
    int a_index = 0;
    int b_index = 0;
    while( a[a_index] != '\0')
        a_index++;
    while(b[b_index] != '\0')
        b_index++;
    char *longest = a_index > b_index ? a : b;
    char *shortest = longest == a ? b : a;
    int longest_index = longest == a ? a_index : b_index;
    int shortest_index = longest_index == a_index ? b_index : a_index;

    char *result = malloc((longest_index+2)*sizeof(char)); // +2 because of 1 (possible) digit more and '\0'.
    //memset(result, '\0', (longest_index+1)*sizeof(char));
    //char result[longest_index+2];

    // make indices point to last char (before the null character);
    result[longest_index+1] = '\0';
    int result_index = longest_index;
    longest_index--;
    shortest_index--;

    // printf("result_index: %d\n", result_index);
    // printf("longest_index: %d\n", longest_index);
    // printf("shortest_index: %d\n", shortest_index);

    // printf("0 + 0 + 0 = %d\n", '0'+'0'+'0'); // => 144
    // printf("0 + 0 + 1 = %d\n", '0'+'0'+'1'); // => 145
    // printf("0 + 1 + 1 = %d\n", '0'+'1'+'1'); // => 146
    // printf("1 + 1 + 1 = %d\n", '1'+'1'+'1'); // => 147

    int carry = '0';
    int oneDigitMore = 0; // flag: is the result one digit longer than longest?
    while (longest_index >= 0) {
        int sum;
        //printf("summing %c and %c (plus carry: %c)\n", longest[longest_index], (shortest_index < 0 ? '0' : shortest[shortest_index]), carry);
        sum = longest[longest_index] + (shortest_index < 0 ? '0' : shortest[shortest_index]) + carry;
        //printf("sum: %d\n", sum);
        if (sum == 144) { // '0' + '0' + '0'
            result[result_index] = '0';
            carry = '0';
        } else if (sum == 145) { // '0' + '0' + '1'
            result[result_index] = '1';
            carry = '0';
        } else if (sum == 146) { // '0' + '1' + '1
            result[result_index] = '0';
            carry = '1';
            if (longest_index == 0) {
                result[result_index-1] = '1';
                oneDigitMore = 1;
            }
        } else if (sum == 147) { // '1' + '1' + '1
            result[result_index] = '1';
            carry = '1';
            if (longest_index == 0) {
                result[result_index-1] = '1';
                oneDigitMore = 1;
            }
        }        
        longest_index--;
        shortest_index--;
        result_index--;
    }

    if (oneDigitMore)
        return result;
    else 
        return result+1;
}

int main() {
    char a[5] = {'1', '1', '\0'};
    char b[3] = {'1', '\0'};
    //char b[4] = {1, 0, 1, 0};

    char *result = addBinary(a, b);

    printf("%s\n", result);

    return 0;
}
