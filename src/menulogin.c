#include "menulogin.h"
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

void menulogin(void)
{
    char user[STRINGSIZE];
    char pass[STRINGSIZE];
    getpassword(&pass);
    printf("\nA sua password é %s", pass);
}
