#ifndef COMMON_H
#define COMMON_H

#define STRINGSIZE 20

typedef struct
{
    int id;
    char nome[STRINGSIZE];
    char nif[STRINGSIZE];
    char username[STRINGSIZE];
    char masterpassword[STRINGSIZE];
} t_user;

void getusername(char *user);

void getpassword(char *pass);

#endif // COMMON_H
