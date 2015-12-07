#include <stdio.h>
#include <stdlib.h>
#include "smart_home_sql.h"

using namespace std;

void mainMenu()
{
   printf("Enter the following:\n");
   printf("1. To show users\n");
   printf("2. To set active user\n");
   printf("3. To add user\n");
   printf("4. To control lock\n");
}

void showUsers()
{
   showUsersSQL();
   mainMenu();
   return;
}

void setActiveUser()
{
   int hour_start = 0;
   int hour_end = 0;
   int min_start = 0;
   int min_end = 0;
   int temperature = 0;
   char input[16];
   
   printf("Set Active User by entering their username:\n");
   scanf("%s", input);
   setActiveUserSQL(input, &hour_start, &hour_end, &min_start, &min_end, &temperature);
   printf("%s set as active user\n", input);
   printf("Parameters: Start: %d:%d, Stop: %d:%d, Temperature: %d\n", hour_start, min_start, hour_end, min_end, temperature);
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
   //printf("%s\n", username);
   
   printf("Enter Light Start Time (HH:MM, 24 hour time):\n");
   scanf("%s", start_time);
   //printf("%s\n", start_time);

   printf("Enter Light Start Time (HH:MM, 24 hour time):\n");
   scanf("%s", end_time);
   //printf("%s\n", end_time);

   printf("Enter Temperature (0-40):\n");
   scanf("%d", &temperature);
   //printf("%d\n", temperature); 

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

int main()
{
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
         setActiveUser();
      }
      else if(input == '3')
      {
         addUser();
      }
      else if(input == '4')
      {
         lockControl();
      }
      else
      {
         printf("ERROR: Invalid input.\n");
      }
   }
   return 1;
}
