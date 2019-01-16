#include "users.h"
#include <stdio.h>

void addUser(t_user arrusers[], int *index, int *user_ID_count)
{
    char pass[PASSSIZE];
    char passverify[PASSSIZE];
    clearscreen();
    printf(" -------------------- NOVO UTILIZADOR -------------------- \n");
    arrusers[*index].id = *user_ID_count;
    printf("Nome: ");
    getName(arrusers[*index].nome);
    getNIF(arrusers[*index].nif);
    printf("Nome do utilizador: ");
    getusername(arrusers[*index].username);
    do
    {
        printf("Password: ");
        getpassword(pass);
        printf("\nVerifique a password: ");
        getpassword(passverify);
        if(strcmp(pass, passverify)==0)
        {
            strcpy(arrusers[*index].masterpassword, pass);
        }
        else
        {
            printf("\nAs palavras passe não coincidem! Tente de novo.\n");
        }
    }while(strcmp(pass, passverify)!=0);
    arrusers[*index].num_access = 0;
    *index+=1;
    *user_ID_count+=1;
}

void showUser(t_user arrusers[], int user_num)
{
    clearscreen();
    printf(" -------------------- Informações do Utilizador -------------------- \n");
    printf("\nID: %d\n", arrusers[user_num].id);
    printf("Nome: %s\n", arrusers[user_num].nome);
    printf("NIF: %s\n", arrusers[user_num].nif);
    printf("Nome de utilizador: %s\n", arrusers[user_num].username);
    printf("Palavra passe mestra: %s\n", arrusers[user_num].masterpassword);
    getch();
}

int login(t_user arr_user[], int arr_index)
{
    char user[USERNAMESIZE];
    char pass[PASSSIZE];
    int numuser = -2;
    clearscreen();
    printf(" -------------------- LOGIN -------------------- \n");
    printf("Nome do utilizador: ");
    getusername(user);
    printf("Password: ");
    getpassword(pass);
    for (int i=0; i < arr_index; i++)
    {
        if(((strcmp(arr_user[i].username, user)) == 0) && ((strcmp(arr_user[i].masterpassword, pass)) == 0))
        {
            numuser = i;
            break;
        }
        if((strcmp(arr_user[i].username, user)) == 0)
        {
            numuser = -1;
            break;
        }
    }
    return numuser;
}

void deleteUser(t_user arr_user[], int *arr_index)
{
    char user[USERNAMESIZE];
    int found = 0;
    clearscreen();
    printf(" -------------------- ELIMINAR UTILIZADOR -------------------- \n");
    printf("Nome do utilizador: ");
    getusername(user);
    for(int i=0; i < *arr_index; i++)
    {
        if((strcmp(arr_user[i].username, user)) == 0)
        {
            found = 1;
            if(arr_user[i].num_access == 0)
            {
                for(int j = i; j < *arr_index; j++)
                {
                    arr_user[i].id = arr_user[i+1].id;
                    strcpy(arr_user[i].nome, arr_user[i+1].nome);
                    strcpy(arr_user[i].nif, arr_user[i+1].nif);
                    strcpy(arr_user[i].username, arr_user[i+1].username);
                    strcpy(arr_user[i].masterpassword, arr_user[i+1].masterpassword);
                }
                *arr_index-=1;
                printf("Utilizador Eliminado");
                break;
            }
            printf("Não é possivel eliminar o utilizador porque existem acessos criados.");
        }
    }
    if(found == 0)
    {
        printf("Utilizador não existe");
    }
    getch();
}
