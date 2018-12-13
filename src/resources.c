#include "resources.h"
#include "common.h"
#include <string.h>

int addResource(t_resource arr_resource[], int num_res)
{
    char name[NAMESIZE];
    int found = 0;
    int index;
    clearscreen();
    printf(" -------------------- NOVO RECURSO -------------------- \n");
    printf("Nome: ");
    getName(name);
    for(index = 0; index < num_res; index++)
    {
        if((strcmp(arr_resource[index].name, name)) == 0)
        {
            found = 1;
        }
    }

    if(found == 0 && index == num_res)
    {
        arr_resource[num_res].id = num_res;
        strcpy(arr_resource[num_res].name, name);
        getSecurity(&arr_resource[num_res].grauseguranca);
        printf("Designação: ");
        getName(arr_resource[num_res].designacao);
        num_res+=1;
        printf("Recurso adicionado com sucesso!");
    }
    else
    {
        printf("Este recurso já existe!");
    }
    getch();
    return num_res;
}

void viewResource(t_resource arr_resource[], int num_res)
{
    clearscreen();
    printf(" -------------------- LISTA DE RECURSOS -------------------- \n");
    for(int index = 0; index < num_res; index++)
    {
        printf("ID: %d\n", arr_resource[index].id);
        printf("Nome: %s\n", arr_resource[index].name);
        printf("Grau de Segurança: %d\n", arr_resource[index].grauseguranca);
        printf("Designação: %s\n", arr_resource[index].designacao);
    }
    getch();
}
