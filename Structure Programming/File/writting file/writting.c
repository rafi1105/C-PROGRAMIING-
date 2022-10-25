#include <stdio.h>
int main()
{
    int num;
    FILE *fp;
    fp=fopen("program.txt","w");
    if (fp==NULL)
    {
        printf("Error");
    }
    printf("enter num :");
    scanf("%d",&num);
    fprintf(fp,"%d",num);
    fclose(fp);
    return 0;
}