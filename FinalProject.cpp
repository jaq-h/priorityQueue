#include "QueueLL.h"
#include "QueueBH.h"
#include "Patient.h"
#include "Compare.h"
#include <time.h>
#include <cmath>
#include <queue>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

void test(Patient *data[], int index);
void printData(float mat[502][6]);
 
int main(int argc, char* argv[])
{
	ifstream inFile;
	std::string line;
	Patient * data[880];
	int index =1;
	inFile.open(argv[1]); 
	if (inFile.is_open()) 
	{
		cout << "opened successfully" << endl;
		string header;
		getline(inFile,header,'\r');
		while(getline(inFile,line,'\r'))
		{
			string dat;
			stringstream s(line);
			Patient * temp = new Patient;
			for(int i =0; i<3; i++)
			{
				if(i==0)
				{
					getline(s,dat,',');
					temp->name = dat;
				}
				else if(i==1)
				{
					getline(s,dat,',');
					temp->priority = stoi(dat);
				}
				else if(i==2)
				{
					getline(s,dat);
					temp->operationTime = stoi(dat);
				}
			}
			data[index] = temp;
			index++;
		}
		test(data,index);

	

	}

	return 0;
}



void test(Patient *data[], int index)
{
		QueueLL q;
		QueueBH *q2 = new QueueBH(880);
		priority_queue <Patient, vector<Patient>,compare> q3;
	
	for(int size=100; size<=800; size+=100) //runs through different size tests
	{
		float mat[502][6];

		int r = rand()%(index-size); //random start index of data
		//cout <<r;i
		Patient * temp[size]; 
		for(int i =0; i<size;i++)
		{
			temp[i] = data[i+r];
		}
		for(int x =0; x<500; x++)
		{
			clock_t t1, t2;
			float  t;

			//Binary Heap Enqueue
		    t1 = clock();
			for( int i=1; i<size;i++) 
			{
				q2->push(*data[i]); 
			}
			t2 = clock();
			t = (((float)t2-(float)t1)/CLOCKS_PER_SEC)*1000; 
			mat[x][0] = t;
			mat[500][0] = mat[500][0] + t;

			//Binary Heap Dequeue
			t1 = clock();
			for( int i=1; i<size;i++) 
			{
				q2->pop();
			}
			t2 = clock();
			t = (((float)t2-(float)t1)/CLOCKS_PER_SEC)*1000;  
			mat[x][1] = t;
			mat[500][1] = mat[500][1] + t;

			 //STL Enqueue
			t1 = clock();
			for( int i=1; i<size;i++)
			{
				q3.push(*data[i]);
			}
			t2 = clock();
			t = (((float)t2-(float)t1)/CLOCKS_PER_SEC)*1000; 
			mat[x][2] = t;
			mat[500][2] = mat[500][2] + t;

			//STL Dequeue
			t1 = clock();
			for( int i=1; i<size;i++) 
			{
				q3.pop();
			}
			t2 = clock();
			t = (((float)t2-(float)t1)/CLOCKS_PER_SEC)*1000; 
			mat[x][3] = t;
			mat[500][3] = mat[500][3] + t;

			//Linked List Enqueue
			t1 = clock();
			for(int i=1; i<size;i++) 
			{
				q.insert(*data[i]);
			}
			t2 = clock();
			t = (((float)t2-(float)t1)/CLOCKS_PER_SEC)*1000;  
			mat[x][4] = t;
			mat[500][4] = mat[500][4] + t;

			//Linked List Dequeue
			t1 = clock();
			for(int i=1; i<size;i++) 
			{
				q.deleteMin();
			}
			t2 = clock();
			t = (((float)t2-(float)t1)/CLOCKS_PER_SEC)*1000; 
			mat[x][5] = t;
			mat[500][5] = mat[500][5] + t;

		}
	
		for(int i =0; i<6; i++)
		{
			mat[500][i] = mat[500][i]/500.0;
		}
		for(int i=0; i<6; i++)
		{
			float std;
			for(int y = 0; y<500; y++) //sum
			{
				std = std + pow((mat[y][i] - mat[500][i]),2.0 );//x-u^2

			}
			std = sqrt(std/499.0); 
			mat[501][i] = std;
		}
		cout<<"-------------- size:"<<size<<" --------------------------------------"<<endl;
		printData(mat);
	}
	
}
void printData(float mat[502][6])
{
	cout << "BH-EnQ   /  BH-DeQ   |  STL-EnQ   /  STl-DeQ   |  LL-EnQ  /  LL-DeQ"<<endl;

	for(int y=500; y<502; y++)
	{
		if(y==500)
		{
			cout << "Average: "<<endl;
		}
		else if(y==501)
			cout <<"Standard Deviation:"<<endl;
		for(int x =0; x<6; x++)
		{
			cout <<mat[y][x] <<" ";
			if(x==5)
				cout<<endl;

		}
	}

}