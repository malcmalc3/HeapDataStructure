//Heap.cpp
//Heap class member functions
//Programmer: Malcolm Milton
//Date: 5/7/15

#include <iostream>
#include "Heap.h"
using namespace std;

Heap::Heap() //Class constructor that initializes the array to have values, then puts them in order by heap property
{
	//Series of calls to initialize array to certain values
	array[0] = 4;
	array[1] = 12;
	array[2] = 3;
	array[3] = 19;
	array[4] = 23;
	array[5] = 5;
	array[6] = 32;
	array[7] = 11;
	array[8] = 2;
	array[9] = 24;
	heapSize = 10; //There are 10 values to start with so heapSize needs to be 10 to start with
	buildHeap(); //Calls the function to put the heap in order by the heap property
}

int Heap::parent(int x) //Function to return the index in the array of the parent of the parameter node's index 
{
	return x/2; //The parent of the parameter node is located in half of the index of the array. (will still find correct index if parameter is odd)
}

int Heap::leftChild(int x) //Function to return the index in the array of where the left child of the parameter node should be, using the parameter node's index
{
	return (x*2) + 1; //The left child of a node will be twice the node's index plus 1
}

int Heap::rightChild(int x) //Function to return the index in the array of where the right child of the parameter node should be, using the parameter node's index
{
	return (x*2) + 2; //The right child of a node will be twice the node's index plus 2
}

void Heap::heapify(int x) //Recursive function to make sure the parameter node's children are both smaller. Calls heapify again on the new child node if a change occurs
{
	int left = leftChild(x); //Finds the left child index of the parameter node
	int right = rightChild(x); //Finds the right child index of the parameter node
	int max = x; //Variable to hold the index of the largest valued node, initially the parameter node
	
	if(array[left] > array[max]) //If the left child of the parameter is bigger than the current maximum node
		max = left; //Sets the maximum node index to the left child index
	if(array[right] > array[max]) //If the right child of the parameter is bigger than the current maximum node
		max = right; //Sets the maximum node index to the right child index
	
	if(max != x) //If the parent node does not have the largest value
	{
		swap(x, max); //Calls function to swap the information in the indexes of the parent node and the maximum node
		heapify(max); //Calls heapify again to make sure the new child node's childen have the heap property
	}
}

void Heap::buildHeap() //Function to sort the whole heap so that every node maintains the heap property
{
	int x = (heapSize/2) - 1; //This is the index of the last node that has children, because nothing needs to be done for a node with no children

	for(x; x >= 0; x--) //Loop to start at the last node that has children, and decrements to the first index (0)
		heapify(x); //Calls the recursive function heapify for the current node
}

void Heap::insert() //Function to insert a new node into the heap
{
	if(heapSize != 100) //If there is space in the heap to insert a new node
	{
		int choice; //Variable that will hold the information of the new node to insert
		cout << "Please enter a number to insert into the array: ";
		cin >> choice; //Saves the user's answer to insert

		array[heapSize] = choice; //Puts the new information in the index that's one above the last node in the heap
		heapSize++; //Increases the size of the heap to allow the new node into the heap
		
		buildHeap(); //Calls the function to put the new node in the correct place by organizing the heap according to the heap property

		cout << "Number inserted into heap" << endl << endl;
	}
	else //If there is no more space in the heap to insert a new node
		cout << "The heap is full" << endl << endl;
}

void Heap::heapSort() //Function to outprint the numbers of the heap in ascending order
{
	int max; //Variable that will hold the index of the current maximum node
	int startSize = heapSize; //Variable that starts at the heapSize and will decrement until there are no more nodes in the array to find a maximum node for
	while(heapSize != 0) //Loops until there are no more nodes in the array to find a maximum node for
	{
		max = maximum(); //Calls the function to find the maximum value in the sub-array
		swap(max, heapSize-1); //Swaps the information of the largest index with the last index in the sub-array
		heapSize--; //Decrements the size of the sub-array
	}
	heapSize = startSize; //Sets the heapSize to what it started out as
	printHeap(); //Calls function to print the array (will be in acending order)
}

void Heap::extractMax() //Function to delete the maximum value of the heap (will always be the first node when this function is called)
{
	if(heapSize != 0) //If there are nodes in the heap to extract
	{
		swap(0, heapSize-1); //Swaps the information of the first (largest value) and last indexes
		array[heapSize-1] = 0; //Makes the information of the previous maximum node to 0
		heapSize--; //Decreases the size of the heap
		buildHeap(); //Calls the function to put the new node in the correct place by organizing the heap according to the heap property
		cout << "Maximum value extraxted" << endl << endl;
	}
	else //If there are no nodes in the heap to extract
		cout << "The heap is empty" << endl << endl;
}

int Heap::maximum() //Function to return the index of the maximum value in the array
{
	int max = 0; //Variable that will hold the index of the largest value, starts at 0 to start comparison from the first node
	
	for(int x=0; x < heapSize; x++) //Starts at the first index (0) and the loop increments until the last node in the heap is reached
		if(array[x] > array[max]) //If the current node is larger than the current max node
			max = x; //Sets the new max index to the current index
	return max; //Returns the index of the largest node
}

void Heap::printMax() //Function to print the largest node in the heap
{
	if(heapSize == 0) //If there are no nodes in the heap
		cout << "The heap is empty" << endl << endl;
	else
		cout << "The maximum value in the heap is " << array[maximum()] << endl << endl; //Calls function to find the index of the largest value and prints its information
}

void Heap::printHeap() //Function to print the information of the heap in ascending order by index
{
	for(int x=0; x<heapSize; x++) //Starts at the first index and loops until the last index in the heap is reached
		cout << array[x] << " "; //Prints the information of the current index
	cout << endl << endl;
}

void Heap::swap(int x, int y) //Function to swap the information in the two parameter indexes
{
	int temp = array[x]; //Variable to hold the information of the first parameter index
	array[x] = array[y]; //Sets the first parameter's information to the second parameter's information
	array[y] = temp; //Sets the information of the second parameter's information to the variable that holds the previous information of the first parameter
}
