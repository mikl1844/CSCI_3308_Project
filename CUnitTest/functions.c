#include "functions.h"
#include "mysql/mysql.h"
#include "stdio.h"
#include "stdlib.h"

void finish_with_error(MYSQL *con)
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);
}

int Pull_Data(int id, char field[])
{
  char query[64];

  MYSQL *con = mysql_init(0);

  if(con == 0)
  {
    fprintf(stderr, "%s\n", mysql_error(con));
    return -1;
  }
  
  if (mysql_real_connect(con,"localhost","root","","Project",0,NULL,0)==NULL)
  {
    finish_with_error(con);
  }
  
  sprintf(query, "SELECT %s FROM House_DB WHERE ID=%d" ,field, id);
  if (mysql_query(con, query))
  {
    finish_with_error(con);
  }

  mysql_close(con);
  return 0;
}

int Push_Data(int id, float data)
{
  char query[64];

  MYSQL *con = mysql_init(NULL);

  if(con == NULL)
  {
    fprintf(stderr, "%s\n", mysql_error(con));
    return -1;
  }
  
  if (mysql_real_connect(con,"localhost","root","","Project",0,NULL,0)==NULL)
  {
    finish_with_error(con);
  }

  sprintf(query, "UPDATE House_DB SET Temperature=%f WHERE ID=%d" ,data, id);
  if (mysql_query(con, query))
  {
    finish_with_error(con);
  }

  mysql_close(con);
  return 0;
}

int Lock(int id, int status)
{
  MYSQL *con = mysql_init(NULL);
  
  char House_DB[50];
  char House_Data[50];
  if(con == NULL)
  {
    fprintf(stderr, "%s\n", mysql_error(con));
    exit(1);
  }
  
  if (mysql_real_connect(con,"localhost","root","","Project",0,NULL,0)==NULL)
  {
    finish_with_error(con);
  }
  if (status == 0)
  {
    sprintf(House_DB, "UPDATE House_DB SET SmartLock='close' WHERE ID=%d",id);
    if (mysql_query(con,House_DB))//House_DB Query
    {
      finish_with_error(con);
    }
    sprintf(House_Data, "UPDATE House_Data SET Lock_Status=%d",status);
    if (mysql_query(con, House_Data))//House_Data Query
    {
      finish_with_error(con);
    }
  }
  else
  {
    status = 1;
    sprintf(House_DB, "UPDATE House_DB SET SmartLock='open' WHERE ID=%d",id);
    if (mysql_query(con,House_DB))//House_DB Query
    {
      finish_with_error(con);
    }
    sprintf(House_Data, "UPDATE House_Data SET Lock_Status=%d",status);
    if (mysql_query(con, House_Data))//House_Data Query
    {
      finish_with_error(con);
    }
  }
  mysql_close(con);
  exit(0);
}
