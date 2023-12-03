#include <CUnit/CUnit.h>
#include <CUnit/TestDB.h>
#include <CUnit/Basic.h>
#include "game_dir.h"
#include "game_core.h"

// test of direcition
void test_dir( void )
{
    CU_ASSERT( LEFT == reverse_dir(RIGHT));
    CU_ASSERT( RIGHT == reverse_dir(LEFT));
    CU_ASSERT( UP == reverse_dir(DOWN) );
    CU_ASSERT( DOWN == reverse_dir(UP) );
}
void test_move( void )
{
    int r = 0;
    int c = 0;
     
    int pr;
    int pc;
    // test move direction one step
    pr = pc = 0;
    advance( &pr, &pc, LEFT);
    CU_ASSERT( pr == 0 && pc == -1);
    
    pr = pc = 0;
    advance( &pr, &pc, RIGHT);
    CU_ASSERT( pr == 0 && pc == 1);

    pr = pc = 0;
    advance( &pr, &pc, UP);
    CU_ASSERT( pr == -1 && pc == 0);

    pr = pc = 0;
    advance( &pr, &pc, DOWN);
    CU_ASSERT( pr == 1 && pc == 0);

    // test move direciton k step

    pr = 1, pc = 3;
    advance_kth( &pr, &pc, LEFT, 4);
    CU_ASSERT( pr == 1 && pc == -1);

    pr = -1, pc = 10;
    advance_kth( &pr, &pc, RIGHT, 3);
    CU_ASSERT( pr == -1 && pc == 13);

    pr = 0, pc = -2;
    advance_kth( &pr, &pc, UP, 10);
    CU_ASSERT( pr == -10 && pc == -2);

    pr = 9, pc = 10;
    advance_kth( &pr, &pc, DOWN, 2);
    CU_ASSERT( pr == 11 && pc == 10); 

}
// end of test of direction

void test_begin_rc( void )
{
   // test LEFT begin
   int pr, pc;
   get_kth_begin_rc( 0, LEFT, &pr, &pc);
   CU_ASSERT( pr == 0 && pc == 0);
   
   get_kth_begin_rc( 1, LEFT, &pr, &pc);
   CU_ASSERT( pr == 1 && pc == 0);

   get_kth_begin_rc( 2, LEFT, &pr, &pc);
   CU_ASSERT( pr == 2 && pc == 0);

   // test RIGHT begin
   get_kth_begin_rc( 0, RIGHT, &pr, &pc);
   CU_ASSERT( pr == 0 && pc == MAP_COLS - 1);

   get_kth_begin_rc( 1, RIGHT, &pr, &pc);
   CU_ASSERT( pr == 1 && pc == MAP_COLS - 1);

   get_kth_begin_rc( 2, RIGHT, &pr, &pc);
   CU_ASSERT( pr == 2 && pc == MAP_COLS - 1);

   // test UP begin
   get_kth_begin_rc( 0, UP, &pr, &pc);
   CU_ASSERT( pr == 0 && pc == 0);

   get_kth_begin_rc( 1, UP, &pr, &pc);
   CU_ASSERT( pr == 0 && pc == 1);

   get_kth_begin_rc( 2, UP, &pr, &pc);
   CU_ASSERT( pr == 0 && pc == 2);

   // test DOWN begin
   get_kth_begin_rc( 0, DOWN, &pr, &pc);
   CU_ASSERT( pr == MAP_ROWS - 1 && pc == 0);

   get_kth_begin_rc( 1, DOWN, &pr, &pc);
   CU_ASSERT( MAP_ROWS - 1 == pr && 1 == pc );

   get_kth_begin_rc( 2, DOWN, &pr, &pc);
   CU_ASSERT( MAP_ROWS - 1 == pr && 2 == pc );
}




int main(int argc, char *argv[])
{
   
   CU_pSuite dirSuite = NULL;
   CU_pSuite coreSuite = NULL;
   
   if ( CUE_SUCCESS != CU_initialize_registry())
	  return CU_get_error();

   dirSuite = CU_add_suite("direction_test", NULL, NULL);
  if ( NULL == dirSuite ) {
      CU_cleanup_registry();
      return CU_get_error();
  } 

  if ( NULL == CU_add_test(dirSuite, "test of dir", test_dir) || 
       NULL == CU_add_test(dirSuite, "test of move", test_move)) {
      CU_cleanup_registry();
      return CU_get_error();
  }

  coreSuite = CU_add_suite("core_test", NULL, NULL);
  if ( NULL == coreSuite) {
       CU_cleanup_registry();
       return CU_get_error();
  }
   
  if ( NULL == CU_add_test(coreSuite, "test of begin rc",test_begin_rc) ){
       CU_cleanup_registry();
       return CU_get_error();
  }


  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  

  CU_cleanup_registry();


    return CU_get_error();
}
