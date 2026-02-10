#include <stdio.h>
#include <string.h>
int main() {
    char s[100]; 

    printf("Enter string: ");
    if (scanf("%s", s) != 1) return 1;

    int start = 0;
    int end = strlen(s) - 1;
    int isPalindrome = 1; 

    while (start < end) {
        if (s[start] != s[end]) {
            isPalindrome = 0;
            break; 
        }
        start++;
        end--;
    }

    if (isPalindrome) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}