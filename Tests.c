//unity testing test cases, tests for functionality in logic functions.

#include "unity.h"
#include "Logic.h"


//tests whether a 1 is returned by the function loadGame which signals a
//succesful load up from the text file.
void testLoadGame(){
  int a = loadGame();
  TEST_ASSERT_EQUAL_INT(1,a);
}


//tests whether a 1 is returned by the function saveGame which signals a
//succesful save to the text file.
void testSaveGame(){
  int a = saveGame();
  TEST_ASSERT_EQUAL_INT(1,a);
}



//this test sets some cells to alive and then checks whether the function
//numNeighbours works correctly and returns the right number.
void testNeighbours(){
  grid[3][4] = 1;
  grid[4][3] = 1;

  int a = numNeighbours(3,3);
  TEST_ASSERT_EQUAL_INT(2,a);
}



//testing the stateChange function and whether it correctly makes a cell come to
//life if the rules are met.
void testState(){
  grid[2][2] = 0;
  int a = stateChange(3, 2, 2);

  TEST_ASSERT_EQUAL_INT(1,a);
}




void setUp(){

}
void tearDown(){

}


int main(){
  UNITY_BEGIN();
  RUN_TEST(testLoadGame);
  RUN_TEST(testSaveGame);
  RUN_TEST(testNeighbours);
  RUN_TEST(testState);

  return UNITY_END();
}
