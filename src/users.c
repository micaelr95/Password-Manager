#include "users.h"

void addUser(t_user arrusers[], int *index)
{
    clearscreen();
    printf(" -------------------- NOVO UTILIZADOR -------------------- \n");
    arrusers[*index].id = *index;
    getName(arrusers[*index].nome);
    getNIF(arrusers[*index].nif);
    getusername(arrusers[*index].username);
    getpassword(arrusers[*index].masterpassword);
    *index+=1;
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
