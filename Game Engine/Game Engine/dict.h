#ifndef DICT_H
#define DICT_H

template<typename T, typename U> class Dict
{
public:
	Dict();
	~Dict();
	int Size();
	void Insert(T key, U data);
	void Remove(T key);
	U Get(T key);
	U Get(int index);

private:
	class Node
	{
	public:
		Node(T key, U data, Node* next = nullptr);
		void SetKey(T key);
		T GetKey();
		void SetData(U data);
		U GetData();
		void SetNext(Node* next);
		Node* GetNext();

	private:
		T key;
		U data;
		Node* next;
	};

	Node* head;
};

template<typename T, typename U> Dict<T, U>::Dict()
{
	this->head = nullptr;
}

template<typename T, typename U> Dict<T, U>::~Dict()
{
	while (this->head != nullptr)
	{
		Node* top = this->head;
		this->head = this->head->GetNext();
		delete top;
	}
}

template<typename T, typename U> int Dict<T, U>::Size()
{
	Node* current = this->head;
	int size = 0;

	while (current != nullptr)
	{
		current = current->GetNext();
		size++;
	}

	return size;
}

template<typename T, typename U> void Dict<T, U>::Insert(T key, U data)
{
	Node* newNode = new Node(key, data);

	if (this->head == nullptr)
	{
		this->head = newNode;
		return;
	}

	newNode->SetNext(this->head);
	this->head = newNode;
}

template<typename T, typename U> void Dict<T, U>::Remove(T key)
{
	for (Node* current = head, Node* prev = nullptr; current != nullptr; prev = current, current = current->GetNext())
	{
		if (current->Get(Key) == key)
		{
			prev->SetNext(current->GetNext());
			delete current;
			return;
		}
	}

	std::cerr << "Error! Dictionary has not this key value!" << std::endl;
	exit(-1);
}

template<typename T, typename U> U Dict<T, U>::Get(T key)
{
	for (Node* current = head; current != nullptr; current = current->GetNext())
	{
		if (current->Get(Key) == key)
		{
			return current->GetData();
		}
	}

	std::cerr << "Error! Dictionary has not this key value!" << std::endl;
	exit(-1);
}

template<typename T, typename U> U Dict<T, U>::Get(int index)
{
	for (int i = 0, Node* current = this->head; i < index; i++, current = current.GetNext());

	if (current == nullptr)
	{
		std::cerr << "Error! Dictionary is out of bound!" << std::endl;
		exit(-1);
	}

	return current.GetData();
}

template<typename T, typename U> Dict<T, U>::Node::Node(T key, U data, Node* next)
{
	this->key = key;
	this->data = data;
	this->next = next;
}

template<typename T, typename U> void Dict<T, U>::Node::SetKey(T key)
{
	this->key = key;
}

template<typename T, typename U> T Dict<T, U>::Node::GetKey()
{
	return this->key;
}

template<typename T, typename U> void Dict<T, U>::Node::SetData(U data)
{
	this->data = data;
}

template<typename T, typename U> U Dict<T, U>::Node::GetData()
{
	return this->data;
}

template<typename T, typename U> void Dict<T, U>::Node::SetNext(Node* next)
{
	this->next = next;
}

template<typename T, typename U> Dict<T, U>::Node* Dict<T, U>::Node::GetNext()
{
	return this->next;
}

#endif