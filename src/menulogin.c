#include "menulogin.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
                login(users, userindex);
                break;
            case '2':
                addUser(users, &userindex);
                break;
        }
    }while(opcao!='0');
}

void addUser(t_user arrusers[], int *index)
{
    clearscreen();
    printf(" -------------------- NOVO UTILIZADOR -------------------- \n");
    arrusers[*index].id = *index;
    printf("Nome: ");
    scanf(" %[^\n]%*c", arrusers[*index].nome);
    printf("Numero de identificação fiscal: ");
    scanf(" %[^\n]%*c", arrusers[*index].nif);
    getusername(arrusers[*index].username);
    getpassword(arrusers[*index].masterpassword);
    *index+=1;
}

void login(t_user arrusers[], int index)
{
    char user[USERNAMESIZE];
    char pass[PASSSIZE];
    clearscreen();
    printf(" -------------------- LOGIN -------------------- \n");
    getusername(user);
    getpassword(pass);
    printf("%d", index);
    for (int i=0; i < index; i++)
    {
        printf("%d", i);
        if(((strcmp(arrusers[i].username, user)) == 0) && ((strcmp(arrusers[i].masterpassword, pass)) == 0))
        {
            printf("\nBem vindo %s!", arrusers[i].username);
        }
        else
        {
            printf("\nCredenciais erradas! Por favor tente de novo");
        }
    }
    getch();
}
