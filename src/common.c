#include "common.h"
#include <stdio.h>
#include <stdlib.h>

// Pede o nome do utilizador
void getusername(char *username)
{
    printf("Nome do utilizador: ");
    scanf(" %s", username);
}

// Pede a palavra passe ao utilizador
void getpassword(char *password)
{
    char passwordchar;
    int currentindex=0;

    printf("Password: ");
    do
    {
        passwordchar = getch();
        if(passwordchar!=13)
        {
            printf("*");
            password[currentindex] = passwordchar;
            currentindex++;
        }
    }while(passwordchar!=13 && currentindex<PASSSIZE-1);
}

void clearscreen(void)
{
    system("@cls||clear");
}
