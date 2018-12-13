#include "access.h"
#include "common.h"
#include <stdio.h>
#include <string.h>

int addaccess(t_resource arr_resource[], int num_ress, t_access arr_access[], int num_acc, int id_user)
{
    char resourcename[NAMESIZE];
    int found = 0;
    int index;
    clearscreen();
    printf(" -------------------- NOVO ACESSO -------------------- \n");
    printf("Recurso ");
    getName(resourcename);
    for(index = 0; index < num_ress; index++)
    {
        if(strcmp(arr_resource[index].name, resourcename) == 0)
        {
            found = 1;
            break;
        }
    }


    char username[USERNAMESIZE];
    char password[PASSSIZE];


    if(found == 1)
    {
        arr_access[num_acc].id = num_acc;
        arr_access[num_acc].idresource = arr_resource[index].id;
        arr_access[num_acc].iduser = id_user;
        arr_access[num_acc].tipo = 0;   // 0 para criação e 1 para alteração
        getusername(arr_access[num_acc].username);
        getpassword(arr_access[num_acc].password);
        getDate(arr_access[num_acc].date);
        getHour(arr_access[num_acc].hora);
        num_acc+=1;
        printf("\nAcesso adicionado com sucesso!");
    }
    else
    {
        printf("\nEste recurso não existe!");
    }
    getch();
    return num_acc;
}

void viewaccess(t_access arr_access[], int num_acc)
{
    clearscreen();
    printf(" -------------------- LISTA DE ACESSOS -------------------- \n");
    for(int index = 0; index < num_acc; index++)
    {
        printf("ID: %d\n", arr_access[index].id);
        printf("ID Recurso: %d\n", arr_access[index].idresource);
        printf("ID Utilizador: %d\n", arr_access[index].iduser);
        printf("Nome de Utilizador: %s\n", arr_access[index].username);
        printf("Password de Utilizador: %s\n", arr_access[index].password);
    }
    getch();
}
