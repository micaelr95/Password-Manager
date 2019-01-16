#ifndef ACCESS_H
#define ACCESS_H

#include "common.h"
#include "resources.h"

void addaccess(t_resource arr_resource[], int num_ress, t_access arr_access[], int *num_acc, int *acc_ID_count, int id_user, t_user arr_users[], int user_index);
void viewaccess(t_resource arr_resource[], int num_ress, t_access arr_access[], int num_acc, int id_user);
void deleteAccess(t_resource arr_resource[], int num_ress, t_access arr_access[], int *access_index, int id_user, t_user arr_users[], int user_index);

#endif // ACCESS_H
