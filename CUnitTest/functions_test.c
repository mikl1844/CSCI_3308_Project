#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "CUnit/Automated.h"
#include "functions.h"

int init_suite(void) 
{ 
	return 0; 
}
int clean_suite(void) 
{ 
	return 0; 
}

//Functions
void testCase(void)
{
   CU_ASSERT(CU_TRUE);
   CU_ASSERT_NOT_EQUAL(1, 0);
   CU_ASSERT_STRING_EQUAL("string #1", "string #1");
   CU_ASSERT_STRING_NOT_EQUAL("string #1", "string #2");

   CU_ASSERT(CU_FALSE);
   CU_ASSERT_EQUAL(1, 1);
   CU_ASSERT_STRING_NOT_EQUAL("string #1", "string #1");
   CU_ASSERT_STRING_EQUAL("string #1", "string #2");
}

void function_test_1(void) {
  CU_ASSERT_TRUE( Push_Data(1,0)==0);
  CU_ASSERT_FALSE(Push_Data(1,1)==1);
}

void function_test_2(void) {
    CU_ASSERT_TRUE(Pull_Data(0, "a")==0);
    CU_ASSERT_FALSE(Pull_Data(1,"1")==1);
}

void function_test_3(void) {
  CU_ASSERT_TRUE( Lock( 1, 1)== 0);
}

int main ( void )
{
   CU_pSuite pSuite = NULL;

   /* initialize the CUnit test registry */
   if ( CUE_SUCCESS != CU_initialize_registry() )
      return CU_get_error();

   /* add a suite to the registry */
   pSuite = CU_add_suite( "Suite 1", init_suite, clean_suite );
   if ( NULL == pSuite ) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   // add tests
   if ((NULL == CU_add_test(pSuite, "Push Data Test", function_test_1)) ||
        (NULL == CU_add_test(pSuite, "Pull Data Test", function_test_2)) ||
        (NULL == CU_add_test(pSuite, "Push Lock Test", function_test_3))
      )
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   // Run all tests using the basic interface
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   printf("\n");
   CU_basic_show_failures(CU_get_failure_list());
   printf("\n\n");

   // Run all tests using the automated interface
   CU_automated_run_tests();
   CU_list_tests_to_file();

   CU_cleanup_registry();
   return CU_get_error();
}
