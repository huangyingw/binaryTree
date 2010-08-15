run : BiTree.o 
	gcc -o run BiTree.o
main.o : BiTree.cpp,Bitree.h
	gcc -c -o BiTree.o BiTree.cpp,Bitree.h
