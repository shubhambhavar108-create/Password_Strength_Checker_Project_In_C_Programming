#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char password[100];
    int i;
    int Uppercase = 0, Lowercase = 0, Digit = 0, Symbol = 0;
    int score = 0;
    int strongFlag = 0;

    printf("=================================================\n");
    printf("              PASSWORD STRENGTH CHECKER         \n");
    printf("=================================================\n");

    printf("\nEnter your password: ");
    scanf("%s", password);

    int length = strlen(password);

    // NULL / Empty Check
    if(length == 0)
    {
        printf("\nPassword cannot be NULL\n");
        return 0;
    }

    // Character Checking
    for(i = 0; password[i] != '\0'; i++)
    {
        if(isupper(password[i])) Uppercase = 1;
        else if(islower(password[i])) Lowercase = 1;
        else if(isdigit(password[i])) Digit = 1;
        else if(ispunct(password[i])) Symbol = 1;
    }

    score = Uppercase + Lowercase + Digit + Symbol;

    printf("\n------------------ ANALYSIS ---------------------\n");
    printf("Password Length : %d characters\n", length);
    printf("Strength Score  : %d / 4\n", score);
    printf("-------------------------------------------------\n\n");

    if(length >= 12 && score == 4)
    {
        printf("Result : VERY STRONG PASSWORD\n");
        strongFlag = 1;
    }
    else if(length >= 8 && score == 4)
    {
        printf("Result : STRONG PASSWORD\n");
        strongFlag = 1;
    }
    else if(score == 3)
    {
        printf("Result : MEDIUM PASSWORD\n");
    }
    else
    {
        printf("Result : WEAK PASSWORD\n");
    }

    printf("\nSuggestions:\n");

    if(strongFlag)
    {
        printf("No suggestions required.\n");
        printf("Good Job! Your password is secure.\n");
    }
    else
    {
        if(!Uppercase) printf("- Add at least one Uppercase letter\n");
        if(!Lowercase) printf("- Add at least one Lowercase letter\n");
        if(!Digit)     printf("- Add at least one Number\n");
        if(!Symbol)    printf("- Add at least one Symbol\n");
        if(length < 8) printf("- Increase password length\n");
    }

    printf("\n=================================================\n");
    printf("        Thank You For Using The Project         \n");
    printf("-------------------------------------------------\n");
    printf("Created By :\n");
    printf("- Abhijeet\n");
    printf("- Shubham\n");
    printf("- Archit\n");
    printf("- Yuvraj\n");
    printf("\n=================================================\n");

    return 0;
}