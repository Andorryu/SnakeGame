#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
private:
	T m_entry;
	Node<T>* m_next;

public:
	Node(T entry)
	{
		m_entry = entry;
		m_next = nullptr;
	}
	void setEntry(T entry)
	{
		m_entry = entry;
	}
	T getEntry() const
	{
		return m_entry;
	}
	void setNext(Node<T>* next)
	{
		m_next = next;
	}
	Node<T>* getNext() const
	{
		return m_next;
	}
};

#endif