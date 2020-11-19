/*
Pranav Saravanan
Student id: 2341335
Email: saravanan@chapman.edu
CPSC 350-01
Registrar’s Office Simulation
*/

#include "ListNode.h"

template <class temp>
class Queue{

	public:
		Queue();
		~Queue();

		ListNode<temp> *front;
		ListNode<temp> *back;
		unsigned int size;

		void insert(temp d);
		temp remove();
		temp returnFront();

		bool isEmpty();
		unsigned int getSize();

	};

	template<class temp>
	Queue<temp>::Queue(){
		size = 0;
		front = NULL;
		back = NULL;
	}

	template<class temp>
	Queue<temp>::~Queue(){

	};

	template<class temp>
	void Queue<temp>::insert(temp d){
		ListNode<temp> *node = new ListNode<temp>(d);
		if (size == 0){
			front = node;
		}
		else{
			back->next = node;
			node->prev = back;
		}
		back = node;
		++size;
	}

	template<class temp>
	temp Queue<temp>::remove(){
		if (!isEmpty()){
			ListNode<temp> *previous = front;
			temp previousData = previous->data;
			if (front->next == NULL){
				front = NULL;
			  back = NULL;
			}
			else{
				front->next->prev = NULL;
				front = front->next;
			}
			delete previous;
			size--;
			return previousData;
		}
		else{
			return temp();
		}
	}

	template<class temp>
	temp Queue<temp>::returnFront(){
		return front->data;
	}

	template<class temp>
	bool Queue<temp>::isEmpty(){
		return (size == 0);
	}

	template<class temp>
	unsigned int Queue<temp>::getSize(){
		return size;
	}
