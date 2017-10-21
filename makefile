compile: linked_list.o music_lib.o main.o
	gcc -o test linked_list.o music_lib.o main.o
clean: 
	rm *.o
	rm *~
run: compile
	test
compile_debug: linked_list.c list_headers.h music_lib.c lib_headers.h main.c
	gcc -g -o test_debug linked_list.c music_lib.c main.c
run_debug_valgrind: compile_debug
	valgrind --leak-check=yes test_debug
run_debug_gdb: compile_debug
	gdb test_debug
linked_list.o: linked_list.c list_headers.h 
	gcc -c linked_list.c
music_lib.o: music_lib.c list_headers.h lib_headers.h
	gcc -c music_lib.c
main.o: main.c list_headers.h lib_headers.h
	gcc -c main.c
