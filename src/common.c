#include "common.h"
#include <stdio.h>
#include <stdlib.h>

// Pede o nome do utilizador
void getusername(char *username)
{
    printf("Nome do utilizador: ");
    scanf(" %20s", username);
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
    password[currentindex++] = '\0';
}

void getName(char *name)
{
    printf("Nome: ");
    scanf(" %30[^\n]", name);
}

void getNIF(char *nif)
{
    printf("Numero de identificação fiscal: ");
    scanf(" %10[^\n]", nif);
}

void clearscreen(void)
{
    system("@cls||clear");
}
