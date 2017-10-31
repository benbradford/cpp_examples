An explanation of the different variable types

Here we describe ints, decimals, bool, chars.
We also describe the difference between signed and unsigned numbers.

There is a template function here which is used to help output information on each variable type.
Have a look, but don't get too bogged down in the detail of this function, it will be explained in a later example.

Note that everything exists inside only 1 main.cpp file, for convenience.
This could've been seperated out into header and cpp file(s), but it is
all in one file instead, to illustrate that this is possible.

To run this program, from this directory, do the following:

`mkdir bin`          	- this will create a directory for our binaries<br>
`cd bin`             	- enter this directory<br>
`cmake ..`           	- invokes CMakelists.txt and places binaries in bin folder<br>
`make`               	- starts compiling and generating the executable<br>
`./vars`      		    - run the created executable<br>
