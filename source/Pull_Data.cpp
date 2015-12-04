#include <my_global.h>
#include <mysql.h>


void finish_with_error(MYSQL *con)
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);
}

int Pull_Data(int id, char field[])
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

  sprintf(query, "SELECT %s FROM House_DB WHERE ID=%d" ,field, id);
  if (mysql_query(con, query))
  {
    finish_with_error(con);
  }

  mysql_close(con);
  return 0;
}

int main()
{
  int id = 0;
  float result;
  char column[16] = "Temperature";
  result = Pull_Data(id, column);
  printf("Temperature: %f", result);
  exit(0);
}
