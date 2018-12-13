#include "common.h"
#include <stdio.h>
#include <stdlib.h>

// Pede o nome do utilizador
void getusername(char *username)
{
    scanf(" %20s", username);
}

// Pede a palavra passe ao utilizador
void getpassword(char *password)
{
    char passwordchar;
    int currentindex=0;
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
    scanf(" %30[^\n]", name);
}

void getNIF(char *nif)
{
    printf("Numero de identificação fiscal: ");
    scanf(" %8[^\n]", nif);
}

void clearscreen(void)
{
    system("@cls||clear");
}
