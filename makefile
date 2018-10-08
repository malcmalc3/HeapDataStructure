All: Heap

Heap: Heap.o Lab8.o
	g++ Heap.o Lab8.o -o Heap

Heap.o: Heap.cpp
	g++ -c Heap.cpp

Lab8.o: Lab8.cpp
	g++ -c Lab8.cpp

clean:
	rm -rf *o Heap
