A simple hello world program.

This project contains an inc folder of headers, a src folder of cpp files and
a CMakeLists.txt file, which tells the compiler how to compile this project.

The main function is in main.cpp. It uses a function called PrintHelloWorld.
PrintHelloWorld is DECLARED in MyFunctions.h and DEFINED in MyFunctions.cpp

main.cpp has to #include the MyFunctions.h file in order to use these functions.

It then calls another function PrintGoodbye which returns an integer.

This integer is returned at the end of the main function.


To run this program, from this directory, do the following:

mkdir bin          - this will create a directory for our binaries
cd bin             - enter this directory
cmake ..           - invokes CMakelists.txt and places binaries in bin folder
make               - starts compiling and generating the executable
./hello_world      - run the created executable