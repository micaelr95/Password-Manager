#include "access.h"
#include "common.h"
#include <stdio.h>
#include <string.h>

int addaccess(t_resource arr_resource[], int num_ress, t_access arr_access[], int num_acc, int id_user)
{
    char resourcename[NAMESIZE];
    char password[PASSSIZE];
    char verifypassword[PASSSIZE];
    int found = -1;
    int index;
    int validpass = 0;
    clearscreen();
    printf(" -------------------- NOVO ACESSO -------------------- \n");
    printf("Nome do recurso: ");
    getName(resourcename);
    for(index = 0; index < num_ress; index++)
    {
        if(strcmp(arr_resource[index].name, resourcename) == 0)
        {
            found = index;
            break;
        }
    }

    if(found != -1)
    {
        arr_access[num_acc].id = num_acc;
        arr_access[num_acc].idresource = arr_resource[index].id;
        arr_access[num_acc].iduser = id_user;
        arr_access[num_acc].tipo = 0;   // 0 para crição e 1 para alteração
        printf("Nome do utilizador: ");
        getusername(arr_access[num_acc].username);
        do
        {
            printf("Password: ");
            getpassword(password);
            printf("\nVerifique a password: ");
            getpassword(verifypassword);
            if(strcmp(password, verifypassword) == 0)
            {
                validpass = verifySecurity(password, arr_resource[found].grauseguranca);
                if(validpass == 1)
                {
                    strcpy(arr_access[num_acc].password, password);
                }
            }
            else
            {
                printf("\nAs passwords são diferentes. Por favor insira duas passwords iguais.\n");
            }
        }while(validpass==0);
        arr_access[num_acc].data = getDate();
        arr_access[num_acc].hora = getHour();
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
        printf("\nID: %d\n", arr_access[index].id);
        printf("ID Recurso: %d\n", arr_access[index].idresource);
        printf("ID Utilizador: %d\n", arr_access[index].iduser);
        printf("Nome de Utilizador: %s\n", arr_access[index].username);
        printf("Password de Utilizador: %s\n", arr_access[index].password);
        printf("Data: %d/%d/%d\n", arr_access[index].data);
        printf("Hora: %d:%d:%d\n", arr_access[index].hora);
    }
    getch();
}
