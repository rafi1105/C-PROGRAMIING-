#include<stdio.h>
int Input_Number();
char character1(char ch);
void p_generator(char password[5], int i, char ex);

int main()
{
    int num, i;
    num = Input_Number();
    if (num==0)
    printf("Wrong Input");
    else
    {
        char number[5], password[5];
        char extracted;
        printf(number, "%d", num);
        for(i=0; i<5; i++)
        {
            extracted = character1(number[i]);
            p_generator(password,i,extracted);
        }
        printf(" Encypted Password is %s", password);
    }
    return 0;
}

int Input_Number()
{
    int num;
    printf("Enter a 5 digit Number: ");
    scanf("%d", &num);
    if(num>=10000 && num<=99999)
    return num;
    else return 0;
}

char character1(char ch)
{
    switch(ch)
    {
        case '0': 
                    return '?'; 
                    break;

        case '1': 
                    return '#'; 
                    break;

        case '2': 
                    return 'a'; 
                    break;

        case '3': 
                    return 't'; 
                    break;

        case '4': 
                    return 'j'; 
                    break;

        case '5': 
                    return '9'; 
                    break;

        case '6': 
                    return 'E'; 
                    break;

        case '7': 
                    return '@'; 
                    break;

        case '8': 
                    return '2'; 
                    break;

        case '9': 
                    return 'F'; 
                    break;
    }
}

void p_generator(char password[5], int i, char ex)
{
    password[i]=ex;
}