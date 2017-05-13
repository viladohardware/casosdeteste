#include <stdio.h>
#include <string.h>
#include "CUnit/Basic.h"
#include "lib/stack.h"

 void test_push(void)
 {
   st* temp = create_stack();
   int i;
   for(i = 0; i < 100000; i++)
   {
     push(temp,i);
     CU_ASSERT(peek(temp) == i);
   }
 }

 void test_pop(void)
 {
   st* temp = create_stack();
   int i, aux;
   for(i = 0; i < 100000; i++)
   {
     push(temp,i);
   }
   for(i = 0; i < 100000; i++)
   {
     aux = peek(temp);
     pop(temp);
     CU_ASSERT(aux != peek(temp));
   }
 }

 int main()
 {
   CU_pSuite pSuite = NULL;

   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   pSuite = CU_add_suite("Stack data struct",NULL,NULL);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   if (NULL == CU_add_test(pSuite, "test of push() and peek() functions", test_push) || NULL == CU_add_test(pSuite, "teste of pop() function", test_pop))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
 }
