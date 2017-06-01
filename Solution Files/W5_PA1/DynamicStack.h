//Class template for a dynamic stack implemented as a linked list, and compatible with any data type.
//Demonstrated in W5_PA1_Source.cpp.
#pragma once
#include <iostream>
using namespace std;

template <class T>
class DynamicStack
{
private:
	struct node
	{
		T data;			//The data item held in the node
		node *next;		//Pointer to the next node in the list
	};
	
	node *top;			//Pointer to the top of the stack

public:
	//###########################################################################	
	//Constructor: sets top of the stack to nullptr, indicating an empty list.	#
	//###########################################################################
	DynamicStack()
	{ top = nullptr; }

	//###########################################################################	
	//Destructor: deletes all items in the stack.								#
	//###########################################################################
	~DynamicStack()
	{
		node *nodePtr = nullptr;
		node *nextNode = nullptr;

		//Position nodePtr at the top of the stack.
		nodePtr = top;

		//Traverse the list deleting each node.
		while (nodePtr != nullptr)
		{
			nextNode = nodePtr->next;
			delete nodePtr;
			nodePtr = nextNode;
		}
	}

	//###########################################################################	
	//Pop function to pull an item off the stack. Returns true if the operation	#
	//was successful, false if it was not (empty list).	Stores the value popped	#
	//off the stack in the "val" variable (passed by reference).				#
	//*Note: this function essentially combines pop() and isEmpty().			#
	//###########################################################################
	bool pop(T &val)
	{
		node *temp = nullptr;		//Pointer to hold the next node's location

		//If the stack is empty, display an error, and return to the calling function.
		if (!top)
		{
			cout << "Error: The stack is empty." << endl;
			return false;			//Return false, indicating the operation was not successful.
		}

		//Otherwise, pop the top value off of stack and store it in "val".
		else
		{
			val = top->data;		//Copy the data in the first item of the list into the "val" parameter
			temp = top->next;		//Store the address of the next value in the linked list in temp.
			delete top;				//Delete the first item in the linked list.
			top = temp;				//Set the address of top to the next value in the linked list.
			return true;			//Return true, indicating the operation was successful
		}
	}

	//###########################################################################	
	//Push function to add the data in "val" onto the top of the stack.			#
	//###########################################################################
	void push(T val)
	{
		node *newNode = nullptr;	//Pointer to a new node

		//Dynamically allocate a new node and store the information in "val" in it
		newNode = new node;
		newNode->data = val;

		//If the list is empty, make newNode the first node in the list.
		if (!top)
		{
			top = newNode;
			newNode->next = nullptr;
		}

		//Otherwise, insert newNode at the top of the stack.
		else
		{
			newNode->next = top;		//Point newNode to the item that was previously at the top of the list
			top = newNode;				//Point top to the new node we created, making it the top of the list
		}
	}

	//###########################################################################	
	//Display function to display all items currently in the stack.				#
	//###########################################################################
	void displayStack()
	{
		node *temp;			//Temporary node pointer to traverse the list
		temp = top;			//Start temp at the top of the list

		cout << "Here are the values currently in the stack:" << endl;

		//As long as temp is not pointing to nullptr (indicating the end of the list), display the data in the node.
		while (temp)
		{
			cout << temp->data << endl;		//Display the data in the node temp is pointing to
			temp = temp->next;				//Make temp point to the next node in the list
		}
		cout << endl;
	}
};

