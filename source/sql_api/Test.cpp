#include <my_global.h>
#include <mysql.h>

void finish_with_error(MYSQL *con)
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);
}

int main(int argc, char **argv)
{
  MYSQL *con = mysql_init(NULL);

  if(con == NULL)
  {
    fprintf(stderr, "%s\n", mysql_error(con));
    exit(1);
  }
  
  if (mysql_real_connect(con,"localhost","root","","Project",0,NULL,0)==NULL)
  {
    finish_with_error(con);
  }
  if (mysql_query(con, "UPDATE House_DB SET SmartLock='close' WHERE ID=1"))
  {
    finish_with_error(con);
  }
  mysql_close(con);
  exit(0);
}
