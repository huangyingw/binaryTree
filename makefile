run : BiTree.o 
	g++ -o run BiTree.o
main.o : BiTree.cpp,Bitree.h
	g++ -c -o BiTree.o BiTree.cpp,Bitree.h
