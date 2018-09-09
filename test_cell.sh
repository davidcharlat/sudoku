errorExit()
{
  echo "$1";
  exit 1;
}

USER_BUILD=$1;
TARGET=$USER_BUILD/test_cell
# BUILD
gcc -D DEBUG -o $TARGET $USER_BUILD/cell.c test/test_cell.c || errorExit "Error: compilation failed";
./$USER_BUILD/test_cell;

