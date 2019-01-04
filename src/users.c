#include "users.h"
#include <stdio.h>

int addUser(t_user arrusers[], int index)
{
    char pass[PASSSIZE];
    char passverify[PASSSIZE];
    clearscreen();
    printf(" -------------------- NOVO UTILIZADOR -------------------- \n");
    arrusers[index].id = index;
    printf("Nome: ");
    getName(arrusers[index].nome);
    getNIF(arrusers[index].nif);
    printf("Nome do utilizador: ");
    getusername(arrusers[index].username);
    do
    {
        printf("Password: ");
        getpassword(pass);
        printf("\nVerifique a password: ");
        getpassword(passverify);
        if(strcmp(pass, passverify)==0)
        {
            strcpy(arrusers[index].masterpassword, pass);
        }
        else
        {
            printf("\nAs palavras passe não coincidem! Tente de novo.\n");
        }
    }while(strcmp(pass, passverify)!=0);
    saveUsersData(arrusers, index+1);
    return index+1;
}

void showUser(t_user arrusers[], int user_num)
{
    clearscreen();
    printf(" -------------------- Informações do Utilizador -------------------- \n");
    printf("\nID: %d\n", arrusers[user_num].id);
    printf("Nome: %s\n", arrusers[user_num].nome);
    printf("NIF: %d\n", arrusers[user_num].nif);
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

int loadUsersData(t_user arr_users[])
{
    FILE *file;
    int arr_index = 0;
    file = fopen("data.dat", "rb");
    if(file == NULL)
    {
        printf("Erro ao abrir o ficheiro");
    }
    else
    {
        fread(&arr_index, sizeof(int), 1, file);
        fread(arr_users, sizeof(t_user), arr_index, file);
        fclose(file);
    }
    return arr_index;
}

void saveUsersData(t_user arr_users[], int arr_index)
{
    FILE *file;
    file = fopen("data.dat", "wb");
    if(file == NULL)
    {
        printf("Erro ao criar o ficheiro");
    }
    else
    {
        fwrite(&arr_index, sizeof(int), 1, file);
        fwrite(arr_users, sizeof(t_user), arr_index, file);
    }
    fclose(file);
}
