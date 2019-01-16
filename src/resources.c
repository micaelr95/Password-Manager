#include "resources.h"
#include "common.h"
#include <string.h>

void addResource(t_resource arr_resource[], int *num_res, int *resource_id_counter)
{
    char name[NAMESIZE];
    int found = 0;
    int index;
    clearscreen();
    printf(" -------------------- NOVO RECURSO -------------------- \n");
    printf("Nome: ");
    getName(name);
    for(index = 0; index < *num_res; index++)
    {
        if((strcmp(arr_resource[index].name, name)) == 0)
        {
            found = 1;
        }
    }

    if(found == 0 && index == *num_res)
    {
        arr_resource[*num_res].id = *resource_id_counter;
        strcpy(arr_resource[*num_res].name, name);
        getSecurity(&arr_resource[*num_res].grauseguranca);
        printf("Designa��o: ");
        getName(arr_resource[*num_res].designacao);
        do
        {
            printf("Tipo de recurso (1 - App; 2 - Website; 3 - Dispositivo): ");
            scanf(" %d", &arr_resource[*num_res].tipo);
        }while(arr_resource[*num_res].tipo<1 || arr_resource[*num_res].tipo>3);
        *num_res+=1;
        *resource_id_counter+=1;
        printf("Recurso adicionado com sucesso!");
    }
    else
    {
        printf("Este recurso j� existe!");
    }
    getch();
}

void viewResource(t_resource arr_resource[], int num_res)
{
    clearscreen();
    printf(" -------------------- LISTA DE RECURSOS -------------------- \n");
    if(num_res > 0)
    {
        for(int index = 0; index < num_res; index++)
        {
            printf("\nID: %d\n", arr_resource[index].id);
            printf("Nome: %s\n", arr_resource[index].name);
            printf("Grau de Seguran�a: %d\n", arr_resource[index].grauseguranca);
            printf("Designa��o: %s\n", arr_resource[index].designacao);
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
            printf("N�mero de acessos: %d\n", arr_resource[index].num_access);
        }
    }
    else
    {
        printf("Recurso n�o encontrado\n");
    }
    getch();
}

void deleteResource(t_resource arr_resource[], int *num_ress)
{
    char name[NAMESIZE];
    int found = 0;
    clearscreen();
    printf(" -------------------- ELIMINAR RECURSO -------------------- \n");
    printf("Nome do recurso a eliminar: ");
    getName(name);

    for(int i = 0; i < *num_ress; i++)
    {
        if((strcmp(arr_resource[i].name, name)) == 0)
        {
            found = 1;
            if(arr_resource[i].num_access == 0)
            {
                for(int j = i; j < *num_ress; j++)
                {
                    arr_resource[j].id = arr_resource[j+1].id;
                    strcpy(arr_resource[j].name, arr_resource[j+1].name);
                    strcpy(arr_resource[j].designacao, arr_resource[j+1].designacao);
                    arr_resource[j].grauseguranca = arr_resource[j+1].grauseguranca;
                    arr_resource[j].num_access = arr_resource[j+1].num_access;
                }
                printf("Recurso eliminado\n");
                *num_ress-=1;
                break;
            }
            else
            {
                printf("N�o � possivel eliminar o recurso porque ha acessos associados.\n");
            }
        }
    }

    if (found == 0)
    {
        printf("Recurso n�o encontrado\n");
    }
    getch();
}
