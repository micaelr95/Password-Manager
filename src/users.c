#include "users.h"

int addUser(t_user arrusers[], int index)
{
    char pass[PASSSIZE];
    char passverify[PASSSIZE];
    clearscreen();
    printf(" -------------------- NOVO UTILIZADOR -------------------- \n");
    arrusers[index].id = index;
    getName(arrusers[index].nome);
    getNIF(arrusers[index].nif);
    getusername(arrusers[index].username);
    do
    {
        getpassword(pass);
        printf("\nVerifique a ");
        getpassword(passverify);
        if(strcmp(pass, passverify)==0)
        {
            strcpy(arrusers[index].masterpassword, pass);
        }
        else
        {
            printf("\nAs palavras passe n�o coincidem! Tente de novo.\n");
        }
    }while(strcmp(pass, passverify)!=0);
    return index+1;
}

void showUser(t_user arrusers[], int user_num)
{
    clearscreen();
    printf(" -------------------- Informa��es do Utilizador -------------------- \n");
    printf("ID: %d\n", arrusers[user_num].id);
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
    int numuser = -1;
    clearscreen();
    printf(" -------------------- LOGIN -------------------- \n");
    getusername(user);
    getpassword(pass);
    for (int i=0; i < arr_index; i++)
    {
        if(((strcmp(arr_user[i].username, user)) == 0) && ((strcmp(arr_user[i].masterpassword, pass)) == 0))
        {
            numuser = i;
            break;
        }
    }
    return numuser;
}
