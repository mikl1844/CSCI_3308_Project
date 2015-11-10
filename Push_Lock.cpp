#include <my_global.h>
#include <mysql.h>


void finish_with_error(MYSQL *con)
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);
}

int main()//want to make it look like Lock(int id, int status)
{
  MYSQL *con = mysql_init(NULL);
  
  char House_DB[50];
  char House_Data[50];
  int id = 1;
  int status = 1;
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
