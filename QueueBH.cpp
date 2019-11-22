#include "QueueBH.h"
#include <iostream>
#include "Patient.h"
using namespace std;

void swap(Patient *x, Patient *y);

QueueBH::QueueBH(int max)
{
	heapSize =0;
	capacity = max;
	arr = new Patient[max];
}

QueueBH::~QueueBH()
{
	delete arr;
}
int QueueBH::right(int i)
{
	return (2*i+1);
}

int QueueBH::left(int i)
{

	return (2*i);
}
int QueueBH::parent(int i)
{
	return i/2;
}

void QueueBH::print()
{
	Patient temp = this->pop();
	cout<<temp.name<<", "<<temp.priority<< ", "<<temp.operationTime<<endl;

}

void QueueBH::push(Patient p) 
{
	if(heapSize == capacity)
		cout << "full";
	else
	{
		heapSize++;
		int i = heapSize;
		arr[i] = p;
		while( i>1 && arr[parent(i)]>arr[i])
		{
			swap(arr[i],arr[parent(i)]);
			i = parent(i);
		}
	}
}
Patient QueueBH::pop() 
{

	if(heapSize ==0 )
		cout << "empty";
	if(heapSize==1)
	{	heapSize--;
		return arr[1];
	}
	Patient top = arr[1];
	arr[1] = arr[heapSize ];
	heapSize--;
	heapify(1);
	return top;
}

void QueueBH::heapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if( l <= heapSize && arr[l]< arr[i])
		smallest = l;
	if( r <= heapSize && arr[r]< arr[smallest])
		smallest = r;
	if(smallest !=i)
	{
		swap(arr[i],arr[smallest]);
		heapify(smallest);
	}
}

void swap(Patient* x, Patient* y)
{
	Patient temp = *x;
	*x = *y;
	*y = temp;
}
