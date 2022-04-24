
#include <stdio.h>

int main()
{
  int num;
  char* ending;
  printf("Enter a number from 1 to 20:\n");
  scanf("%i", &num);

  if (num >= 1 && num <= 20) {
	printf("Here are the first %i ordinal numbers:\n", num);
	for (int i = 1; i <= num; i++) {
		if (i == 1) {
			ending = "st";
		} else if (i == 2) {
			ending = "nd";
		} else if (i == 3) {
			ending = "rd";
		} else {
			ending = "th";
		}
		printf("%i%s\n", i, ending);
	}

  }  else {
	printf("Number is not in the range from 1 to 20\n");
  }
}

// normal if, print statement then for loop with the switch cases


/*
  switch (i)
    case i is 1
      set to "st"
      break
    case i is 2
      set to "nd"
      break
    case i is 3
      set to "rd"
      break
    default
      set to "th"

  since range is only 1 to 20, it wont matter about the 20+ values
*/

/* switch (expression)
    {
    case constant1:
      // statements
      break;
    case ...
      ...
      break;
    default:
      // statements
  }
*/
