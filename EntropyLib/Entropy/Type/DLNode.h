#pragma once

namespace Entropy
{
	template<class T>
	class DLNode
	{
	public:
		typedef DLNode<T> Node;

	private:
		T value;
		Node* next;
		Node* prev;

		DLNode() : value(), next(&NIL), prev(&NIL) {};

	public:
		static Node NIL;

		DLNode(const T& value) : value(value), next(&NIL), prev(&NIL) {};

		void prepend(Node& node);
		void append(Node& node);
		void remove();

		const T& getValue() const;
		const Node& getNext() const;
		const Node& getPrev() const;
	};

	template<class T>
	DLNode<T> DLNode<T>::NIL;

	template<class T>
	void DLNode<T>::prepend(Node& node)
	{
		node.next = this;
		if (prev != &NIL)
		{
			node.prev = prev;
			prev->next = node;
		}
		prev = &node;
	}

	template<class T>
	void DLNode<T>::append(Node& node)
	{
		node.prev = this;
		if (next != &NIL)
		{
			node.next = next;
			next->prev = node;
		}
		next = &node;
	}

	template<class T>
	void DLNode<T>::remove()
	{
		if (prev != &NIL)
			prev->next = next;
		if (next != &NIL)
			next->prev = prev;
	}

	template<class T>
	const T& DLNode<T>::getValue() const
	{
		return value;
	}

	template<class T>
	const DLNode<T>& DLNode<T>::getNext() const
	{
		return *next;
	}

	template<class T>
	const DLNode<T>& DLNode<T>::getPrev() const
	{
		return *prev;
	}
}
