#ifndef QUEUEBH_H
#define QUEUEBH_H
#include<iostream>
#include "Patient.h"


class QueueBH
{
		

    public:
        QueueBH(int);
        ~QueueBH();     
        void push(Patient);
        Patient pop();  
        void print();
    private:
    	Patient *arr;
		int capacity;
		int heapSize;
		void heapify(int);
		int right(int);
        int parent(int);
        int left(int);
        

};

#endif 