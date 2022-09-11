#include<stdio.h>
int Input_Number();
char character_extractor(char ch);
void password_generator(char password[5], int i, char ex);

int main()
{
    int num, i;
    num = Input_Number();
    if (num==0)
    printf("Wrong Input");
    else
    {
        char sNum[5], password[5];
        char extracted;
        sprintf(sNum, "%d", num);
        for(i=0; i<5; i++)
        {
            extracted = character_extractor(sNum[i]);
            password_generator(password,i,extracted);
        }
        printf("Password is %s", password);
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

char character_extractor(char ch)
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

void password_generator(char password[5], int i, char ex)
{
    password[i]=ex;
}