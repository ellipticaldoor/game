#!/bin/bash
set -e
sh -c "cd .."

if [ ! -f ./bin/pch.hpp.gch ]; then
  echo "compiling pch"
  make build-pch
fi

if [ ! -f ./bin/catch2.o ]; then
  echo "compiling catch2"
  clang++ -std=c++17 -c src/catch2.cpp -o ./bin/catch2.o
fi

TEST_FILES=`find src -name "*.test.cpp" | grep "$1"`
O_FILES=""
BUILD="clang++ -std=c++17 -Wall -I ./src -include-pch bin/pch.hpp.gch"

for file in $TEST_FILES
do
  echo $file
  FILENAME=`echo "${file/.cpp/.o}" | rev | cut -d"/" -f1 | rev`
  O_FILES="$O_FILES ./bin/$FILENAME"
  $BUILD -c $file -o ./bin/$FILENAME
done

$BUILD ./bin/catch2.o $O_FILES -o ./bin/test.out -I

./bin/test.out

rm $O_FILES
