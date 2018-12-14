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

int verifySecurity(char password[], int security)
{
    int valid = 0;
    int numcount = 0;
    printf("Grau de seguran�a: %d", security);
    if(security == 1)
    {

        if(strlen(password) > 8)
        {
            valid = 1;
        }
        else
        {
            printf("\nPassword inv�lida. Insira uma password com no minimo 8 caracteres.\n");
        }
    }
    else if(security == 2)
    {
        for(int i = 0; i < strlen(password); i++)
        {
            if(isdigit(password[i]) == 0)
            {
                numcount++;
            }
        }

        if(strlen(password) > 8 && numcount > 1)
        {
            valid = 1;
        }
        else
        {
            printf("\nPassword inv�lida. Insira uma password com no minimo 8 caracteres e 1 numero.\n");
        }
    }
    else if(security==3)
    {
        for(int i = 0; i < strlen(password); i++)
        {
            if(isdigit(password[i]) == 0)
            {
                numcount++;
            }
        }
        if(strlen(password) > 8 && numcount > 1 && strspn(password, "~!@#$%^&*()_-+=")>1)
        {
            valid = 1;
        }
        else
        {
            printf("\nPassword inv�lida. Insira uma password com no minimo 8 caracteres e 1 numero e 1 caracter especial.\n");
        }
    }
    return valid;
}

void getName(char *name)
{
    scanf(" %30[^\n]", name);
}

void getNIF(char *nif)
{
    printf("Numero de identifica��o fiscal: ");
    do
    {
        fflush(stdin);
        scanf(" %s", nif);
        if(strlen(nif) != NIFSIZE)
        {
            printf("Numero de identifica��o fiscal incorreto. Insira de novo: ");
        }
    }while(strlen(nif) != NIFSIZE);
}

void clearscreen(void)
{
    system("@cls||clear");
}

t_date getDate()
{
    t_date i_data;
    printf("Data (dd/mm/aaaa): ");
    scanf(" %2d/%2d/%4d", &i_data.dia, &i_data.mes, &i_data.ano);
}

t_hour getHour()
{
    t_hour i_hora;
    printf("Horas (hh:mm:ss): ");
    scanf(" %2d:%2d:%2d", &i_hora.hora, &i_hora.minuto, &i_hora.segundo);
}

void getSecurity(int *security)
{
    printf("Insira um grau de seguran�a (1 - Baixo, 2 - M�dio, 3 - Elevado): ");
    do{
        scanf(" %d", security);
        if (*security <1 && *security>3){
            printf("Por favor insira (1 - Baixo, 2 - M�dio, 3 - Elevado) ");
        }
    }while(*security <1 && *security>3);
}
