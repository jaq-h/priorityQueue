#include "QueueLL.h"
#include "Patient.h"
#include "PatientNode.h"
#include <iostream>

using namespace std;

QueueLL::QueueLL()
{
	head = NULL;
	tail = NULL;

}

void QueueLL::insert(Patient p)
{
	PatientNode *current = head;
	PatientNode *temp = new PatientNode(p);

	if (head == NULL){
		head = temp;
	} 
	else 
	{
		if(head->p >temp->p)
		{
			temp->next = head;
			head = temp;
		}
		else
		{
			while(current->next != NULL && current->next->p < temp->p)
			{
				current = current->next;
			}
			temp->next = current->next;
			current->next = temp;
		}
	}
}

Patient QueueLL::deleteMin()
{
	Patient temp = head->p;
	head = head->next;
	return temp;
}
void QueueLL::print()
{
	Patient temp = this->deleteMin();
	cout<<temp.name<<", "<<temp.priority<< ", "<<temp.operationTime<<endl;

}


