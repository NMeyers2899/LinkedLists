#pragma once
template <typename T>
class Node
{
public:
	/// <summary>
	/// Creates a new node with no data.
	/// </summary>
	Node();

	/// <summary>
	/// Creates a new node with some value for its data.
	/// </summary>
	Node(T value);

	T data;

	/// <summary>
	/// This is the node that is next in the list ahead of this node.
	/// </summary>
	Node<T>* next;

	/// <summary>
	/// This is the node that is behind this node in the list.
	/// </summary>
	Node<T>* previous;
};

template<typename T>
inline Node<T>::Node()
{
	data = 0;
	next = nullptr;
	previous = nullptr;
}

template<typename T>
inline Node<T>::Node(T value)
{
	data = value;
	next = nullptr;
	previous = nullptr;
}
