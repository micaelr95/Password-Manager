#include "common.h"
#include <stdio.h>
#include <stdlib.h>

// Pede o nome do utilizador
void getusername(char *username)
{
    scanf(" %50s", username);
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
            printf("\nPassword inv�lida. Insira uma password com no minimo 8 caracteres.\n");
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
            printf("\nPassword inv�lida. Insira uma password com no minimo 8 caracteres e 1 numero.\n");
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
        if(strlen(nif) != NIFSIZE-1)
        {
            printf("Numero de identifica��o fiscal incorreto. Insira de novo: ");
        }
    }while(strlen(nif) != NIFSIZE-1);
}

void clearscreen(void)
{
    system("@cls||clear");
}

t_date getDate()
{
    t_date i_data;
    do
    {
        printf("\nData (dd/mm/aaaa): ");
        fflush(stdin);
        scanf(" %2d/%2d/%4d", &i_data.dia, &i_data.mes, &i_data.ano);
        if (i_data.dia<01 || i_data.dia>31)
        {
            printf("Dia inv�lido! Insira de novo.\n");
        }
        else if (i_data.mes<01 || i_data.mes>12)
        {
            printf("M�s inv�lido! Insira de novo.\n");
        }
        else if (i_data.ano<1111 || i_data.ano>9999)
        {
            printf("Ano inv�lido! Insira de novo.\n");
        }
    }while(i_data.dia<01 || i_data.dia>31 || i_data.mes<01 || i_data.mes>12 || i_data.ano<1111 || i_data.ano>9999);
    return i_data;
}

t_hour getHour()
{
    t_hour i_hora;
    do
    {
        printf("\nHoras (hh:mm:ss): ");
        fflush(stdin);
        scanf(" %2d:%2d:%2d", &i_hora.hora, &i_hora.minuto, &i_hora.segundo);
        if (i_hora.hora<00 || i_hora.hora>23)
        {
            printf("Hora inv�lida! Insira de novo.\n");
        }
        else if (i_hora.minuto<00 || i_hora.minuto>59)
        {
            printf("Minuto inv�lido! Insira de novo.\n");
        }
        else if (i_hora.segundo<00 || i_hora.segundo>59)
        {
            printf("Segundo inv�lido! Insira de novo.\n");
        }
    }while(i_hora.hora<00 || i_hora.hora>23 || i_hora.minuto<00 || i_hora.minuto>59 || i_hora.segundo<00 || i_hora.segundo>59);
    return i_hora;
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

void saveToFile(t_user arr_users[], int users_index, int users_ID_count, t_resource arr_resources[], int resources_index, int resources_ID_count, t_access arr_access[], int access_index, int access_ID_count)
{
    FILE *file;
    file = fopen("data.dat", "wb");
    if(file == NULL)
    {
        printf("Erro ao criar o ficheiro");
    }
    else
    {
        fwrite(&users_index, sizeof(int), 1, file);
        fwrite(&resources_index, sizeof(int), 1, file);
        fwrite(&access_index, sizeof(int), 1, file);
        fwrite(&users_ID_count, sizeof(int), 1, file);
        fwrite(&resources_ID_count, sizeof(int), 1, file);
        fwrite(&access_ID_count, sizeof(int), 1, file);
        fwrite(arr_users, sizeof(t_user), users_index, file);
        fwrite(arr_resources, sizeof(t_resource), resources_index, file);
        fwrite(arr_access, sizeof(t_access), access_index, file);
        fclose(file);
    }
}

int readFromFile(t_user arr_users[], int *users_index, int *users_ID_count, t_resource arr_resources[], int *resources_index, int *resources_ID_count, t_access arr_access[], int *access_index, int *access_ID_count)
{
    int status = 0;
    FILE *file;
    file = fopen("data.dat", "rb");
    if(file == NULL)
    {
        printf("Erro ao criar o ficheiro");
        status = 1;
    }
    else
    {
        fread(&(*users_index), sizeof(int), 1, file);
        fread(&(*resources_index), sizeof(int), 1, file);
        fread(&(*access_index), sizeof(int), 1, file);
        fread(&(*users_ID_count), sizeof(int), 1, file);
        fread(&(*resources_ID_count), sizeof(int), 1, file);
        fread(&(*access_ID_count), sizeof(int), 1, file);
        fread(arr_users, sizeof(t_user), *users_index, file);
        fread(arr_resources, sizeof(t_resource), *resources_index, file);
        fread(arr_access, sizeof(t_access), *access_index, file);
        fclose(file);
    }
    return status;
}
