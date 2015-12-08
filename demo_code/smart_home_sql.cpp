#include <my_global.h>
#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>

void finish_with_error(MYSQL *con)
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);
}

int addUserSQL(char username[], char start_time[], char end_time[], int temperature)
{
  char query[128];

  MYSQL *con = mysql_init(NULL);

  if(con == NULL)
  {
    fprintf(stderr, "%s\n", mysql_error(con));
    return -1;
  }
  
  if (mysql_real_connect(con,"localhost","root","","project",0,NULL,0)==NULL)
  {
    finish_with_error(con);
  }

  sprintf(query, "INSERT INTO Users (Username, Start_time, Stop_time, Temperature) VALUES ('%s', '%s', '%s', %d);", username, start_time, end_time, temperature);
  if (mysql_query(con, query))
  {
    finish_with_error(con);
  }

  mysql_close(con);
  return 0;
}

int showUsersSQL()
{
  int count = 0;
  MYSQL_RES *result;
  MYSQL_ROW row;
  char *row_string;
  char query_count[] = "SELECT count(Username) FROM Users;";
  char query_usernames[] = "SELECT Username FROM Users;";

  MYSQL *con = mysql_init(NULL);

  if(con == NULL)
  {
    fprintf(stderr, "%s\n", mysql_error(con));
    return -1;
  }
  
  if (mysql_real_connect(con,"localhost","root","","project",0,NULL,0)==NULL)
  {
    finish_with_error(con);
  }
  
  if (mysql_query(con, query_count))
  {
    finish_with_error(con);
  }
  else 
  {
    result = mysql_store_result(con);
    row = mysql_fetch_row(result);
    row_string = row[0];
    count = row_string[0] - '0';
    if (mysql_query(con, query_usernames))
    {
      finish_with_error(con);
    }
    else 
    {
      result = mysql_store_result(con);
      for(int i = 0; i < count; i++)
      {
        row = mysql_fetch_row(result);
        row_string = row[0];
        printf("%s\n", row_string);
      } 
    }  
  }

  mysql_close(con);
  return 0;
}

int setActiveUserSQL(char username[], int *start_hour, int *end_hour, int *start_min, int *end_min, int *temperature)
{
  char query[128];
  char *start;
  char *end;
  char *temp;
  MYSQL_RES *result;
  MYSQL_ROW row;
  MYSQL *con = mysql_init(NULL);

  if(con == NULL)
  {
    fprintf(stderr, "%s\n", mysql_error(con));
    return -1;
  }
  
  if (mysql_real_connect(con,"localhost","root","","project",0,NULL,0)==NULL)
  {
    finish_with_error(con);
  }

  sprintf(query, "SELECT * FROM Users WHERE Username='%s';", username);
  if (mysql_query(con, query))
  {
    finish_with_error(con);
  }
  else 
  {
    result = mysql_store_result(con);
    row = mysql_fetch_row(result);
    start = row[2];
    end = row[3];
    temp = row[4];
    *start_hour = (start[0] - '0') * 10;
    *start_hour += start[1] - '0';
    *start_min = (start[3] - '0') * 10;
    *start_min += start[4] - '0';
    *end_hour = (end[0] - '0') * 10;
    *end_hour += end[1] - '0';
    *end_min = (end[3] - '0') * 10;
    *end_min += end[4] - '0';
    *temperature = (temp[0] - '0') * 10;
    *temperature += temp[1] - '0';
  }

  mysql_close(con);
  return 0;
}

int deleteUserSQL(char username[])
{
  char query[64];

  MYSQL *con = mysql_init(NULL);

  if(con == NULL)
  {
    fprintf(stderr, "%s\n", mysql_error(con));
    return -1;
  }
  
  if (mysql_real_connect(con,"localhost","root","","project",0,NULL,0)==NULL)
  {
    finish_with_error(con);
  }

  sprintf(query, "DELETE FROM Users WHERE Username='%s';", username);
  if (mysql_query(con, query))
  {
    finish_with_error(con);
  }

  mysql_close(con);
  return 0;
}
