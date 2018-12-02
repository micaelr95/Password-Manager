#include "menulogin.h"
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

void menulogin(void)
{
    t_user users[20];
    int opcao;
    do
    {
        printf("[1] Login\n");
        printf("[2] Criar Conta\n");
        printf("\n[0] Sair\n");
        opcao = getch();
        printf("A opção escolhida foi %c", opcao);
    }while(opcao!='1' && opcao!='2' && opcao!='0');
    //getusername(&user);
    //getpassword(&pass);
    printf("\n\n\n\n\Olá %s!\nA sua password é %s", users[0].username, users[0].masterpassword);
}
