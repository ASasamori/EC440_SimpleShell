override CFLAGS := -std=gnu99 -O0 -Wall -Werror -g  -fsanitize=undefined $(CFLAGS) -I.
override LDFLAGS := -fsanitize=undefined -fsanitize=leak $(LDLAGS)  
CC = gcc

# I generally make the first rule run all the tests
all: check

# rule for making the parser.o  that is needed by all the test programs
myshell_parser.o: myshell_parser.c myshell_parser.h

myshell.o: myshell.c myshell.h

# each of the test files depend on their own .c and myshell_parser.h
#  add another time for each test, e.g., test_simple_pipe.o line below
test_simple_input.o: test_simple_input.c myshell_parser.h
test_simple_pipe.o: test_simple_pipe.c myshell_parser.h

andrewsTest.o: andrewsTest.c andrewsTest.h

# each of the test programs executables are generated by combining the generated .o with the parser.o
test_simple_input : test_simple_input.o myshell_parser.o
test_simple_pipe : test_simple_pipe.o myshell_parser.o

# Add any additional tests here
test_files=./test_simple_input ./test_simple_pipe

.PHONY: clean check checkprogs all

# Build all of the test program
checkprogs: $(test_files)

check: checkprogs
	/bin/bash run_tests.sh $(test_files)

clean:
	rm -f *~ *.o $(test_files) $(test_o_files)
