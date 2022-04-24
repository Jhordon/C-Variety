#include <stdio.h>  /* Need for standard I/O functions */
#include <string.h> /* Need for strlen() */
#define NUM 25   /* number of strings */
#define LEN 1000  /* max length of each string */

// strcmp()
// strcpy()

int main()
{
  char Strings[NUM][LEN], temp[NUM][LEN];
  int i, j;

  printf("Please enter %d strings, one per line:\r\n", NUM);

  /* Write a for loop here to read NUM strings.

     Use fgets(), with LEN as an argument to ensure that an input line that is too
     long does not exceed the bounds imposed by the string's length.  Note that the
     newline and NULL characters will be included in LEN.
  */
  for (i = 0; i < NUM; i++) {
      fgets(Strings[i], LEN, stdin);
  }

  puts("\r\nHere are the strings in the order you entered:\r");

  /* Write a for loop here to print all the strings. */
  for (i = 0; i < NUM; i++) {
      printf("%s", Strings[i]);
  }

  // sort here with strcmp and strcpy
  for (i = 0; i < NUM; i++) {
    for (j = 0; j < NUM - i - 1; j++) {
      if (strcmp(Strings[j], Strings[j+1]) > 0) {
        strcpy(temp[j], Strings[j]);
        strcpy(Strings[j], Strings[j+1]);
        strcpy(Strings[j+1], temp[j]);
      }
    }
  }


  /* Output sorted list */
  puts("\r\nIn alphabetical order, the strings are:\r");
  /* Write a for loop here to print all the strings. Feel free to use puts/printf
     etc. for printing each string.
  */
  for (i = 0; i < NUM; i++) {
      printf("%s", Strings[i]);
  }
}
