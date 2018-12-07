#include <locale.h>
#include "menulogin.h"

int main()
{
    t_user users[20];
    int userindex = 0;

    setlocale(LC_ALL, "");
    menulogin(users, userindex);
    return 0;
}
