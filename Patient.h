#ifndef PATIENT_H
#define PATIENT_H

#include <string>

struct Patient
{
    
    std::string name;
    int priority;
    int operationTime;
    bool operator<(const Patient & p)const{
		if( this->priority < p.priority ) 
			return true;
		else if( this->priority > p.priority ) 
			return false;
		else if( this->operationTime < p.operationTime ) 
			return true;
		return false;
	};
	bool operator>(const Patient & p)const{
		if( this->priority > p.priority )
			return true;
		else if( this->priority < p.priority ) 
			return false;
		else if( this->operationTime > p.operationTime ) 
			return true;
		return false;
	};
};



#endif