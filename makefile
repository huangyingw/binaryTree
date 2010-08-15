run : BiTree.o 
	gcc -o run BiTree.o
main.o : BiTree.cpp
	gcc -c -o BiTree.o BiTree.cpp