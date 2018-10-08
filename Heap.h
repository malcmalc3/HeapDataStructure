//Heap.h
//Declaration of Heap class
//Programmer: Malcolm Milton
//Date: 5/7/15

#ifndef HEAP_H
#define HEAP_H

class Heap
{
	private:
		int array[100];
		int heapSize;
		int parent(int);
		int leftChild(int);
		int rightChild(int);
		void heapify(int);
		void buildHeap();
	public:
		Heap();
		void insert();
		void heapSort();
		void extractMax();
		void printMax();
		int maximum();
		void printHeap();
		void swap(int, int);
};

#endif
