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
        if(passwordchar==8 && currentindex>0) // 8 tecla apagar (backspace)
        {
            // '\b' apaga caracter da consola depois mete um espaco para apagar
            printf("\b \b");
            currentindex--;

        }
        else if(passwordchar!=13)   // 13 tecla enter
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
    int numspecialchar = 0;
    if(security == 1)
    {

        if(strlen(password) >= 8)
        {
            valid = 1;
        }
        else
        {
            printf("\nPassword inválida. Insira uma password com no minimo 8 caracteres.\n");
        }
    }
    else if(security == 2)
    {
        for(int i = 0; i < strlen(password); i++)
        {
            if(isdigit(password[i]))
            {
                numcount++;
            }
        }

        if(strlen(password) >= 8 && numcount >= 1)
        {
            valid = 1;
        }


        else
        {
            printf("\nPassword inválida. Insira uma password com no minimo 8 caracteres e 1 numero.\n");
        }
    }
    else if(security==3)
    {
        for(int i = 0; i < strlen(password); i++)
        {
            if(isdigit(password[i]))
            {
                numcount++;
            }
        }
        for(int i = 0; i < strlen(password); i++)
        {
            if(ispunct(password[i]))
            {
                numspecialchar++;
            }
        }
        if(strlen(password) >= 8 && numcount >= 1 && numspecialchar>=1)
        {
            valid = 1;
        }
        else
        {
            printf("\nPassword inválida. Insira uma password com no minimo 8 caracteres e 1 numero e 1 caracter especial.\n");
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
    printf("Numero de identificação fiscal: ");
    do
    {
        fflush(stdin);
        scanf(" %s", nif);
        if(strlen(nif) != NIFSIZE)
        {
            printf("Numero de identificação fiscal incorreto. Insira de novo: ");
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
    return i_data;
}

t_hour getHour()
{
    t_hour i_hora;
    printf("Horas (hh:mm:ss): ");
    scanf(" %2d:%2d:%2d", &i_hora.hora, &i_hora.minuto, &i_hora.segundo);
    return i_hora;
}

void getSecurity(int *security)
{
    printf("Insira um grau de segurança (1 - Baixo, 2 - Médio, 3 - Elevado): ");
    do{
        scanf(" %d", security);
        if (*security <1 && *security>3){
            printf("Por favor insira (1 - Baixo, 2 - Médio, 3 - Elevado) ");
        }
    }while(*security <1 && *security>3);
}
