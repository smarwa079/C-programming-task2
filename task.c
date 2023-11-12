#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    char userName[25];
    int password;
    union
    {
        int numericFlag;
        bool booleanFlage;
    } active;

} User;

User newUser;
char activeFlage[25];

void login();

void registeration()
{
    printf("Register\n");

    printf("Enter your name: ");
    scanf("%s", newUser.userName);

    printf("\nEnter your password: ");
    scanf("%d", &newUser.password);

    printf("\nYou are active or not: ");
    scanf("%s", &activeFlage);

    if (strcmp(activeFlage, "true") == 0)
    {
        newUser.active.booleanFlage = true;
        login();
    }
    else if (strcmp(activeFlage, "1") == 0)
    {
        newUser.active.numericFlag = 1;
        printf("\nSuccessfully registered, you are active :) \n");
        login();
    }
    else
    {
        newUser.active.booleanFlage = false;
        newUser.active.numericFlag = 0;
        printf("\nYou are not active, you are disabled :(\n");
    }

    return;
}

void login()
{
    printf("\n###########################################################################\n");
    printf("\nLogin\n");

    char nameOfUser[25];
    int userPassword;
    int comp;

    printf("Enter your name: ");
    scanf("%s", nameOfUser);

    printf("\nEnter your password: ");
    scanf("%d", &userPassword);

    comp = strcmp(newUser.userName, nameOfUser);

    if ((newUser.active.booleanFlage == true) || (newUser.active.numericFlag == 1))
    {
        if (comp == 0 && newUser.password == userPassword)
        {
            printf("login successfully, welcome");
            return;
        }
        else if (comp != 0 && newUser.password == userPassword)
        {
            printf("userName is incorrect, try again");
            login();
        }
        else if (comp == 0 && newUser.password != userPassword)
        {
            printf("password is incorrect, try again");
            login();
        }
        else
        {
            printf("userName and password are incorrect, create an account\n");
            registeration();
        }
    }
    
}

int main()
{

    registeration();

    // printf("name %s, password %d", userName, password);

    return 0;
}