//Name: Andrew Kinney
//Title: Lab 6B
//Description:  Write the following functions for a doubly linked list: clear(),is_empty(),size(),pop_front(), and pop_back()
//Date: 4.4.2022
//Course: Data Structures
//File: Main

#include <iostream>
using namespace std;

//Node definition
struct Node 
{
	int val;
	Node* next;
	Node* prev;
};

//Function prototypes
void pop_back(Node*& tail);
void pop_front(Node*& head);
int size(Node* currentNode);
bool isEmpty(Node* head);
void clear(Node*& head);
void printList(Node* p);
void prepend(Node*& head, Node*& tail, int newVal);
void append(Node*& head, Node*& tail, int newVal);
void printListReversed(Node* currentNode);

int main() 
{
    //List 1
	Node* head = nullptr;
	Node* tail = nullptr;
	
	prepend(head, tail, 1);
	prepend(head, tail, 20);
	prepend(head, tail, 10);
	prepend(head, tail, 5);
	
	cout << "List 1 created using prepend" << endl;
	printList(head);
	printListReversed(tail);

    //List 2
	Node* head2 = nullptr;
	Node* tail2 = nullptr;
	
	append(head2, tail2, 35);
	append(head2, tail2, -25);
	append(head2, tail2, 4);
	append(head2, tail2, 96);
	append(head2, tail2, -234);
	cout << endl<< "List 2 created using append" << endl;
	printList(head2);
	printListReversed(tail2);
	
	//Demonstrate clear()
	clear(head);
	cout << endl << "List 1 after running clear()" << endl;
    printList(head);
    cout << endl;
    
    //Demonstrate isEmpty()
    if(isEmpty(head))
        cout << "List 1 is empty" << endl;
    else
        cout << "List 1 is not empty" << endl;
    if(isEmpty(head2))
        cout << "List 2 is empty" << endl;
    else
        cout << "List 2 is not empty" << endl << endl;
    
    //Demonstrate size()
    cout << "The size of list 1 is " << size(head) << endl;
    cout << "The size of list 2 is " << size(head2) << endl;
    
    //Demonstrate pop_front()
    cout << endl << "List 2 before pop_front()" << endl;
    printList(head2);
    cout << "List 2 after pop_front()" << endl;
    pop_front(head2);
    printList(head2);
    
    //Demonstrate pop_back()
    cout << endl << "List 2 before pop_back()" << endl;
    printList(head2);
    cout << "List 2 after pop_back()" << endl;
    pop_back(tail2);
    printList(head2);
    
    return 0;
}

//Remove last node in list 
void pop_back(Node*& tail)
{
    Node* temp = tail->prev;
    delete tail;
    tail = temp;
    tail->next = nullptr;
}

//Remove first node in list
void pop_front(Node*& head)
{
    Node* temp = head->next;
    delete head;
    head = temp;
    head->prev = nullptr;
}

//Finds the size of the list 
int size(Node* currentNode)
{
    int count = 0;
    while(currentNode != nullptr) 
	{
	    count++;
		currentNode = currentNode->next;
	}
	return count;
}

//Returns whether or not the list is empty
bool isEmpty(Node* head)
{
    if(head == nullptr)
        return true;
    return false;
}

//Empties the list of all nodes
void clear(Node*& currentNode)
{
    while(currentNode != nullptr) 
	{
	    Node* temp = currentNode->next;
        delete currentNode;
		currentNode = temp;
	}
}

//Prints all nodes' value in list
void printList(Node* currentNode) 
{
	while(currentNode != nullptr) 
	{
		cout << currentNode->val << "  ";
		currentNode = currentNode->next;
	}
	cout << endl;
}

//Inserts new node at front of list 
void prepend(Node*& head, Node*& tail, int newVal) 
{
    Node* newNode = new Node();
    newNode->val = newVal;
    
    //if empty
    if(head == nullptr)     
    {
        newNode->next = nullptr;
        newNode->prev = nullptr;
        tail = newNode;
        head = newNode;
        return;
    }
    
    //not empty
    newNode->next = head;         //previous head is now next
    head->prev = newNode;
    newNode->prev = nullptr;
    head = newNode;               //head now points at this node
    
	return;
}

//Inserts new node at end of list 
void append(Node*& head, Node*& tail, int newVal) 
{
	Node* newNode = new Node();
    newNode->val = newVal;
    
    //if list is empty
	if(head == nullptr)         
	{
        newNode->next = nullptr;
        newNode->prev = nullptr;
        head = newNode;
        tail = newNode;
        return;
	}
	
	//not empty, make new tail
    newNode->next = nullptr;
    newNode->prev = tail;
    tail->next = newNode;       //old tail becomes second to last in list
    tail = newNode;             //new tail becomes tail in main
	return;
}

//To test prev pointers
void printListReversed(Node* currentNode) 
{
	cout << "List in reverse" << endl;
	while(currentNode != nullptr) 
	{
		cout << currentNode->val << "  ";
		currentNode = currentNode->prev;
	}
	cout << endl;
}
