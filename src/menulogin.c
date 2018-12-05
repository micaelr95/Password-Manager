#include "menulogin.h"
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

void menulogin(void)
{
    t_user users[20];
    int userindex = 0;
    int opcao;
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

                break;
            case '2':
                criarConta(users, &userindex);
                break;
        }
    }while(opcao!='0');
}

void criarConta(t_user arrusers[], int *index)
{
    clearscreen();
    printf(" -------------------- NOVO UTILIZADOR -------------------- \n");
    getusername(arrusers[*index].username);
    getpassword(arrusers[*index].masterpassword);
    *index+=1;
}
