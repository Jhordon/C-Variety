1 #include <stdio.h>
2 #include <string.h>
3
4 char animals[20][15];
5 char lyrics[20][60];
6 int  number;
7
8 void nurseryrhyme(int current)
9 {
10
11
12     if (number == -1) {
13         return;
14     }
15  printf("%*s", current, "");
16 if (current == number) {
17         printf("I don't know why she swallowed a %s - %s\n", animals[current], lyrics[current]);
18         number--;
19         nurseryrhyme(number);
20     } else if (current == 0) {
21         printf("There was an old lady who swallowed a %s;\n", animals[current]);
22     } else if (current > 0) {
23         printf("She swallowed the %s to catch the %s;\n", animals[current - 1], animals[current]);
24             if (current == number - 1) {
25                 printf("%*s", current, "");
26                 printf("I don't know why she swallowed a %s - %s\n", animals[current], lyrics[current]);
27                 number -= 2;
28                 nurseryrhyme(number);
29             }
30     }
31
32     if(current < number-1)
33         nurseryrhyme(current+1);
34 }
35
36 int main() {
37   int i=0;
38
39   while (1)
40   {
41     fgets(animals[i], 15, stdin);
42         if (strcmp(animals[i], "END\n") == 0){
43  animals[i][strlen(animals[i])-1] = '\0';
44
45         break;
46 }
47     animals[i][strlen(animals[i])-1] = '\0';
48     fgets(lyrics[i], 60, stdin);
49     lyrics[i][strlen(lyrics[i])-1] = '\0';
50     i++;
51   }
52
53   number = i;
54
55   nurseryrhyme(0);
56
57 }
58
