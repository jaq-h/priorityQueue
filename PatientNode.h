#ifndef PATIENTNODE_H
#define PATIENTNODE_H
#include "Patient.h"

struct PatientNode{

	Patient p;
    PatientNode *next;

    PatientNode(Patient p){
    	this->p = p;
    	next = NULL;
    };



};
#endif