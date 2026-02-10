#include <stdio.h>
#include <string.h> 
int main() {
    char str[100]; 

    printf("Enter code name: ");
    scanf("%s", str); 

    int len = strlen(str);

    int start = 0;
    int end = len - 1;
    char temp;

    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }

    printf("Mirrored code: %s\n", str);

    return 0;
}