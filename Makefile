main : main.c root.c root.h
	gcc main.c root.c -o main -lm
test : main_test.c test.c ctest.h
	gcc main_test.c test.c root.c -o test_test -lm
	./test_test
