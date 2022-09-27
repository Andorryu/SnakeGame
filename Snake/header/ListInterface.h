#ifndef LIST_INTERFACE_H
#define LIST_INTERFACE_H

#include "Node.h"

template <typename T>
class ListInterface
{
private:
	Node<T>* m_front;
	int m_length;
public:
	virtual ~ListInterface() {}
	virtual void insert(T entry, int index = 0) = 0;
	virtual void remove(int index) = 0;
	virtual T peek(int index) const = 0;
	virtual bool isEmpty() const = 0;
	virtual int getLength() const = 0;
};

#endif