#include <stdio.h>
#include <locale.h>
#include "common.h"
#include "users.h"
#include "resources.h"
#include "access.h"

int menulogin(t_user arr_users[], int *num_users, t_resource arr_resources[], int *resources_index, t_access arr_access[], int *access_index);
void menuresources(t_resource arr_resources[], int *num_resources);
void menuaccess(t_resource arr_resources[], int *num_resources, t_access arr_access[], int *num_access, int num_user);

int main()
{
    t_user users[MAX_USERS];
    int userindex = 0;
    t_resource resources[MAX_RESOURCES];
    int resourceindex = 0;
    t_access access[MAX_ACCESS];
    int accessindex = 0;
    int opcao;
    int usernum = 0;

    setlocale(LC_ALL, "");

    usernum = menulogin(users, &userindex, resources, &resourceindex, access, &accessindex);
    if (usernum != -1)
    {
        do
        {
            clearscreen();
            printf(" -------------------- MENU PRINCIPAL -------------------- \n");
            printf("[1] Recursos\n");
            printf("[2] Acessos\n");
            printf("[3] Informações do Utilizador\n");
            printf("[4] Guardar Dados\n");
            printf("\n[0] Sair\n");
            opcao = getch();
            switch (opcao)
            {
                case '1':
                    menuresources(resources, &resourceindex);
                    break;
                case '2':
                    menuaccess(resources, &resourceindex, access, &accessindex, usernum);
                    break;
                case '3':
                    showUser(users, usernum);
                    break;
                case '4':
                    clearscreen();
                    saveToFile(users, userindex, resources, resourceindex, access, accessindex);
                    printf("\nDados gravados\n");
                    getch();
                    break;
            }
        }while(opcao!='0');
    }
    return 0;
}

int menulogin(t_user arr_users[], int *num_users, t_resource arr_resources[], int *resources_index, t_access arr_access[], int *access_index)
{

    int opcao;
    int usernum = -1;
    int users = 0, resources = 0, access = 0;
    readFromFile(arr_users, &(*num_users), arr_resources, &(*resources_index), arr_access, &(*access_index));
    showUser(arr_users, users);
    do
    {
        clearscreen();
        printf("Numero de utilizadores: %d", users);
        printf("Numero de utilizadores: %d", *num_users);
        printf(" -------------------- MENU LOGIN -------------------- \n");
        printf("[1] Login\n");
        printf("[2] Criar Conta\n");
        printf("\n[0] Sair\n");
        opcao = getch();
        switch (opcao)
        {
            case '1':
                usernum = login(arr_users, *num_users);
                if(usernum == -1)
                {
                    printf("\nCredenciais erradas! Por favor tente de novo.");
                    getch();
                }
                else if(usernum == -2)
                {
                    printf("\nConta de utilizador não existente.");
                    getch();
                }
                break;
            case '2':
                *num_users = addUser(arr_users, *num_users);
                break;
        }
    }while(opcao!='0' && usernum < 0);
    return usernum;
}

void menuresources(t_resource arr_resources[], int *num_resources)
{
    int opcao;
    do
    {
        clearscreen();
        printf(" -------------------- MENU RECURSOS -------------------- \n");
        printf("[1] Adicionar\n");
        printf("[2] Ver\n");
        printf("\n[0] Voltar\n");
        opcao = getch();
        switch (opcao)
        {
            case '1':
                *num_resources = addResource(arr_resources, *num_resources);
                break;
            case '2':
                viewResource(arr_resources, *num_resources);
                break;
        }
    }while(opcao!='0');
}

void menuaccess(t_resource arr_resources[], int *num_resources, t_access arr_access[], int *num_access, int num_user)
{
    int opcao;
    do
    {
        clearscreen();
        printf(" -------------------- MENU ACESSOS -------------------- \n");
        printf("[1] Adicionar\n");
        printf("[2] Ver\n");
        printf("\n[0] Voltar\n");
        opcao = getch();
        switch (opcao)
        {
            case '1':
                *num_access = addaccess(arr_resources, *num_resources, arr_access, *num_access, num_user);
                break;
            case '2':
                viewaccess(arr_resources, *num_resources, arr_access, *num_access, num_user);
                break;
        }
    }while(opcao!='0');
}
