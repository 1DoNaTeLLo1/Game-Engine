#ifndef LIST_H
#define LIST_H

template <typename T> class List
{
public:
	List();
	~List();
	void Insert(T data);
	T Get(unsigned int index);
	unsigned int Size();

private:
	class Node
	{
	public:
		Node(T data, Node* next = nullptr);
		T GetData();
		void SetData(T data);
		Node* GetNext();
		void SetNext(Node* next);

	private:
		T data;
		Node* next;
	};

	Node* head;
};

template <typename T> List<T>::List()
{
	this->head = nullptr;
}

template <typename T> List<T>::~List()
{
	while (this->head != nullptr)
	{
		Node* next = this->head->GetNext();
		delete this->head;
		this->head = next;
	}
}

template <typename T> void List<T>::Insert(T data)
{
	Node* newNode = new Node(data);

	if (this->head == nullptr)
	{
		this->head = newNode;
		return;
	}

	Node* currentNode = this->head;
	while (currentNode->GetNext() != nullptr)
	{
		currentNode = currentNode->GetNext();
	}
	currentNode->SetNext(newNode);
}

template <typename T> T List<T>::Get(unsigned int index)
{
	Node* currentNode = this->head;
	for (unsigned int i = 0; i < index; i++)
	{
		currentNode = currentNode->GetNext();
	}
	return currentNode->GetData();
}

template <typename T> unsigned int List<T>::Size()
{
	Node* currentNode = head;
	unsigned int size = 0;
	while (currentNode != nullptr)
	{
		currentNode = currentNode->GetNext();
		size++;
	}
	return size;
}

template <typename T> List<T>::Node::Node(T data, Node* next)
{
	this->data = data;
	this->next = next;
}

template <typename T> T List<T>::Node::GetData()
{
	return this->data;
}

template <typename T> void List<T>::Node::SetData(T data)
{
	this->data = data;
}

template <typename T> typename List<T>::Node* List<T>::Node::GetNext()
{
	return this->next;
}

template <typename T> void List<T>::Node::SetNext(Node* next)
{
	this->next = next;
}

#endif