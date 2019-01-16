#ifndef RESOURCES_H
#define RESOURCES_H

#include "common.h"

void addResource(t_resource arr_resource[], int *num_res, int *resource_id_counter);

void viewResource(t_resource arr_resource[], int num_res);

void deleteResource(t_resource arr_resource[], int *num_ress);

void editResource(t_resource arr_resource[], int num_ress);

#endif // RESOURCES_H
