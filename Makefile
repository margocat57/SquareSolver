.PHONY: all clean
all: quadratic tests

CFLAGS = -Wall -Wextra -Weffc++ -Waggressive-loop-optimizations 

quadratic: main.o input.o clear_input.o solver.o output.o
	$(CC) -o $@ $^ 

tests: main_for_test.o input.o clear_input.o solver.o output.o tests_for_solver.o work_with_file.o
	$(CC) -o $@ $^ 

clean:
	rm -f *.o quadratic
#main.o: main.cpp *h
#input.o: input.cpp *h
#clear_input.o: clear_input.cpp *h
#solver.o: solver.cpp *h
#output.o: output.cpp *h
#tests.o: tests.cpp *h
#main_for_test.o: main_for_test.cpp *h
#work_with_file.o: work_with_file.cpp *h
