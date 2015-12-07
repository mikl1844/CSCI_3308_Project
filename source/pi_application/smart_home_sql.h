#include <my_global.h>
#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>

void finish_with_error(MYSQL *con);
int addUserSQL(char username[], char start_time[], char end_time[], int temperature);
int showUsersSQL();
int setActiveUserSQL(char username[], int *start_hour, int *end_hour, int *start_min, int *end_min, int *temperature);
