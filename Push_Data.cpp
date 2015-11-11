#include <my_global.h>
#include <mysql.h>


void finish_with_error(MYSQL *con)
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);
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

int main()
{
  int id = 2;
  int status;
  float data = 73.37;
  status = Push_Data(id, data);
  if(status == 0)
  {
    exit(0);
  }
  else
  {
    exit(1);
  }
}
