#ifndef QUEUE_H
#define QUEUE_H

#include <cstddef>

template <typename T>
class Queue
{
	struct Node
	{
		T value;
		Node *Next;

		//Constructor
		Node(const T& v)
		{
			Next = NULL;
			value = v;
		}
	};
	Node *head, *tail;
	size_t s;

public:
	Queue()
	{
		head = NULL;
		tail = NULL;
		s = 0;
	}
	~Queue()
	{
		clear();
	}
	void clear()
	{
		while (!empty())
			leaveQueue();
	}
	void enterQueue(const T& value)
	{
		Node *new_node = new Node(value);

		if (empty())
		{
			head = tail = new_node;
		}
		else
		{
			tail->Next = new_node;
			tail = new_node;
		}
		++s;
	}
	void leaveQueue()
	{
		Node *oHead = head;

		if (head == tail)
		{
			head = tail = NULL;
		}
		else
		{
			head = head->Next;
		}
		delete oHead;
		--s;
	}
	T& front()
	{
		return head->value;
	}
	bool empty()
	{
		return s == 0;
	}
	size_t size()
	{
		return s;
	}
};

#endif