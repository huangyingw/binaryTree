run : binaryTree.o 
	gcc -o run binaryTree.o
main.o : binaryTree.c
	gcc -c -o binaryTree.o binaryTree.c
