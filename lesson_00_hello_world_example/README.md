A simple hello world program.

This project contains an inc folder of headers, a src folder of cpp files and
a CMakeLists.txt file, which tells the compiler how to compile this project.

The main function is in main.cpp. It uses a function called PrintHelloWorld.
PrintHelloWorld is DECLARED in MyFunctions.h and DEFINED in MyFunctions.cpp

main.cpp has to #include the MyFunctions.h file in order to use this function.


To run this program, from this directory, do the following:

`make`               - starts compiling and generating the executable<br>
`./bin/hello_world`  - run the created executable
