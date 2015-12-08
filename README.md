Purpose:
The purpose of this project was to build a home automation system.

Organization:
This repository is organized into the following directories. The arduino directory contains the arduino code that was used to in testing and executing the project. The CUnitTest directory contains the code that was used for unit testing. The demo_code directory contains all of the code that was used in the project demonstration. The source directory contains two subdirectories the pi_application directory and the sql_api directories. The pi_application directory contains all of the code that was used to develop the c++ application that is built and executed in the demo_code directory. The sql_api directory contains all of the code that was used to develop the c to sql interface portion of the demo code.

Building/Running/Testing the Code:
To build the c++ demo code run make in the demo_code directory and the smart_house_demo executable will be built. To run the smart house demo enter ./smart_house_demo. To build and run the arduino portion of the demo code open the Arduino IDE and open the interface_driver.ino code found in the arduino directory. Next push the code to the arduino. To build the unit test run g++ -Wall functions.c functions_test.c -lcunit -o cunit_tests. Run the unit tests with ./cunit_tests.
