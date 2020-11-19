/*
Pranav Saravanan
Student id: 2341335
Email: saravanan@chapman.edu
CPSC 350-01
Registrar’s Office Simulation
*/

#include <iostream>
#include "ListNode.h"

using namespace std;

template <class temp>
class DoublyLinkedList{
	private:

	public:
		DoublyLinkedList();
		~DoublyLinkedList();

		ListNode<temp> *front;
		ListNode<temp> *back;
		unsigned int size;

		bool isEmpty();
    unsigned int getSize();
		temp getFront();

	};

	template <class temp>
	DoublyLinkedList<temp>::DoublyLinkedList(){
		size = 0;
		front = NULL;
		back = NULL;
	}

	template <class temp>
	DoublyLinkedList<temp>::~DoublyLinkedList(){

	}

	template <class temp>
	temp DoublyLinkedList<temp>::getFront(){
		return front->data;
	}

	template <class temp>
	unsigned int DoublyLinkedList<temp>::getSize(){
		return size;
	}

	template <class temp>
	bool DoublyLinkedList<temp>::isEmpty(){
		return (size == 0);
	}
