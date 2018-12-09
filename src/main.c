#include <stdio.h>
#include <locale.h>
#include "common.h"
#include "users.h"
#include "resources.h"

int menulogin(t_user arr_users[], int *num_users);

int main()
{
    t_user users[MAX_USERS];
    int userindex = 0;
    t_resource resources[MAX_RESOURCES];
    int resourceindex = 0;

    setlocale(LC_ALL, "");

    if (menulogin(users, &userindex) == 1)
    {
        int opcao;
        do
        {
            clearscreen();
            printf(" -------------------- MENU PRINCIPAL -------------------- \n");
            printf("[1] Recursos\n");
            printf("[2] Acessos\n");
            printf("\n[0] Sair\n");
            opcao = getch();
            switch (opcao)
            {
                case '1':
                    resourceindex = addResource(resources, resourceindex);
                    break;
                case '2':
                    viewResource(resources, resourceindex);
                    break;
                case '3':
                    showUser(users, userindex);
                    break;
            }
        }while(opcao!='0');
    }
    return 0;
}

int menulogin(t_user arr_users[], int *num_users)
{

    int opcao;
    int canLogin = 0;
    do
    {
        clearscreen();
        printf("[1] Login\n");
        printf("[2] Criar Conta\n");
        printf("\n[0] Sair\n");
        opcao = getch();
        switch (opcao)
        {
            case '1':
                canLogin = login(arr_users, *num_users);
                if(canLogin == 0)
                {
                    printf("\nCredenciais erradas! Por favor tente de novo");
                }
                break;
            case '2':
                *num_users = addUser(arr_users, *num_users);
                break;
        }
    }while(opcao!='0' && canLogin == 0);
    return canLogin;
}
