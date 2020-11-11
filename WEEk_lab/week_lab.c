#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void function(char *source, char *integers, char *nonintegers)
{
	int nonint=0, number=0;
	for(int i=0; source[i] !='\0'; i++)
	{
	if(source[i] >=48 && source[i] <=57)
        {
        	integers[number]=source[i];
                number++;
        }else{
        	nonintegers[nonint] = source[i];
                nonint++;
        }
        integers[number] = '\0';
        nonintegers[nonint] = '\0';
	}
}
int main()
{
 
	char source[] = "abc123def99!";
	char integers[256];
	char nonintegers[256];
        function(source, integers, nonintegers);
        printf("source is %s\n", source);
        printf("nonintegers are %s\n", nonintegers);
        printf("integers are %s\n", integers);
        return 0; 
}

