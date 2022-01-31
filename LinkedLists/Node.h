#pragma once
template <typename T>
class Node
{
public:
	Node();
	Node(T value);

	T data;
	Node<T>* next;
	Node<T>* previous;
};

/// <summary>
/// Creates a new node with no data.
/// </summary>
template<typename T>
inline Node<T>::Node()
{
	data = 0;
	next = nullptr;
	previous = nullptr;
}

/// <summary>
/// Creates a new node with some value for its data.
/// </summary>
template<typename T>
inline Node<T>::Node(T value)
{
	data = value;
	next = nullptr;
	previous = nullptr;
}
