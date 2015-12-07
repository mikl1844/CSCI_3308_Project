#include <stdio.h>
#include <stdlib.h>
#include <wiringSerial.h>

using namespace std;

void printMainMenu(int file_descriptor)
{
   serialPrintf(file_descriptor, "Enter the following:\n");
   serialPrintf(file_descriptor, "0. To view users\n");
   serialPrintf(file_descriptor, "1. To set active user\n");
   serialPrintf(file_descriptor, "2. To add user\n");
   serialPrintf(file_descriptor, "3. For Lock Control Menu\n");
   return;
}

void printUsers(int file_descriptor)
{
   //query database to get all users and then print them
   printMainMenu(file_descriptor);
   return;
}

void setActiveUser(int file_descriptor)
{
   //query database to get specified user's parameters
   printMainMenu(file_descriptor);
   return;
}

void addUser(int file_descriptor)
{
   //insert new row into database table with entered parameters
   printMainMenu(file_descriptor);
   return;
}

void lockControl(int fd_input, int fd_output)
{
   int count = 0;
   char data;

   serialPrintf(fd_input, "Enter the following:\n");
   serialPrintf(fd_input, "0. To lock\n");
   serialPrintf(fd_input, "1. To unlock\n");
   serialPrintf(fd_input, "2. To return to Main Menu");
    
   while(1)
   {
      count = serialDataAvail(fd_input);

      if(count > 0)
      {
         data = serialGetchar(fd_input);
    
         if(data == '0')
         {
            serialPutchar(fd_output, 'a');
         }
         else if(data == '1')
         {   
            serialPutchar(fd_output, 'b');
         }
         else if(data == '2')
         {
            printMainMenu(fd_input);
            return;
         }
         else
         {
            serialPrintf(fd_input, "ERROR: Invalid input.\n");
         }
      } 
   }
}

int main()
{
   int baud_rate = 9600;
   int bluetooth_count = 0;
   char bluetooth_data;
   int arduino_fd = serialOpen("/dev/ttyAMA0", baud_rate);
   int bluetooth_fd = serialOpen("/dev/rfcomm0", baud_rate); 

   printMainMenu(bluetooth_fd); 

   while(1) 
   {
      bluetooth_count = serialDataAvail(bluetooth_fd);
      
      if(bluetooth_count > 0)
      {
         bluetooth_data = serialGetchar(bluetooth_fd);
         
         if(bluetooth_data == '0')
         {
            printUsers(bluetooth_fd);
         }
         else if(bluetooth_data == '1')
         {
            setActiveUser(bluetooth_fd);
         }
         else if(bluetooth_data == '2') 
         {
            addUser(bluetooth_fd);
         }
         else if(bluetooth_data == '4')
         {
            lockControl(bluetooth_fd, arduino_fd);
         }
         else
         {
            serialPrintf(bluetooth_fd, "ERROR: Invalid input.\n");
         } 
      }
   }
   return 1;
}
