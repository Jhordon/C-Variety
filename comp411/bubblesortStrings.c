/* Example: bubble sort strings in array */

#include <stdio.h>  /* Need for standard I/O functions */
#include <string.h> /* Need for strlen() */


#define NUM 25   /* number of strings */
#define LEN 1000  /* max length of each string */


int my_compare_strings(char string1[], char string2[]) {

  /* Write code here to compare string1 and string2, character by character.
     WITHOUT USING ANY C STRING LIBRARY FUNCTIONS.

     The max length of the strings is LEN, though they may be shorter so look
     for the string terminators.

     This function should return:
      -1 if string1 comes before string2 in alphabetical order
       0 if string1 is the same as string2
      +1 if string1 comes after string2 in alphabetical order

      Here, alphabetical order is defined simply by the numerical value
      of the characters in the string, from left to right.  See the writeup
      for more details.
  */
  int i;
  for (i = 0; i < LEN; i++) {
    if (string1[i] > string2[i]) {
      return 1;
    } else if (string1[i] < string2[i]) {
      return -1;
    } else {
      continue;
    }
  }
}


void my_swap_strings(char string1[], char string2[]) {
  char temp;
  int i;
  for (i = 0; i < LEN; i++) {
    temp = string1[i];
    string1[i] = string2[i];
    string2[i] = temp;
  }
}


int main()
{
  char Strings[NUM][LEN];
  int i, j;
  printf("Please enter %d strings, one per line:\r\n", NUM);
  for (i = 0; i < NUM; i++) {
      fgets(Strings[i], LEN, stdin);
  }
  puts("\r\nHere are the strings in the order you entered:\r");
  for (i = 0; i < NUM; i++) {
      printf("%s", Strings[i]);
  }


  /* Bubble sort */
  /* Write code here to bubble sort the strings in ascending alphabetical order

     Use the function my_compare_strings() to compare two strings.  If they are out of order,
     use the function my_swap_strings() to swap their contents.

  */
  for (i = 0; i < NUM; i++) {
      for (j = 0; j < NUM - i - 1; j++) {
        if (my_compare_strings(Strings[j], Strings[j + 1]) > 0) {
          my_swap_strings(Strings[j], Strings[j + 1]);
        }
      }
  }


  puts("\r\nIn alphabetical order, the strings are:\r");
  for (i = 0; i < NUM; i++) {
      printf("%s", Strings[i]);
  }
}
