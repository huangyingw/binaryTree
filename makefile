run : BiTree.o 
	gcc -o run BiTree.o
main.o : BiTree.c,Bitree.h
	gcc -c -o BiTree.o BiTree.c,Bitree.h
