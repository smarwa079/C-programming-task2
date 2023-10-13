#include <stdio.h>
#include <string.h>

char userName[25];
int password;

void login();

void registeration(){
    printf("\n###########################################################################\n");
    printf("Register\n");

    
    printf("Enter your name: ");
    scanf("%s", userName);

    printf("\nEnter your password: ");
    scanf("%d", &password);
    
    login();  
    
    
    return;

}

void login(){
    printf("\nLogin\n");

    char nameOfUser[25];
    int userPassword;
    int comp;
    
    printf("Enter your name: ");
    scanf("%s", nameOfUser);

    printf("\nEnter your password: ");
    scanf("%d", &userPassword);
    
    comp = strcmp(userName , nameOfUser);

    if(comp == 0 &&  password == userPassword){
        printf("login successfully, welcome");
        return;
    } else if (comp != 0 &&  password == userPassword)
    {
        printf("userName is incorrect, try again");
        login();
    } else if (comp == 0 &&  password != userPassword)
    {
        printf("password is incorrect, try again");
        login();
    } else
    {
        printf("userName and password are incorrect, create an account\n");
        registeration();   
    }  

}


int main(){

    login();

    // printf("name %s, password %d", userName, password);
    


    return 0;
}