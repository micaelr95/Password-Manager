#include <stdio.h>
#include <locale.h>
#include "common.h"
#include "users.h"
#include "resources.h"
#include "access.h"
#include "statistics.h"

int menulogin(t_user arr_users[], int *num_users, int *user_id_count, t_resource arr_resources[], int *resources_index, int *resource_id_count, t_access arr_access[], int *access_index, int *access_id_count);
void menuresources(t_resource arr_resources[], int *num_resources, int *resources_id_counter);
void menuaccess(t_resource arr_resources[], int *num_resources, t_access arr_access[], int *num_access, int *access_id_counter, int num_user, t_user arr_user[], int userindex);
void menustatistics(t_resource arr_resources[], int num_resources, t_user arr_user[], int userindex, int num_user);

int main()
{
    t_user users[MAX_USERS];
    int userindex = 0;
    int user_next_id = 0;
    t_resource resources[MAX_RESOURCES];
    int resourceindex = 0;
    int resource_next_id = 0;
    t_access access[MAX_ACCESS];
    int accessindex = 0;
    int access_next_id = 0;
    int opcao;
    int usernum = 0;

    setlocale(LC_ALL, "");

    usernum = menulogin(users, &userindex, &user_next_id, resources, &resourceindex, &resource_next_id, access, &accessindex, &access_next_id);
    if (usernum != -1)
    {
        do
        {
            clearscreen();
            printf(" -------------------- MENU PRINCIPAL -------------------- \n");
            printf("[1] Recursos\n");
            printf("[2] Acessos\n");
            printf("[3] Informa��es do Utilizador\n");
            printf("[4] Editar utilizador\n");
            if(usernum == 0)
            {
                printf("[5] Estatisticas\n");
                printf("[6] Apagar Utilizador\n");
            }
            printf("[9] Guardar Dados\n");
            printf("\n[0] Sair\n");
            opcao = getch();
            switch (opcao)
            {
                case '1':
                    menuresources(resources, &resourceindex, &resource_next_id);
                    break;
                case '2':
                    menuaccess(resources, &resourceindex, access, &accessindex, &access_next_id, usernum, users, userindex);
                    break;
                case '3':
                    showUser(users, usernum);
                    break;
                case '4':
                    editUser(users, userindex, usernum);
                    break;
                case '5':
                    if(usernum == 0)
                    {
                        menustatistics(resources, resourceindex, users, userindex, usernum);
                    }
                    break;
                case '6':
                    if(usernum == 0)
                    {
                        deleteUser(users, &userindex);
                    }
                    break;
                case '9':
                    clearscreen();
                    saveToFile(users, userindex, user_next_id, resources, resourceindex, resource_next_id, access, accessindex, access_next_id);
                    printf("\nDados gravados\n");
                    getch();
                    break;

            }
        }while(opcao!='0');
    }
    return 0;
}

int menulogin(t_user arr_users[], int *num_users, int *user_id_count, t_resource arr_resources[], int *resources_index, int *resource_id_count, t_access arr_access[], int *access_index, int *access_id_count)
{
    int opcao;
    int usernum = -1;
    int readSuccess = 0;
    readSuccess = readFromFile(arr_users, &(*num_users), &(*user_id_count), arr_resources, &(*resources_index), &(*resource_id_count), arr_access, &(*access_index), &(*access_id_count));
    if (readSuccess == 1)
    {
        arr_users[*num_users].id = *user_id_count;
        strcpy(arr_users[*num_users].nome, "Admin");
        strcpy(arr_users[*num_users].username, "admin");
        strcpy(arr_users[*num_users].masterpassword, "admin");
        strcpy(arr_users[*num_users].nif, "99999999");
        arr_users[*num_users].num_access = 0;
        *user_id_count+=1;
        *num_users+=1;
    }
    do
    {
        clearscreen();
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
                    printf("\nConta de utilizador n�o existente.");
                    getch();
                }
                break;
            case '2':
                addUser(arr_users, &(*num_users), &(*user_id_count));
                break;
        }
    }while(opcao!='0' && usernum < 0);
    return usernum;
}

void menuresources(t_resource arr_resources[], int *num_resources, int *resources_id_counter)
{
    int opcao;
    do
    {
        clearscreen();
        printf(" -------------------- MENU RECURSOS -------------------- \n");
        printf("[1] Adicionar\n");
        printf("[2] Editar\n");
        printf("[3] Ver\n");
        printf("[4] Eliminar\n");
        printf("\n[0] Voltar\n");
        opcao = getch();
        switch (opcao)
        {
            case '1':
                addResource(arr_resources, &(*num_resources), &(*resources_id_counter));
                break;
            case '2':
                editResource(arr_resources, *num_resources);
                break;
            case '3':
                viewResource(arr_resources, *num_resources);
                break;
            case '4':
                deleteResource(arr_resources, &(*num_resources));
                break;
        }
    }while(opcao!='0');
}

void menuaccess(t_resource arr_resources[], int *num_resources, t_access arr_access[], int *num_access, int *access_id_counter, int num_user, t_user arr_user[], int userindex)
{
    int opcao;
    do
    {
        clearscreen();
        printf(" -------------------- MENU ACESSOS -------------------- \n");
        printf("[1] Adicionar\n");
        printf("[2] Editar\n");
        printf("[3] Ver\n");
        printf("[4] Apagar\n");
        printf("\n[0] Voltar\n");
        opcao = getch();
        switch (opcao)
        {
            case '1':
                addaccess(arr_resources, *num_resources, arr_access, &(*num_access), &(*access_id_counter), num_user, arr_user, userindex);
                break;
            case '2':
                editAccess(arr_resources, *num_resources, arr_access, *num_access, num_user);
                break;
            case '3':
                viewaccess(arr_resources, *num_resources, arr_access, (*num_access), num_user);
                break;
            case '4':
                deleteAccess(arr_resources, *num_resources, arr_access, &(*num_access), num_user, arr_user, userindex);
                break;
        }
    }while(opcao!='0');
}

void menustatistics(t_resource arr_resources[], int num_resources, t_user arr_user[], int userindex, int num_user)
{
    int opcao;
    do
    {
        clearscreen();
        printf(" -------------------- MENU ESTATISTICAS -------------------- \n");
        printf("[1] Recurso com mais acessos\n");
        printf("[2] Utilizador com mais acessos\n");
        printf("[3] Recurso por tipo\n");
        printf("\n[0] Voltar\n");
        opcao = getch();
        switch (opcao)
        {
            case '1':
                showresourcemoreaccess(arr_resources, num_resources);
                break;
            case '2':
                showusermoreaccess(arr_user, userindex);
                break;
            case '3':
                showresourcebytype(arr_resources, num_resources);
                break;
            default:
                printf("Op��o inv�lida");
        }
    }while(opcao!='0');
}
