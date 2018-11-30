#include "menulogin.h"
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

void menulogin(void)
{
    char user[STRINGSIZE];
    char pass[STRINGSIZE];
    int opcao;
    do
    {
        printf("[1] Login\n");
        printf("[2] Criar Conta\n");
        printf("\n[0] Sair\n");
        opcao = (int)((char)getch());
        printf("A opção escolhida foi %d", opcao);
    }while(opcao!='1' && opcao!='2' && opcao!='0');
    //getusername(&user);
    //getpassword(&pass);
    printf("\nOlá %s!\nA sua password é %s", user, pass);
}
