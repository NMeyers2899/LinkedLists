#pragma once
#include "Iterator.h"

template <typename T>
class List
{
public:
	List();
	List(const List<T>& other);
	~List();
	void destroy();
	Iterator<T> begin() const;
	Iterator<T> end() const;
	bool contains(const T& object) const;
	void pushFront(const T& value);
	void pushBack(const T& value);
	bool insert(const T& value, int index);
	bool remove(const T& value);
	void print() const;
	void initialize();
	bool isEmpty() const;
	bool getData(Iterator<T>& iter, int index);
	int getLength() const;
	List<T>& operator=(const List<T>& otherList) const;
	void sort();

private:
	Node<T>* m_first;
	Node<T>* m_last;
	int m_nodeCount;
};

/// <summary>
/// Creates a new list with zero elements inside.
/// </summary>
template<typename T>
inline List<T>::List()
{
	m_first = nullptr;
	m_last = nullptr;
	m_nodeCount = 0;
}

/// <summary>
/// Creates a new list using the same elements from another list.
/// </summary>
template<typename T>
inline List<T>::List(const List<T>& other)
{
	initialize();
	m_first = other.m_first;
	m_last = other.m_last;
	m_nodeCount = other.m_nodeCount;
}

/// <summary>
/// On deletion, calls the list's destroy function.
/// </summary>
template<typename T>
inline List<T>::~List()
{
	destroy();
}

/// <summary>
/// Deletes all elements of the list.
/// </summary>
template<typename T>
inline void List<T>::destroy()
{
	Node<T>* currentNode = m_first;
	Node<T>* nextNode;
	for (int i = 0; i < m_nodeCount; i++) {
		nextNode = currentNode->next;
		delete currentNode;
		currentNode = nextNode;
	}

	initialize();
}

/// <summary>
/// Creates a new iterator that points to the first node in the list.
/// </summary>
template<typename T>
inline Iterator<T> List<T>::begin() const
{
	return Iterator<T>(m_first);
}

/// <summary>
/// Creates a new iterator that points to the last node in the list.
/// </summary>
template<typename T>
inline Iterator<T> List<T>::end() const
{
	return Iterator<T>(m_last);
}

/// <summary>
/// Returns whether or not a specific item could be found in the list.
/// </summary>
template<typename T>
inline bool List<T>::contains(const T& object) const
{
	bool itemFound = false;
	for (Iterator<T> iter = begin(); iter.operator* != nullptr; iter++) {
		if (iter.operator* == object) {
			itemFound = true;
			return itemFound;
		}
	}

	return itemFound;
}

/// <summary>
/// Adds a node to the front of the list.
/// </summary>
template<typename T>
inline void List<T>::pushFront(const T& value)
{
	// Creates a new node that will go in front of the list.
	Node<T>* newFirst = new Node<T>(value);
	// Changes the next of the new first to m_first.
	newFirst->next = m_first;
	// Changes m_first to the new first.
	m_first = newFirst;
	// Changes the original m_first's previous to the new first.
	newFirst->next->previous = newFirst;

	m_nodeCount++;
}

/// <summary>
/// Adds a new node to the end of the list.
/// </summary>
template<typename T>
inline void List<T>::pushBack(const T& value)
{
	// Creates a new node that will go at the end of the list.
	Node<T>* newLast = new Node<T>(value);
	// Changes the previous of the new last to m_last.
	newLast->previous = m_last;
	// Changes m_last to the new last.
	m_last = newLast;
	// Changes the original m_last's next to the new last.
	newLast->previous->next = newLast;

	m_nodeCount++;
}

/// <summary>
/// Inserts a given node into the given index if that index is valid.
/// </summary>
template<typename T>
inline bool List<T>::insert(const T& value, int index)
{
	bool nodeInserted = false;
	Node<T>* newNode = new Node<T>(value);
	Node<T>* currentNode = m_first;
	// If the index is not within the current length...
	if (index >= getLength())
		// ...it returns false.
		return nodeInserted;

	if (index == 0)
		pushFront;

	// Iterates through the list of node until it reaches the specified index.
	for (int i = 0; i < index; i++)
		currentNode = currentNode->next;
		
	// Insert the new node into the space where the current node was.
	newNode->next = currentNode;
	newNode->previous = currentNode->previous;
	currentNode->previous->next = newNode;
	currentNode->previous = newNode;

	m_nodeCount++;
	return nodeInserted;
}

template<typename T>
inline bool List<T>::remove(const T& value)
{
	bool objectRemoved = false;
	Node<T>* nodeToRemove = m_first;
	for (Iterator<T> iter = begin(); iter != nullptr; iter++) {
		if (iter.operator* == value) {
			nodeToRemove->next->previous = nodeToRemove->previous;
			nodeToRemove->previous->next = nodeToRemove->next;
			delete nodeToRemove;
			break;
		}
		nodeToRemove = nodeToRemove->next;
	}

	return objectRemoved;
}

/// <summary>
/// Prints each element in the linked list.
/// </summary>
template<typename T>
inline void List<T>::print() const
{
	for (Iterator<T> iter = begin(); iter != nullptr; iter++)
		std::cout << iter.operator* << std::endl;
}

/// <summary>
/// Sets the first and last node to nothing.
/// </summary>
template<typename T>
inline void List<T>::initialize()
{
	m_first = new Node<T>();
	m_last = new Node<T>();
	m_nodeCount = 2;
	m_first->next = m_last;
	m_last->previous = m_first;
}

/// <summary>
/// Finds wether or not the list has any elements.
/// </summary>
template<typename T>
inline bool List<T>::isEmpty() const
{
	return (begin() == nullptr && end() == nullptr && m_nodeCount == 0);
}

/// <summary>
/// Finds the data at a certain index in the list.
/// </summary>
template<typename T>
inline bool List<T>::getData(Iterator<T>& iter, int index)
{
	return false;
}

/// <summary>
/// Finds the number of nodes in the list.
/// </summary>
template<typename T>
inline int List<T>::getLength() const
{
	return m_nodeCount;
}

template<typename T>
inline List<T>& List<T>::operator=(const List<T>& otherList) const
{
	// TODO: insert return statement here
}

template<typename T>
inline void List<T>::sort()
{
}
