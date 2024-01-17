#include<iostream>
using namespace std;

class Node {
	friend class DoublyLinkedList;
private:
	int data;
	Node* next;
	Node* prev;
	Node(int d) {

		this->data = d;
		this->next = nullptr;
		this->prev = nullptr;
	}
};

class DoublyLinkedList {
private:
	Node* head;
public:
	DoublyLinkedList()
	{
		head = nullptr;
	}

	void insertAtEnd(int d)
	{
		Node* newNode = new Node(d);
		if (head == nullptr) {
			head = newNode;
			return;
		}
		else {
			Node* curr = head;
			while (curr->next != 0)
			{
				curr = curr->next;
			}

			curr->next = newNode;       
			newNode->prev = curr;       
		}
	}


	void display()
	{
		Node* curr = head;
		while (curr != 0)
		{
			cout << curr->data << " -> ";
			curr = curr->next;
		}

	}

	void reverseDisplay()
	{
		Node* tail = head;
		while (tail->next != 0)      
		{
			tail = tail->next;
		}
		while (tail != 0)            
		{
			cout << tail->data << " -> ";
			tail = tail->prev;       
		}
	}

	void deleteSecondLastNode()
	{
		Node* secondLast = head;
		while (secondLast->next->next != 0)
		{
			secondLast = secondLast->next;
		}
		secondLast->prev->next = secondLast->next;      
		secondLast->next->prev = secondLast->prev;      
		delete secondLast;
		secondLast = nullptr;
	}


	void insertAtStart(int d)
	{
		Node* n = new Node(d);
		n->next = head;
		head->prev = n;
		n->prev = nullptr;
	}



	void swap(Node* &temp, Node* &curr)
	{
		temp->next = curr->next;
		curr->prev = temp->prev;
		temp->prev = curr;
		curr->next = temp;

	}


	void selectionSort(Node* head) {
		Node* start = head;
		while (start != NULL) 
		{
			Node* min = start;
			Node* curr = start->next;
			while (curr != NULL) {
				if (curr->data < min->data) 
				{
					min = curr;
				}
				curr = curr->next;
			}
			int temp = start->data;
			start->data = min->data;
			min->data = temp;
			start = start->next;
		}
	}



	void merageTwoListsSorted(DoublyLinkedList l2)
	{
		//first merging

		Node* temp = this->head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = l2.head;
		selectionSort(this->head);
	}

};

int main()
{


	DoublyLinkedList l1;
	l1.insertAtEnd(1);
	l1.insertAtEnd(2);
	l1.insertAtEnd(3);
	l1.insertAtEnd(4);
	l1.insertAtEnd(5);
	l1.display();
	cout << endl;
	
	DoublyLinkedList l2;
	l2.insertAtEnd(6);
	l2.insertAtEnd(7);
	l2.insertAtEnd(8);
	l2.insertAtEnd(9);
	l2.insertAtEnd(10);

	l2.merageTwoListsSorted(l1);
	l2.display();
}
