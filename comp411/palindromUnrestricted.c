#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 1000 /* The maximum number of characters in a line of input */

int main()
{
    char string[MAX], reverse[MAX], temp[MAX];
    int k, j, i, l, flag = 0, begin, middle, end, count = 0; 
    
    printf("Type some text (then ENTER):\n");
    
    fgets(string, MAX, stdin);
    
    // DO NOT TOUCH         
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



    for(i = 0; string[i] != '\0'; ++i)
    {
    while (!( (string[i] >= 'a' && string[i] <= 'z') || (string[i] >= 'A' && string[i] <= 'Z') || string[i] == '\0') )
          {
              for(j = i; string[j] != '\0'; ++j)
              {
                  string[j] = string[j+1];
              }
                   string[j] = '\0';
          }
          string[i] = tolower(string[i]);
      }




    // DETERMINING PALIDROME SENTENCES


    l = strlen(string);
    for (k = 0; k < l / 2; k++) {
        if (string[k] != string[l - k - 1]) {
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        printf("Found a palindrome!\n");
    }
}
