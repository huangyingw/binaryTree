run : BiTree.o 
	g++ -o run BiTree.o
main.o : BiTree.cpp
	g++ -c -o BiTree.o BiTree.cpp
