#!/bin/bash

# set working directory of this script to be the directory the script is in
cd "$(dirname "$(realpath "$0")")"

# removed due to astyle mangling my code formatting - if another tool is found that will properly align everything (something something haskell prettify), please make this script use that
#astyle --options=astylerc ./*.c ./*.h ./*.cpp ./*.hpp

cmake --build build --target Cppcamlexample --config Debug

