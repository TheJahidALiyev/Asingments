#include <stdio.h>
void swapStrings(char **destination, char **source);

int main(){
        char *str1 = "computer";
        char *str2 = "laptop";
        printf("str1: %s, str2: %s\n",str1,str2);
        swapStrings(&str1,&str2);
        printf("str1: %s, str2: %s\n",str1,str2);

        return 0;
}

void swapStrings(char **destination, char **source){
        char *temp = *destination;
        *destination = *source;
        *source = temp;
}
