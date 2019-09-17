#pragma once
#ifndef VECTOR_H
#define VECTOR_H
class Vector
{
public:
	Vector(int s = 0);
	Vector(const Vector& rhs); // copy constructor 
	Vector operator= (const Vector& rhs); // makes self a deep copy of rhs 
	~Vector(); // default destructor  
	int& operator[](int index);
	int length();// returns the # of entries. 
private:
	int size;            //store the # of elements used  
	int *entries;
	void deepCopy(const Vector& rhs);
};
#endif