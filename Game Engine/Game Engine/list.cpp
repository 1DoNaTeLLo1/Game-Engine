#include "list.h"

template <typename T> List<T>::List()
{
	this->head = nullptr;
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
	while (currentNode->next != nullptr)
	{
		currentNode = currentNode->GetNext();
	}
	currentNode->SetNext(newNode);
}

template <typename T> T List<T>::Get(unsigned int index)
{
	Node* currentNode = this->head;
	for (unsigned int i = 0; i <= index; i++)
	{
		currentNode = currentNode->GetNext();
	}
	return currentNode->GetData();
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