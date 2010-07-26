run : quick_sort.o 
	gcc -o run quick_sort.o
main.o : quick_sort.c
	gcc -c -o quick_sort.o quick_sort.c
