#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdexcept>
#include "ListInterface.h"

template <typename T>
class LinkedList : public ListInterface<T>
{
private:
	Node<T>* m_front;
	int m_length;
public:
	LinkedList()
	{
		m_front = nullptr;
		m_length = 0;
	}

	~LinkedList()
	{
	}
	void insert(T entry, int index = 0)
	{
		if (index < 0 || index > m_length) // index is out of bounds
		{
			throw(std::runtime_error("Index out of bounds"));
		}
		else
		{
			if (index == 0)
			{
				Node<T>* temp = new Node<T>(entry);
				temp->setNext(m_front);
				m_front = temp;
				m_length++;
			}
			else
			{
				Node<T>* prevNode = m_front;
				Node<T>* nextNode = m_front;
				Node<T>* temp = new Node<T>(entry);
				for (int i = 0; i < index; i++)
				{
					prevNode = nextNode;
					nextNode = nextNode->getNext();
				}
				prevNode->setNext(temp);
				temp->setNext(nextNode);
				m_length++;
			}
		}
	}
	void remove(int index)
	{
		if (index < 0 || index >= m_length)
		{
			throw(std::runtime_error("Index out of bounds or list is empty"));
		}
		else
		{
			if (index == 0)
			{
				Node<T>* temp = m_front;
				m_front = m_front->getNext();
				delete temp;
				m_length--;
			}
			else
			{
				Node<T>* prevNode = m_front;
				Node<T>* temp = m_front;
				for (int i = 0; i < index; i++)
				{
					prevNode = temp;
					temp = temp->getNext();
				}
				prevNode->setNext(temp->getNext());
				delete temp;
				m_length--;
			}
		}
	}
	T peek(int index) const
	{
		if (index < 0 || index >= m_length)
		{
			throw(std::runtime_error("Index is out of bounds or list is empty"));
		}
		else
		{
			if (index == 0)
			{
				return m_front->getEntry();
			}
			else
			{
				Node<T>* temp = m_front;
				for (int i = 0; i < index; i++)
				{
					temp = temp->getNext();
				}
				return temp->getEntry();
			}
		}
	}
	bool isEmpty() const
	{
		return m_front == NULL;
	}
	int getLength() const
	{
		return m_length;
	}
};

#endif