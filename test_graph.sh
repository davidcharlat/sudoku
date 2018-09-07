errorExit()
{
  echo "$1";
  exit 1;
}

USER_BUILD=$1;
TARGET=$USER_BUILD/test_graph
# BUILD
gcc -o $TARGET $USER_BUILD/graph.c test/test_graph.c || errorExit "Error: compilation failed";
./$USER_BUILD/test_graph;

