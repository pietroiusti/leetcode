#include <stdio.h>

/* https://leetcode.com/problems/length-of-last-word/submissions/ */

/* Given a string s consisting of words and spaces, return the length
 * of the last word in the string. */

/* A word is a maximal substring consisting of non-space characters
 * only. */

/* Example 1: */
/* Input: s = "Hello World" */
/* Output: 5 */
/* Explanation: The last word is "World" with length 5. */

/* Example 2: */
/* Input: s = "   fly me   to   the moon  " */
/* Output: 4 */
/* Explanation: The last word is "moon" with length 4. */

/* Example 3: */
/* Input: s = "luffy is still joyboy" */
/* Output: 6 */
/* Explanation: The last word is "joyboy" with length 6. */

/* Constraints: */
/* 1 <= s.length <= 104 */
/* s consists of only English letters and spaces ' '. */
/* There will be at least one word in s. */




// In this solution I start from the end of s and go backwards

int lengthOfLastWord(char * s){
    int result = 0;
    int started = 0; //flag
    int i = 0;
    int length;

    while (s[i] != '\0') {
        i++;
    }
    i--; // last index of s;

    while (i >= 0) {
        if (s[i] == ' ') {
            if (started) {
                return result;
            } else {
                i--;
            }
        } else {
            if (!started) {
                started = 1;
            }
            result++;
            i--;
        }
    }
    return result;
}

int main(void) {
    char s[] = {'h','e','l','l','o',' ','w','o','r','l','d',' ',' ','\0'};

    int n = lengthOfLastWord(s);

    printf("%d\n", n);

    return 0;
}
