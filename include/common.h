#ifndef COMMON_H
#define COMMON_H

#define MAX_USERS 20
#define MAX_RESOURCES 100
#define MAX_ACCESS 200

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

typedef struct
{
    int id;
    char name[NAMESIZE];
} t_resource;

void getusername(char *user);

void getpassword(char *pass);

void getName(char *name);

void getNIF(char *nif);

void clearscreen(void);

#endif // COMMON_H
