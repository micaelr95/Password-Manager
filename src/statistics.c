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
