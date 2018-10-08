//Lab6.cpp
//Program for testing heap
//Programmer: Malcolm Milton
//Date: 5/7/15

#include "Heap.h"
#include <iostream>
using namespace std;

int menu(); //Function to ask user what they would like to do with the array and returns thier answer in number form

int main()
{
	Heap *heap = new Heap(); //Creates a new instance of the Heap class
	int choice = 0; //Variable that will hold the user's answer to the menu() function
	
	cout << endl;
	
	while(choice != 5) //Runs until the user wants to quit the program (chooses option 5)
	{
		choice = menu(); //Calls the function to ask the user what they want to do with the heap and saves the answer in the variable

		if(choice == 1) //If the user wants to insert a new node into the heap
			heap->insert(); //Calls the function to insert a new node into the heap
		else if(choice == 2) //If the user wants to print out the largest node in the heap
			heap->printMax(); //Calls the function to print out the largest node in the heap
		else if(choice == 3) //If the user wants to take out the largest node in the heap
			heap->extractMax(); //Calls function to take out the largest node in the heap
		else if(choice == 4) //If the user wants to print the contents of the heap
			heap->printHeap(); //Calls the function to print the contents of the heap (by ascending index order)
		else if(choice == 5) //If the user wants to print out the contents of the heap in ascending order by value, and then quit the program
			heap->heapSort(); //Calls the function to print out the contents of the heap in ascending order by value
	}
	cout << "Thank you for using this program" << endl << endl;
	return 0;
}

int menu() //Function to ask user what they would like to do with the array and returns thier answer in number form
{
	int choice; //Variable that will save the user's answer
	
	cout << "Please choose an option:" << endl;
	cout << "1. Insert Element \n2. Maximum Value \n3. Extract Maximum Element \n4. Print Heap \n5. Heap Sort and Quit" << endl;
	cin >> choice; //Saves the user's answer

	while(choice < 1 || choice > 5) //Loops until the user chooses a number 1-5
	{
		cout << "Please choose a valid choice: ";
		cin >> choice; //Saves the user's answer
	}
	cout << endl;
	return choice; //Returns the user's answer
}
