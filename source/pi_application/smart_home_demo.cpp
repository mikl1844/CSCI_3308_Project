#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include "smart_home_sql.h"

using namespace std;

void mainMenu()
{
   printf("Enter the following:\n");
   printf("1. To show users\n");
   printf("2. To set active user\n");
   printf("3. To add user\n");
   printf("4. To control lock\n");
   printf("5. To delete user\n");
   printf("6. To exit\n");
}

void showUsers()
{
   showUsersSQL();
   mainMenu();
   return;
}

void setActiveUser(int *hour_start, int *hour_end, int *min_start, int *min_end, int *temperature)
{
   char input[16];
   
   printf("Set Active User by entering their username:\n");
   scanf("%s", input);
   setActiveUserSQL(input, hour_start, hour_end, min_start, min_end, temperature);
   printf("%s set as active user\n", input);
   printf("Parameters: Start: %d:%d, Stop: %d:%d, Temperature: %d\n", *hour_start, *min_start, *hour_end, *min_end, *temperature);
   mainMenu();  
   return;
}

void addUser()
{
   char username[16];
   char start_time[6];
   char end_time[6];
   int temperature = 0;

   printf("Enter Username (15 characters max):\n");
   scanf("%s", username);
   
   printf("Enter Light Start Time (HH:MM, 24 hour time):\n");
   scanf("%s", start_time);

   printf("Enter Light End Time (HH:MM, 24 hour time):\n");
   scanf("%s", end_time);

   printf("Enter Temperature (0-40):\n");
   scanf("%d", &temperature); 

   addUserSQL(username, start_time, end_time, temperature); 
   printf("User Added\n");
   mainMenu();

   return;
}

void lockControl()
{
   char input;
   
   printf("Enter the following:\n");
   printf("1. Lock\n");
   printf("2. Unlock\n");
   printf("3. Return\n");
   while(1)
   {
      scanf("%s", &input);

      if(input == '1')
      {
         printf("Lock\n");
      }
      else if(input == '2')
      {
         printf("Unlock\n");
      }
      else if(input == '3')
      {
         mainMenu();
         return;
      }
      else
      {
         printf("ERROR: Invalid input.\n");
      }
   }
}

void deleteUser()
{
   char input[16];
   printf("Delete user by entering their user name\n");
   scanf("%s", input);
   deleteUserSQL(input);   
   
   printf("User deleted\n");
   mainMenu();
   return;
}

void checkTime(int hour_start, int hour_end, int minute_start, int minute_end)
{
   time_t time_check; 
   struct tm *t;    

   time_check = time(0);
   t = localtime(&time_check);
    
   if((hour_start < t->tm_hour) && (hour_end > t->tm_hour))
   {
      printf("Light is ON\n");
   }
   else if(hour_start == t->tm_hour)
   {
      if(minute_start < t->tm_min)
      {
         printf("Light is ON\n");
      }
      else
      {
         printf("Light is OFF\n");
      }
   }
   else if(hour_end == t->tm_hour)
   {
      if(minute_end > t->tm_min)
      {
         printf("Light is ON\n");
      }
      else
      {
         printf("Light is OFF\n");
      }
   } 
   else
   {
      printf("Light is OFF\n");
   }
   return;  
}

int main()
{
   int start_hour = 0;
   int end_hour = 0;
   int start_minute = 0;
   int end_minute = 0;
   int temperature = 20;
   char input;
   
   mainMenu();
   
   while(1)
   {
      scanf("%s", &input);
      
      if(input == '1')
      {
         showUsers();
      }
      else if(input == '2')
      {
         setActiveUser(&start_hour, &end_hour, &start_minute, &end_minute, &temperature);
      }
      else if(input == '3')
      {
         addUser();
      }
      else if(input == '4')
      {
         lockControl();
      }
      else if(input == '5')
      {
         deleteUser();
      }
      else if(input == '6')
      {
         return 0;
      }
      else
      {
         printf("ERROR: Invalid input.\n");
      }
      checkTime(start_hour, end_hour, start_minute, end_minute);
   }
   return 0;
}
