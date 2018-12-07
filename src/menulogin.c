#include "menulogin.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "users.h"

int menulogin(t_user arr_users[], int *index)
{

    int opcao;
    int canLogin = 0;
    do
    {
        clearscreen();
        printf("[1] Login\n");
        printf("[2] Criar Conta\n");
        printf("[3] Mostrar Contas\n");
        printf("\n[0] Sair\n");
        opcao = getch();
        switch (opcao)
        {
            case '1':
                canLogin = login(arr_users, index);
                if(canLogin == 0)
                {
                    printf("\nCredenciais erradas! Por favor tente de novo");
                }
                break;
            case '2':
                addUser(arr_users, &index);
                break;
            case '3':
                showUser(arr_users, index);
                break;
        }
    }while(opcao!='0' && canLogin == 0);
    return canLogin;
}

int login(t_user arr_user[], int arr_index)
{
    char user[USERNAMESIZE];
    char pass[PASSSIZE];
    int logincorrect = 0;
    clearscreen();
    printf(" -------------------- LOGIN -------------------- \n");
    getusername(user);
    getpassword(pass);
    for (int i=0; i < arr_index; i++)
    {
        if(((strcmp(arr_user[i].username, user)) == 0) && ((strcmp(arr_user[i].masterpassword, pass)) == 0))
        {
            logincorrect = 1;
        }
        else
        {
            logincorrect = 0;
        }
    }
    return logincorrect;
}
