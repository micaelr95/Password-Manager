#ifndef COMMON_H
#define COMMON_H

#define MAX_USERS 20
#define MAX_RESOURCES 100
#define MAX_ACCESS 200

#define NAMESIZE 30
#define USERNAMESIZE 20
#define PASSSIZE 20
#define NIFSIZE 8
#define DATE 8
#define HOUR 5

typedef struct
{
    int dia;
    int mes;
    int ano;
} t_date;

typedef struct
{
    int hora;
    int minuto;
    int segundo;
} t_hour;

typedef struct
{
    int id;
    char nome[NAMESIZE];
    int nif;
    char username[USERNAMESIZE];
    char masterpassword[PASSSIZE];
} t_user;

typedef struct
{
    int id;
    char name[NAMESIZE];
    int grauseguranca;
    char designacao[NAMESIZE];
} t_resource;

typedef struct
{
    int id;
    int iduser;
    int idresource;
    char username[USERNAMESIZE];
    char password[PASSSIZE];
    int tipo;
    t_date data;
    t_hour hora;
} t_access;


void getusername(char *user);

void getpassword(char *pass);

void getName(char *name);

void getNIF(char *nif);

void clearscreen(void);

#endif // COMMON_H
