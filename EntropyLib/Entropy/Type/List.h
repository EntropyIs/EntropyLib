#pragma once

#include "DLNode.h"

namespace Entropy {
	template<class T>
	class List
	{
	private:
		typedef DLNode<T> Node;

		Node* top;
		Node* last;
		int count;

	public:
		//typedef DLNodeItr<T> Iterator;

		List();
		~List();

		bool empty();
		int size();

		void push_front(const T& element);
		void push_back(const T& element);
		void remove(const T& element);

		const T& operator[](unsigned int index) const;

		//Iterator getIterator() const;
	};
	
	template<class T>
	inline List<T>::List()
	{
		top = &Node::NIL;
		last = &Node::NIL;
		count = 0;
	}
	
	template<class T>
	inline List<T>::~List()
	{
		while (top != &Node::NIL)
		{
			Node* temp = (Node*)&top->getNext();
			top->remove();
			delete top;
			top = temp;
		}
	}
	
	template<class T>
	inline bool List<T>::empty()
	{
		return top == &Node::NIL;
	}
	
	template<class T>
	inline int List<T>::size()
	{
		return count;
	}
	
	template<class T>
	inline void List<T>::push_front(const T& element)
	{
		Node* newElement = new newNode(element);
		if (top == &Node::NIL)
		{
			top = newElement;
			last = newElement;
		}
		else
		{
			top->prepend(*newElement);
			top = newElement;
		}
		count++;
	}
	
	template<class T>
	inline void List<T>::push_back(const T& element)
	{
		Node* newElement = new newNode(element);
		if (top == &Node::NIL)
		{
			top = newElement;
			last = newElement;
		}
		else
		{
			last->append(*newElement);
			last = newElement;
		}
		count++;
	}
	
	template<class T>
	inline void List<T>::remove(const T& element)
	{
		Node* node = top;

		while (node != &Node::NIL)
		{
			if (node->getValue() == element)
				break;
			node = (Node*)&node->getNext();
		}

		if (node != &Node::NIL)
		{
			if (node == top)
				top = (Node*)&node->getNext();
			if (node == last)
				last = (Node*)&node->getPrev();

			node->remove();
			delete node;
			count--;
		}
	}
	
	template<class T>
	inline const T& List<T>::operator[](unsigned int index) const
	{
		if (index < count)
		{
			Node* node = top;
			while (index)
			{
				index--;
				node = (Node*)&node->getNext();
			}
			return node->getValue();
		}
		else
			throw std::range_error("Index out of bounds");
	}
}