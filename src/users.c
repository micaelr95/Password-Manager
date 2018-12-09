#include "users.h"

int addUser(t_user arrusers[], int index)
{
    clearscreen();
    printf(" -------------------- NOVO UTILIZADOR -------------------- \n");
    arrusers[index].id = index;
    getName(arrusers[index].nome);
    getNIF(arrusers[index].nif);
    getusername(arrusers[index].username);
    getpassword(arrusers[index].masterpassword);
    return index+1;
}

void showUser(t_user arrusers[], int index)
{
    clearscreen();
    printf(" -------------------- LISTA DE UTILIZADORES -------------------- \n");
    for(int userindex = 0; userindex < index; userindex++)
    {
        printf("ID: %d\n", arrusers[userindex].id);
        printf("Nome: %s\n", arrusers[userindex].nome);
        printf("NIF: %s\n", arrusers[userindex].nif);
        printf("Nome de utilizador: %s\n", arrusers[userindex].username);
        printf("Palavra passe mestra: %s\n", arrusers[userindex].masterpassword);
    }
    getch();
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
