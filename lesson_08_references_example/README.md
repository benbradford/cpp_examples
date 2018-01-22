An introduction to references

A reference is an alias to another variable.

When you declare a reference, you have to give another variable as a value.
The & symbol is used to denote that a variable is a reference.

int i = 7;
int& r = i;

Here both i and r refer to the same value: 7.

To run this program, from this directory, do the following:

`make`               - starts compiling and generating the executable<br>
`bin/references`      - run the created executable
