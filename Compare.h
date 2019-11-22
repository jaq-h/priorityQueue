#ifndef COMPARE_H
#define COMPARE_H
#include "Patient.h"

struct compare
{
    
   bool operator () (const Patient a, const Patient b)
   {
   		if(a.priority> b.priority)
   			return true;
   		else if(a.priority<b.priority)
   			return false;
   		else if(a.priority==b.priority)
   		{
   			if(a.operationTime>b.operationTime)
   				return true;
   			else if(a.operationTime<b.operationTime)
   				return false;
   			else if(a.operationTime == b.operationTime)
   			{
   				if(a.name>b.name)
   					return true;
   				else 
   					return false;
   			}
   		}
   		
   		return false;
   }
	
    
};
#endif