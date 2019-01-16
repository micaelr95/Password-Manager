#include "statistics.h"
#include <stdio.h>
#include <stdlib.h>

void showresourcemoreaccess(t_resource arr_resource[], int num_ress)
{
    int more = 0;
    int id = 0;
    clearscreen();
    printf(" -------------------- RECURSO COM MAIS ACESSOS -------------------- \n");
    for(int i=0; i < num_ress; i++)
    {
        if(more < arr_resource[i].num_access)
        {
            more = arr_resource[i].num_access;
            id = i;
        }
    }
    printf("O recurso com mais acessos é %s com %d acessos.", arr_resource[id].name, arr_resource[id].num_access);
    getch();
}

void showusermoreaccess(t_user arr_user[], int num_user)
{
    int more = 0;
    int id = 0;
    clearscreen();
    printf(" -------------------- RECURSO COM MAIS ACESSOS -------------------- \n");
    for(int i=0; i < num_user; i++)
    {
        if(more < arr_user[i].num_access)
        {
            more = arr_user[i].num_access;
            id = i;
        }
    }
    printf("O utilizador com mais acessos é %s com %d acessos.", arr_user[id].nome, arr_user[id].num_access);
    getch();
}
