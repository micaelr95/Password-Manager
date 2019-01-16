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

void showresourcebytype(t_resource arr_resource[], int num_ress)
{
    int tipo = 0;
    int found = 0;
    clearscreen();
    printf(" -------------------- LISTA DE RECURSOS POR TIPO -------------------- \n");
    do
    {
        printf("Tipo de recurso (1 - App; 2 - Website; 3 - Dispositivo): ");
        scanf(" %d", &tipo);
    } while(tipo<1 || tipo>3);

    for(int index = 0; index < num_ress; index++)
    {
        if(arr_resource[index].tipo == tipo)
        {
            found = 1;
            printf("\nID: %d\n", arr_resource[index].id);
            printf("Nome: %s\n", arr_resource[index].name);
            printf("Grau de Segurança: %d\n", arr_resource[index].grauseguranca);
            printf("Designação: %s\n", arr_resource[index].designacao);
            switch(arr_resource[index].tipo)
            {
                case 1:
                    printf("Tipo: App\n");
                break;
                case 2:
                    printf("Tipo: Website\n");
                break;
                case 3:
                    printf("Tipo: Dispositivo\n");
                break;
            }
            printf("Número de acessos: %d\n", arr_resource[index].num_access);
        }
    }
    if(found == 0)
    {
        printf("Não existe recurso com esse tipo.\n");
    }
    getch();
}
