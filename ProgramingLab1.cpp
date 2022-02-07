//Name: Andrew Kinney
//Title: Program Lab 1
//Description: Four programs dealing with arrays, functions, and pointers
//Date: 2.4.2022
//Course: Data Structures
//File: Main

#include <iostream>

using namespace std;

float findAverage(int *array, int size);
void swapThroughPointers(int &p1, int &p2);
void swapByReference(int &num1, int &num2);
void swapPointers(int **p3, int **p4);

int main()
{
	//Problem 1
	float average;
	int a1[6] = { 1, 4, 8, 12, 7, 3};
	average = findAverage(a1, 6);
	cout << "The average of a1 is: " << average << endl << endl;

	//Problem 2
	int a2[8] = {56, 61, 33, 90, 82, 15, 25, 49};
	int *p[8];
	for (int i = 0; i < 8; i++)
		p[i] = &a2[i];
	cout << "Pointer array elements are as follows...\n";
	for (int i = 0; i < 8; i++)
		cout << "Element " << i << ", " << "value: " << *p[i] << ", address: " << p[i] << endl;
    cout << endl;

	//Problem 3A and B
    int num1 = 4, num2 = 7;
    int *p1 = &num1;
    int *p2 = &num2;
    cout << "Num 1: " << num1 << " Num 2: " << num2 << endl;
    swapThroughPointers(*p1, *p2);
    cout << "Num 1: " << num1 << " Num 2: " << num2 << endl;
    swapByReference(num1, num2);
    cout << "Num 1: " << num1 << " Num 2: " << num2 << endl << endl;

    //Problem 4
    int num3 = 5, num4 = 8;
    int *p3 = &num3;
    int *p4 = &num4;
    cout << "Num 3 Value: " << num3 << endl << "p3 Address: " << p3 << endl
         << "Num 4 Value: " << num4 << endl << "p4 Address: " << p4 << endl;
    swapPointers(&p3, &p4);
    cout << "Num 3 Value: " << num3 << endl << "p3 Address: " << p3 << endl
         << "Num 4 Value: " << num4 << endl << "p4 Address: " << p4;
    
	return 0;
}

//Problem 1
float findAverage(int *a, int size)
{
	float sum = 0, average;

	for (int i = 0; i < size; i++)
		sum += a[i];

	average = sum / size;

	return average;
}

//Problem 3A
void swapThroughPointers(int &p1, int &p2)
{
    int temp = p1;
    p1 = p2;
    p2 = temp;
    return;
}

//Problem 3B
void swapByReference(int &num1, int &num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
    return;
}

//Problem 4
void swapPointers(int **p3, int **p4)
{
    int* temp;
    temp = *p3;
    *p3 = *p4;
    p4 = &temp;
    return;
}