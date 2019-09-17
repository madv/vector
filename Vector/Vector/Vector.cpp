#include <iostream>
#include "Vector.h"
using namespace std;

/*
Purpose: Makes array elements 0, makes s assigned to Size, and allocates memory.
Pre-condition: Vector.h file created
Post-condition: Makes all entries 0.
*/
Vector::Vector(int s)
{
	this->size = s;

	entries = new int[size]; //pointer to an array of ints on the heap

	for (int index = 0; index < size; index++)
	{
		entries[index] = 0; //intialze all values to 0 of an array of size s
	}

}


/*
Pre-condition: Deep copy function created.
Post-condition: Makes a deep copy of vector right hand side.
*/
Vector::Vector(const Vector& rhs)
{
	deepCopy(rhs);
}


/*
Pre-condition: Deep copy function created.
Post-condition: Makes a self deep copy of right hand side.
*/
Vector Vector::operator= (const Vector& rhs)
{

	delete[] entries;
	deepCopy(rhs);

	return *this;
}


/*
Pre-condition: None
Post-condition: Deletes entry array and initialzes size to 0.
*/
Vector::~Vector() // default destructor  
{
	delete[] entries;
	size = 0; //reset size var
}


/*
Pre-condition: pos < size and 0 <= pos (index)
Post-condition: Returns entries at index.
*/
int& Vector::operator[](int index) // if 0 <= pos < size    
{
	if (0 <= index && index < size)
	{
		return entries[index];
	}
}


/*
Pre-condition: None
Post-condition: Returns the number of entries
*/
int Vector::length()
{
	return size;
}


/*
Pre-condition: Needs rhs arguement
Post-condition: Deep copies vector
*/
void Vector::deepCopy(const Vector& rhs)
{
	this->size = rhs.size;
	entries = new int[size]; //allocate for for new array of ints on the heap
	for (int index = 0; index < size; index++)
	{
		entries[index] = rhs.entries[index]; // fill that array from old info, making a deep copy

	}
}