#include <stdio.h>
#include <string.h>

void teste2(){
    char *pt = strtok(NULL, " ");
    printf("%s\n", pt);
}

void teste(){
    char *pt = strtok(NULL, " ");
    printf("%s\n", pt);
    teste2();
}

int main(){
    char string[50] = {"Oii tudo bem"};
    char *pt = strtok(string, " ");

    printf("%s\n", pt);
    teste();
    

    return 0;
}
