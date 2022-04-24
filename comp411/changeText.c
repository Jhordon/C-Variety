#include <stdio.h>
#include <string.h>
#define MAX_BUF 1024

int main()
{
    char buf[MAX_BUF];
    int i, length;
    
    do
    {
        fgets(buf, MAX_BUF, stdin);
        
        length = strlen(buf) - 1;
        
        if (length == 0) 
            break;

        for (i = 0; buf[i] != '\0'; i++)
        {
            if (buf[i]=='e' || buf[i]=='E')
            {
                buf[i]= '3';
            }

            if (buf[i]=='i' || buf[i]=='I')
            {
                buf[i]= '1';
            }
        
            if (buf[i]=='s' || buf[i]=='S')
            {
                buf[i]= '5';
            }
 
            if (buf[i]=='o' || buf[i]=='O')
            {
                buf[i]= '0';
            }
        }
       printf("%s", buf);
    } while (length > 1);
}
