#ifndef QUEUELL_H
#define QUEUELL_H
#include<iostream>
#include "Patient.h"
#include "PatientNode.h"


class QueueLL
{
    public:
        QueueLL();
        void insert(Patient);
        Patient deleteMin();
        void print();
        
    private:
        PatientNode *head;
        PatientNode *tail;

};

#endif 