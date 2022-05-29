#include <stdio.h>
#include <string.h>
#define MAX 1000 /* The maximum number of characters in a line of input */

int main()
{
    char string[MAX], reverse[MAX];
    int i, l, flag = 0, begin, middle, end, count = 0; 
    printf("Type some text (then ENTER):\n");
    

    fgets(string, MAX, stdin);
    while (string[count] != '\0')
    {    
        count++;
    }

    end = count - 1;
    middle = count/2;

    for (begin = 0; begin < count; begin++) {
        reverse[begin] = string[end];
        end--;
    }

    reverse[begin] = '\0';

    printf("Your input in reverse is:%s\n", reverse);
    
    l = strlen(string) - 1;
    for (i = 0; i < l / 2; i++) {
        if (string[i] != string[l - i - 1]) {
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        printf("Found a palindrome!\n");
    }
}
