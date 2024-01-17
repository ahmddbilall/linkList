#include <iostream>
using namespace std;

class node {
	int data;
	node* next;
	friend class circular_link_list;
public:
	node(int data)
	{
		this->data = data;
		next = nullptr;
	}
};

class circular_link_list {
	node* head;
public:
	circular_link_list()
	{
		head = nullptr;
	}

	circular_link_list(int data)
	{
		node* newnode = new node(data);
		head = newnode;
		newnode->next = head;
	}

	void insert(int data)
	{
		node* newnode = new node(data);
		node* temp = head;
		while (temp->next != head)
		{
			temp = temp->next;
		}
		temp->next = newnode;
		newnode->next = head;
	}

	void print()
	{
		node* temp = head;
		while (temp->next != head)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << temp->data;
	}
};


int main()
{
	circular_link_list l1(2);
	l1.insert(3);
	l1.insert(4);
	l1.insert(5);
	l1.insert(6);
	l1.print();

}
