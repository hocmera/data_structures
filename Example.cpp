// Copyright (c) 2019 HocMera
// Distributed under the GPL software license
// Example for using a generic circular queue

#include "stdafx.h"
#include "iostream"
#include "CircularQueue.h"

using namespace std;

int main()
{

	 size_t queuesize; // queue size
	 int data; // data variable used for queue/dequeue
	 int typed; // user operation selection

	 cout<< "****GENERIC QUEUE IMPLEMENTATION****"<<endl;
	 cout<< "please enter the queue size: ";
	 cin>>queuesize;
	 CircularQueue<int>* queue1 = new CircularQueue<int>(queuesize); // dynamic memory allocation of an int-type queue


	 do {
	     cout<<"what do you want do? enqueue: 1, dequeue: 2, available space: 3. quit: 4"<<endl;
	     cin>>typed;
	     switch(typed){
	         case 1:
	         cout<< "enter an integer: "<<endl;
	         cin>>data;
	         if (queue1->EnQeue(data));
	         else cout<<"QUEUE IS FULL!"<<endl;
	         cout<<"available memory is: "<<queue1->AvlQueueSpace()<<endl;
	         break;
	         case 2:
	         if (queue1->DeQeueu(data)){
	         cout<<data<<endl;
	         } else cout<<"NOTHING TO READ!"<<endl;
	         break;
	         case 3:
	         cout<<"available memory is: "<<queue1->AvlQueueSpace()<<endl;
	         break;
	         case 4:
	         queue1->~CircularQueue();
	         cout<<"good bye!"<<endl;
	         break;
	     }

	 } while (typed!=4);


	return 0;

}




