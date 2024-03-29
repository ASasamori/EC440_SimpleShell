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

Got help for implementing redirection here: https://stackoverflow.com/questions/11515399/implementing-shell-in-c-and-need-help-handling-input-output-redirection

Source code for the blog is here: https://github.com/brenns10/lsh/blob/407938170e8b40d231781576e05282a41634848c/src/main.c

Cross referenced that blog and these 2 to start implementing the REPL (Read, Evaluate Print, Loop) aspect of the shell. Was very daunted and didn't know how to start before reading:
https://medium.com/@santiagobedoa/coding-a-shell-using-c-1ea939f10e7e
https://danishpraka.sh/posts/write-a-shell/

Got a clearer understanding of how the fork process works by using this blog:
https://indradhanush.github.io/blog/writing-a-unix-shell-part-1/

Also found out how to properly pipe using the dup2 function using this Stack Overflow thread:
https://stackoverflow.com/questions/33884291/pipes-dup2-and-exec

Was still confused, so cross referenced the piping structure and read source code for it.
Blog: https://medium.com/@avocadi/creating-my-own-shell-for-fun-635ea0d3f7b7
Source code: https://github.com/yongjoon-km/ysh/blob/main/main.c

Was very confused on how to treat zombies/signal handling and needed to read this reddit thread:
https://www.reddit.com/r/C_Programming/comments/772qhf/writing_a_shell_in_c_how_do_i_use_signal_handling/

And of course, referenced the slides for conceptul understanding:
https://piazza.com/class_profile/get_resource/lqnz3iw9y02fc/lrzfklq1p9une
https://piazza.com/class_profile/get_resource/lqnz3iw9y02fc/lrzbhyowb0r1c6
