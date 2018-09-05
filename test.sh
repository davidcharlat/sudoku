
USER_BUILD=$1;
TARGET=$USER_BUILD/colle-1
# BUILD
gcc -Wextra -Wall -Werror -O3 -o $TARGET $USER_BUILD/*.c

shouldError()
{
  echo "\n$2";
  OUTPUT="`$TARGET $(cat test/$1)`";
  ERRCODE=$?;
  if [ "$OUTPUT" != "Erreur" ]
  then
    echo "Error: was expecting\nErreur\n\nand got\n$OUTPUT"
    exit 1;
  elif [ $ERRCODE = 0 ]
  then
    echo "Error: was expecting error code different than 0 and got $ERRCODE."
    exit 1;
  else
    echo "Ok"
  fi    
}

shouldSucceed()
{
  echo "\n$1";
  OUTPUT="`$TARGET $(cat test/$1.sample)`";
  EXPECTED="`cat test/$1.solution`"
  ERRCODE=$?;
  if [ "$OUTPUT" != "$EXPECTED" ]
  then
    echo "Error: was expecting\n$EXPECTED\nand got\n$OUTPUT"
    exit 1;
  elif [ $ERRCODE -ne 0 ]
  then
    echo "Error: was expecting error code 0 and got $ERRCODE."
    exit 1;
  else
    echo "Ok"
  fi 
}

# TESTS
time shouldError "invalid_arg" "calling with an invalid number of argument should throw"
time shouldError "invalid_board_forbidden_input" "calling with a forbidden char in an otherwise valid argument should throw"
time shouldError "invalid_board_impossible" "calling with a board with built in errors should throw"
# time shouldError "invalid_board_demon_impossible" "calling with a board with built in errors should throw"
time shouldError "invalid_board_multiple_solutions" "calling with an ambiguous board should throw"
time shouldSucceed "sudoku1"
time shouldSucceed "sudoku_difficult"
time shouldSucceed "sudoku_hardcore"
time shouldSucceed "sudoku_uber"
# time shouldSucceed "sudoku_demon"
