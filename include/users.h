#ifndef USERS_H
#define USERS_H

#include "common.h"

void addUser(t_user arrusers[], int *index, int *user_ID_count);

void showUser(t_user arrusers[], int user_num);

int login(t_user arrusers[], int index);

void deleteUser(t_user arr_user[], int *arr_index);

#endif // USERS_H
