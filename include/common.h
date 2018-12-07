#ifndef COMMON_H
#define COMMON_H

#define ACCESSSIZE 20

#define NAMESIZE 30
#define USERNAMESIZE 20
#define PASSSIZE 20
#define NIFSIZE 10

typedef struct
{
    int id;
    char nome[NAMESIZE];
    char nif[NIFSIZE];
    char username[USERNAMESIZE];
    char masterpassword[PASSSIZE];
} t_user;

void getusername(char *user);

void getpassword(char *pass);

void getName(char *name);

void getNIF(char *nif);

void clearscreen(void);

#endif // COMMON_H
