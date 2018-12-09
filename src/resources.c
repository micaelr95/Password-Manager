#include "resources.h"
#include "common.h"

int addResource(t_resource arr_resource[], int num_res)
{
    clearscreen();
    printf(" -------------------- NOVO RECURSO -------------------- \n");
    arr_resource[num_res].id = num_res;
    getName(arr_resource[num_res].name);
    return num_res+1;
}

void viewResource(t_resource arr_resource[], int num_res)
{
    clearscreen();
    printf(" -------------------- LISTA DE RECURSOS -------------------- \n");
    for(int index = 0; index < num_res; index++)
    {
        printf("ID: %d\n", arr_resource[index].id);
        printf("Nome: %s\n", arr_resource[index].name);
    }
    getch();
}
