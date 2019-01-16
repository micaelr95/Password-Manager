#ifndef COMMON_H
#define COMMON_H

#define MAX_USERS 20
#define MAX_RESOURCES 100
#define MAX_ACCESS 200

#define NAMESIZE 30
#define USERNAMESIZE 20
#define PASSSIZE 20
#define NIFSIZE 10
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
    char nif[NIFSIZE];
    char username[USERNAMESIZE];
    char masterpassword[PASSSIZE];
    int num_access;
} t_user;

typedef struct
{
    int id;
    char name[NAMESIZE];
    int grauseguranca;
    char designacao[NAMESIZE];
    int num_access;
} t_resource;

typedef struct
{
    int id;
    int iduser;
    int idresource;
    char username[USERNAMESIZE];
    char password[PASSSIZE];
    int tipo;   // 0 para crição e 1 para alteração
    t_date data;
    t_hour hora;
} t_access;


void getusername(char *user);

void getpassword(char *pass);

int verifySecurity(char password[], int security);

void getName(char *name);

void getNIF(char *nif);

void clearscreen(void);

t_date getDate();

t_hour getHour();

void getSecurity(int *security);

void saveToFile(t_user arr_users[], int users_index, int users_ID_count, t_resource arr_resources[], int resources_index, int resources_ID_count, t_access arr_access[], int access_index, int access_ID_count);

int readFromFile(t_user arr_users[], int *users_index, int *users_ID_count, t_resource arr_resources[], int *resources_index, int *resources_ID_count, t_access arr_access[], int *access_index, int *access_ID_count);

#endif // COMMON_H
