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
    printf("Numero de identifica��o fiscal: ");
    scanf(" %10[^\n]", nif);
}

void clearscreen(void)
{
    system("@cls||clear");
}

void getDate(t_date i_data)
{
    scanf(" %2d/%2d/%4d", i_data.dia, i_data.mes, i_data.ano);
}

void getHour(t_hour i_hora)
{
    scanf(" %2d:%2d:%2d", i_hora.hora, i_hora.minuto, i_hora.segundo);
}

void getSecurity(int *security)
{
    printf("Insira um grau de seguran�a (1 - Baixo, 2 - M�dio, 3 - Elevado): ");
    do{
        scanf(" %d", security);
        if (security <1 && security>3){
            printf("Por favor insira (1 - Baixo, 2 - M�dio, 3 - Elevado) ");
        }
    }while(security <1 && security>3);
}
