#include <stdio.h>
int main(){
    int out[300],i;
    FILE *fRead = fopen("inputText.txt","r");
    char str[300];
    while (!feof(fRead)){
        fgets(str,300,fRead);
    }
    for(i=0;str[i]!= '\0';i++){
        out[i] = str[i] -7;
        printf("%c",out[i]);
    }
    return 0;
}