#ifndef ACCESS_H
#define ACCESS_H

#include "common.h"
#include "resources.h"

int addaccess(t_resource arr_resource[], int num_ress, t_access arr_access[], int num_acc, int id_user);
void viewaccess(t_resource arr_resource[], int num_ress, t_access arr_access[], int num_acc, int id_user);

#endif // ACCESS_H
