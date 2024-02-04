# EC440: Shell Parser

The sample code provided for the Parser includes:

- [Makefile](Makefile): The Makefile that builds your parser, tests, and runs your test programs as described [here](https://openosorg.github.io/openos/textbook/intro/tools-make.html#a-simple-example)
- [myshell_parser.h](myshell_parser.h): The header file that describes the structures and interfaces that clients of your parser needs to know (see [this](https://openosorg.github.io/openos/textbook/intro/tools-testing.html#testing)).
- [myshell_parser.c](myshell_parser.c): An initial stub implementation of the functions that you will need to fill in.
- [run_tests.sh](run_tests.sh): A shell script, described [here](https://openosorg.github.io/openos/textbook/intro/tools-shell.html#shell) for automating running all the tests

Two example test programs that exercise the interface of the parser, discussed [here](https://openosorg.github.io/openos/textbook/intro/tools-testing.html#testing), are:

- [test_simple_input.c](test_simple_input.c): Tests parsing the command 'ls'
- [test_simple_pipe.c](test_simple_pipe.c): Tests parsing the command 'ls | cat`

Got information from the blog of https://brennan.io/2015/01/16/write-a-shell-in-c/
Subsequently, used the code from the blog as a guideline: https://github.com/brenns10/lsh/blob/407938170e8b40d231781576e05282a41634848c/src/main.c
