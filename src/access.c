#include "access.h"
#include "common.h"
#include <stdio.h>
#include <string.h>

void addaccess(t_resource arr_resource[], int num_ress, t_access arr_access[], int *num_acc, int *acc_ID_count, int id_user, t_user arr_users[], int user_index)
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
        arr_access[*num_acc].id = *acc_ID_count;
        arr_access[*num_acc].idresource = arr_resource[found].id;
        arr_access[*num_acc].iduser = id_user;
        arr_access[*num_acc].tipo = 0;   // 0 para crição e 1 para alteração
        printf("Nome do utilizador: ");
        getusername(arr_access[*num_acc].username);
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
                    strcpy(arr_access[*num_acc].password, password);
                }
            }
            else
            {
                printf("\nAs passwords são diferentes. Por favor insira duas passwords iguais.\n");
            }
        }while(validpass==0);
        arr_access[*num_acc].data = getDate();
        arr_access[*num_acc].hora = getHour();
        arr_resource[found].num_access+=1;
        for(int i = 0; i < user_index; i++)
        {
            if(arr_users[i].id == id_user)
            {
                arr_users[*num_acc].num_access+=1;
            }
        }
        *num_acc+=1;
        *acc_ID_count+=1;
        printf("\nAcesso adicionado com sucesso!");
    }
    else
    {
        printf("\nEste recurso não existe!");
    }
    getch();
}

void viewaccess(t_resource arr_resource[], int num_ress, t_access arr_access[], int num_acc, int id_user)
{
    char resourcename[NAMESIZE];
    int resource_found = 0;
    clearscreen();
    printf(" -------------------- LISTA DE ACESSOS -------------------- \n");
    printf("Nome do recurso: ");
    scanf(" %s", resourcename);
    // Procura o recurso pelo nome
    for(int i = 0; i < num_ress; i++)
    {
        if(strcmp(arr_resource[i].name, resourcename) == 0)
        {
            resource_found = 1;
            for(int index = 0; index < num_acc; index++)
            {
                // Apenas mostra os acessos com o ID do recurso pretendido e com o ID do utilizador logado
                if(arr_access[index].idresource == arr_resource[i].id  && arr_access[index].iduser == id_user)
                {
                    printf("\n-----------------------------------------------------");
                    printf("\nID Acesso: %d", arr_access[index].id);
                    printf("\nID Recurso: %d", arr_access[index].idresource);
                    printf("\nID Utilizador: %d", arr_access[index].iduser);
                    printf("\nNome de Utilizador: %s", arr_access[index].username);
                    printf("\nPassword de Utilizador: %s", arr_access[index].password);
                    printf("\nData: %d/%d/%d", arr_access[index].data);
                    printf("\nHora: %d:%d:%d\n", arr_access[index].hora);
                }
                else
                {
                    printf("O utilizador não tem acessos para este recurso.");
                }
            }
        }
    }

    if(resource_found == 0)
    {
        printf("Recurso não encontrado.");
    }
    getch();
}

void deleteAccess(t_resource arr_resource[], int num_ress, t_access arr_access[], int *access_index, int id_user, t_user arr_users[], int user_index)
{
    char resourceName[NAMESIZE];
    int resource_found = -1;
    int access_found = -1;
    int removeID;
    clearscreen();
    printf(" -------------------- REMOVER ACESSO -------------------- \n");
    printf("Nome do recurso: ");
    getName(resourceName);

    // Procura o recurso pelo nome
    for(int index = 0; index < num_ress; index++)
    {
        if(strcmp(arr_resource[index].name, resourceName) == 0)
        {
            resource_found = index;
            for(int j = 0; j < *access_index; j++)
            {
                // Apenas mostra os acessos com o ID do recurso pretendido e com o ID do utilizador logado
                if(arr_access[j].idresource == arr_resource[index].id && arr_access[j].iduser == id_user)
                {
                    printf("\n-----------------------------------------------------");
                    printf("\nID Acesso: %d", arr_access[j].id);
                    printf("\nID Recurso: %d", arr_access[j].idresource);
                    printf("\nID Utilizador: %d", arr_access[j].iduser);
                    printf("\nNome de Utilizador: %s", arr_access[j].username);
                    printf("\nPassword de Utilizador: %s", arr_access[j].password);
                    printf("\nData: %d/%d/%d", arr_access[j].data);
                    printf("\nHora: %d:%d:%d\n", arr_access[j].hora);
                }
            }

            printf("\nID do acesso a eliminar: ");
            scanf(" %d", &removeID);

            for (int i = 0; i < *access_index; i++)
            {
                if(arr_access[i].id == removeID && arr_access[i].iduser == id_user)
                {
                    access_found = i;
                    for(int j = i; j < *access_index; j++)
                    {
                        arr_access[j].id = arr_access[j+1].id;
                        arr_access[j].idresource = arr_access[j+1].idresource;
                        arr_access[j].iduser = arr_access[j+1].iduser;
                        arr_access[j].tipo = arr_access[j+1].tipo;
                        strcpy(arr_access[j].username, arr_access[j+1].username);
                        strcpy(arr_access[j].password, arr_access[j+1].password);
                        arr_access[j].data = arr_access[j+1].data;
                        arr_access[j].hora = arr_access[j+1].hora;
                    }
                    *access_index -=1;
                    arr_resource[resource_found].num_access -=1;

                    for(int i = 0; i < user_index; i++)
                    {
                        if(arr_users[i].id == id_user)
                        {
                            arr_users[i].num_access-=1;
                        }
                    }

                    printf("Acesso %s eliminado.", resourceName);
                }
            }
        }
    }

    if(resource_found == -1)
    {
        printf("Recurso não encontrado.");
    }
    if(access_found == -1)
    {
        printf("ID inválido\n");
    }

    getch();
}
