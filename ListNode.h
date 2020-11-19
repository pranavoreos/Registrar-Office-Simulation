/*
Pranav Saravanan
Student id: 2341335
Email: saravanan@chapman.edu
CPSC 350-01
Registrar’s Office Simulation
*/

#include <iostream>

using namespace std;

template <class temp>
class ListNode{
  private:

	public:
    ListNode();
    ListNode(temp d);
    ~ListNode();

    temp data;
    ListNode<temp> *next;
    ListNode<temp> *prev;

  };

  template <class temp>
  ListNode<temp>::ListNode(){

  }

  template <class temp>
  ListNode<temp>::ListNode(temp d){
    data = d;
		next = NULL;
		prev = NULL;
  }

  template <class temp>
  ListNode<temp>::~ListNode(){
    if (next != NULL){
      next = NULL;
			prev = NULL;
      delete next;
      delete prev;
    }
  }
