#include <stdio.h>

int main()
{
    int a [300];
    int i,
    FILE *read=fopen("e.txt","r");
    char sr[300];
    while(!feof(fread))
    {
        fgets(sr,300,fread);
    }
    fclose(FILE *fread);

            for(i=0;sr[i]!='\0';i++)
            {
                a[i] = sr[i]-7;
                printf("%c",a[i]);

            }

    }
