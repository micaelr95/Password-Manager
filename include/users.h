#ifndef USERS_H
#define USERS_H

#include "common.h"

int addUser(t_user arrusers[], int index);

void showUser(t_user arrusers[], int user_num);

int login(t_user arrusers[], int index);

int loadUsersData(t_user arr_users[]);

void saveUsersData(t_user arr_users[], int arr_index);

#endif // USERS_H
