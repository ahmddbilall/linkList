#include <iostream>
using namespace std;

template <class L>
class LinkList;

template <class T>
class Node {
	T data;
	Node* next;
public:
	Node(T data)
	{
		this->data = data;
		this->next = nullptr;
	}
	
	friend class LinkList<T>;
	
	friend ostream& operator << (ostream& out, Node& node)
	{
		out << node.data;
		return out;
	}
	
	T getData()
	{
		return this->data;
	}

	Node* getNext()
	{
		return this->next;
	}

	void setNext(Node* next)
	{
		this->next = next;
	}

	void setData(T data)
	{
		this->data = data;
	}
	
	friend istream& operator >> (istream& in, Node& node)
	{
		in >> node.data;
		return in;
	}
};

template <class L>
class LinkList {
	Node<L>* head;
public:
	LinkList()
	{
		head = nullptr;
	}

	LinkList(L data)
	{
		head = new Node<L>(data);
	}
	
	
	bool insertAtEnd(L data)
	{
		Node<L>* node= new Node<L>(data);
		if (head == nullptr)
		{
			head = node;
			return true;
		}
		else
		{
			Node<L>* current = head;
			while (current->next != nullptr)
			{
				current = current->next;
			}
			current->next = node;
			return true;
		}
		return false;
	}
	bool insertAtStart(L data)
	{
		Node<L>* node = new Node<L>(data);
		if (head == nullptr)
		{
			head = node;
			return true;
		}
		else {
			Node<L>* current = head;
			node->setNext(head);
			head = node;
			node->next = current->next;
			return true;
		}
		return false;

	}
	bool insertAfterValue(L data,L value)//insert this data after given value
	{
		Node<L>* current = head;
		Node<L>* newNode = new Node<L>(data);

		while (current->getData() != value)
		{
			current = current->getNext();
		}
		newNode->setNext(current->getNext());
		current->setNext(newNode);


		return true;
	}
	void insertAtPosition(int element, int position)
	{
		Node<L>* newNode = new Node<L>(element);

		Node<L>* current = head;
		int i = 0;
		while (current != nullptr)
		{
			current = current->next;
			i++;
		}
		if (i < position)
		{
			return;
		}
		if (head == nullptr)
		{
			head = newNode;
		}
		else if (position == 0)
		{
			newNode->next = head;
			head = newNode;
		}
		else {
			i = 0;
			current = head;
			while (i + 1 < position)
			{
				current = current->next;
				i++;
			}
			if (current->next == nullptr)
				newNode->next = nullptr;
			else
				newNode->next = current->next;
			current->next = newNode;
		}
	}


	
	bool pop_back()
	{
		Node<L>* current = head;
		while ((current->getNext())->getNext() != nullptr)
		{
			current = current->getNext();
		}
		Node<L>* abc = current->getNext();
		current->setNext(nullptr);
		delete abc;
		abc = nullptr;
		return true;
	}
	void deleteValue(L value)
	{
		Node<L>* current = head;
		Node<L>* previousCurr = current;
		bool flag;
		while (current != nullptr)
		{
			flag = false;
			if (current->data == value && current == head)
			{
				head = current->next;
				current = current->next;
				delete previousCurr;
				previousCurr = current;
				flag = true;
			}
			else if (current->data == value)
			{
				previousCurr->next = current->next;
				delete current;
				current = previousCurr->next;
				flag = true;
			}
			if (flag == false)
			{
				previousCurr = current;
				current = current->next;
			}
		}
	}
	


	bool isEmpty()
	{
		if (head == nullptr)
			return true;
		return false;
	}
	L getMax()
	{
		if (head != nullptr)
		{
			Node<L>* current = head;
			L max = head->data;
			while (current != nullptr)
			{
				if (max < current->data)
					max = current->data;
				current = current->next;
			}
			return max;
		}
		else
			return new L(0);
	}
	L getMin()
	{
		if (head != nullptr)
		{
			Node<L>* current = head;
			L min = head->data;
			while (current != nullptr)
			{
				if (min > current->data)
					max = current->data;
				current = current->next;
			}
			return min;
		}
		else
			return new L(0);
	}
	int getSize()
	{
		int i = 0;
		Node<L>* curr = head;
		while (curr != nullptr)
		{
			i++;
			curr = curr->getNext;
		}
		return i;
	}
	

	bool reverseList()
	{
		Node<L>* current = head;;
		Node<L>* previous;
		Node<L>* next;
		previous = nullptr;
		while (current != nullptr)
		{
			next = current->next;
			current->next = previous;
			previous = current;
			current = next;
		}
		head = previous;
		return true;
	}
	void mergeLists(LinkList& otherlist)
	{
		Node<L>* current = head;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		Node<L>* current2 = otherlist.head;
		while (current2 != nullptr)
		{
			current->next = current2;
			current2 = current2->next;
			current = current->next;
		}
	}

	friend ostream& operator << (ostream& out, LinkList& list)
	{
		Node<L>* current = list.head;
		while (current != nullptr)
		{
			out << current->getData() << "  ";
			current = current->getNext();
		}
		
		return out;
	}
};

int main()
{
	LinkList <int> list(5);
	
	cout << list;

	cout << "\n\n___________\n\n";
	list.insertAtEnd(1);
	list.insertAtEnd(2);
	list.insertAtEnd(3);
	list.insertAtEnd(4);
	list.insertAtEnd(5);
	list.insertAtEnd(6);
	list.insertAtEnd(7);
	cout << list;
	cout << "\n\n___________\n\n";
	list.insertAtStart(8888);
	cout << list;
	cout << "\n\n___________\n\n";
	list.insertAfterValue(10, 5);
	cout << list;


	list.pop_back();
	cout << "\n\n___________\n\n";
	cout << list;

	list.pop_back();
	cout << "\n\n___________\n\n";
	cout << list;

	list.pop_back();
	cout << "\n\n___________\n\n";
	cout << list;

	list.reverseList();
	cout << "\n\n___________\n\n";
	cout << list; 



}
